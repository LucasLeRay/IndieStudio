/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** created by Lucas Le Ray
*/

#include "PlayerSelect.hpp"
#include "Assets3DHandler.hpp"

PlayerSelect::PlayerSelect(int pos, Graphics *graph, HandleInput *inputs)
{
	this->pos = pos;
	this->graph = graph;
	this->inputs = inputs;
	this->playerType = this->pos < 2 ? (PlayerType)(PlayerSelect::J1 + this->pos) : PlayerSelect::IA;
	this->modelChoosing = (unsigned)this->pos;
	this->createAssets();
}

PlayerSelect::~PlayerSelect() {}

void PlayerSelect::createAssetBackground()
{
	Graphics::typeTexture	texture;

	switch (this->playerType)
	{
		case IA:
			texture = Graphics::PLAYER_NAME_ORDI;
			break;
		case NO_PLAYER:
			texture = Graphics::PLAYER_NAME_SANS;
			break;
		default:
			texture = Graphics::PLAYER_NAME_JOUEUR;
			break;
	}
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(
		(Graphics::typeTexture)(texture),
		SELECT_POS_X,
		SELECT_POS_Y - this->graph->getTextureByType(Graphics::PLAYER_NAME_ORDI)->getSize().Height));
	if (this->playerType != NO_PLAYER)
		this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(
		(Graphics::typeTexture)(Graphics::typeTexture::PLAYER_BACK1 + this->pos),
		SELECT_POS_X,
		SELECT_POS_Y));
}

void PlayerSelect::createAssetInput()
{
	Graphics::typeTexture	texture;

	switch (this->playerType)
	{
		case J1:
			texture = Graphics::INPUT_ZQSD;
			break;
		case J2:
			texture = Graphics::INPUT_OKLM;
			break;
		case J3:
			texture = Graphics::INPUT_CONTROLLER1;
			break;
		case J4:
			texture = Graphics::INPUT_CONTROLLER2;
			break;
		default:
			return;
	}
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(
		(Graphics::typeTexture)(texture),
		SELECT_POS_X,
		SELECT_POS_Y + this->graph->getTextureByType(Graphics::PLAYER_BACK1)->getSize().Height));
}

void PlayerSelect::createAssetPlayer()
{
	if (this->playerType != NO_PLAYER)
		this->modelChara = this->graph->getAsset3DHandler()->createMeshModel3D(
		(Graphics::typeObj)this->pos,
		this->graph->getAsset3DHandler()->getBasicMenuPosbyId(this->pos),
		this->graph->getAsset3DHandler()->getBasicMenuRotbyId(this->pos));
}

void PlayerSelect::createAssetButtons()
{
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(
		Graphics::SELECT_LEFT,
		SELECT_POS_X + 10,
		SELECT_POS_Y - this->graph->getTextureByType(Graphics::PLAYER_NAME_ORDI)->getSize().Height + 10));
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(
		Graphics::SELECT_RIGHT,
		SELECT_POS_X + this->graph->getTextureByType(Graphics::PLAYER_NAME_ORDI)->getSize().Width -
		this->graph->getTextureByType(Graphics::SELECT_LEFT)->getSize().Width - 10,
		SELECT_POS_Y - this->graph->getTextureByType(Graphics::PLAYER_NAME_ORDI)->getSize().Height + 10));
}

void PlayerSelect::createAssets()
{
	if (this->modelChara != -1 && this->playerType == NO_PLAYER)
	{
		this->graph->getAsset3DHandler()->destroyById(this->modelChara);
		this->modelChara = -1;
	}
	this->createAssetBackground();
	if (this->modelChara == -1)
		this->createAssetPlayer();
	this->createAssetInput();
	this->createAssetButtons();
}

void PlayerSelect::deleteAssetList()
{
	std::list<unsigned>::iterator it;

	for (it = this->asset2DIdList.begin(); it != this->asset2DIdList.end(); ++it)
	{
		this->graph->getAsset2DHandler()->destroy2DAsset((*it));
		it = this->asset2DIdList.erase(it);
	}
	for (it = this->asset2DIdList.begin(); it != this->asset2DIdList.end(); ++it)
	{
		this->graph->getAsset2DHandler()->destroy2DAsset((*it));
		it = this->asset2DIdList.erase(it);
	}
	this->asset2DIdList.clear();
}

bool PlayerSelect::changeParam(unsigned id)
{
	Asset2D                 *asset = this->graph->getAsset2DHandler()->getAsset2DById(id);

	switch (asset->type)
	{
		case (Graphics::SELECT_LEFT):
			this->playerType = this->playerType == IA ? (PlayerType)(J1 + this->pos) : this->playerType == NO_PLAYER ? IA : NO_PLAYER;
			return (true);
		case (Graphics::SELECT_RIGHT):
			this->playerType = this->playerType == IA ? NO_PLAYER : this->playerType == NO_PLAYER ? (PlayerType)(J1 + this->pos) : IA;
			return (true);
	}
	if (asset->type == (Graphics::typeTexture)(Graphics::typeTexture::PLAYER_BACK1 + this->pos))
	{
		this->modelChoosing = this->modelChoosing == Graphics::SNAKE ? 0 : this->modelChoosing + 1;
		this->graph->getAsset3DHandler()->modifyMesh((Graphics::typeObj)(this->modelChoosing), this->modelChara);
	}
	return (false);
}

void PlayerSelect::deleteModel()
{
	this->graph->getAsset3DHandler()->destroyById(this->modelChara);
	this->asset2DIdList.clear();
}

void PlayerSelect::handleEvent()
{
	std::list<unsigned>::iterator           it;
	HandleInput::MouseStateOnAsset2D        state;
	Graphics::typeTexture                   texture;

	for (it = this->asset2DIdList.begin(); it != this->asset2DIdList.end(); ++it)
	{
		texture = this->graph->getAsset2DHandler()->getAsset2DById((*it))->type;
		if (texture != Graphics::PLAYER_NAME_JOUEUR && texture != Graphics::PLAYER_NAME_ORDI && texture != Graphics::PLAYER_NAME_SANS)
		{
			state = this->inputs->getMouseStateOnAsset2D(
				this->graph->getAsset2DHandler()->getAsset2DById((*it)));
			if (state == HandleInput::CLICK && this->changeParam((*it)))
			{
				this->deleteAssetList();
				this->createAssets();
				return;
			}
		}
	}
}

PlayerSelect::PlayerType PlayerSelect::getPlayerType()
{
	return (this->playerType);
}

unsigned PlayerSelect::getModelChoosing()
{
	return (this->modelChoosing);
}