/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "GraphicsGame.hpp"
#include "Floor.hpp"
#include "Assets3DHandler.hpp"
#include "IBomberman.hpp"
#include "Button.hpp"

GraphicsGame::GraphicsGame(Graphics *graph, Settings *settings, Game *game, SoundMachine *soundMachine, HandleInput *input)
{
	this->graph = graph;
	this->settings = settings;
	this->game = game;
	this->soundMachine = soundMachine;
	this->input = input;
	this->createAll();
}

GraphicsGame::~GraphicsGame()
{
}

void	GraphicsGame::createAll()
{
	this->createFloor();
	this->createPlayer();
	this->createWall();
	this->soundMachine->playSound(SoundMachine::GAME_MUSIC);
	this->pauseBackgroundId = this->graph->getAsset2DHandler()->create2DAsset(Graphics::PAUSE_BACKGROUND, 0, 0);
	this->pauseTitleId = this->graph->getAsset2DHandler()->create2DAsset(Graphics::PAUSE_TITLE,
									     this->graph->getScreenWidth() / 2 - (this->graph->getTextureByType(Graphics::PAUSE_TITLE)->getSize().Width / 2),
									     this->graph->getScreenHeight() / 2 - 200 - (this->graph->getTextureByType(Graphics::PAUSE_TITLE)->getSize().Height / 2));
	this->winnerTitleId = this->graph->getAsset2DHandler()->create2DAsset(Graphics::WINNER_TITLE,
										 this->graph->getScreenWidth() / 2 - (this->graph->getTextureByType(Graphics::WINNER_TITLE)->getSize().Width / 2),
										 this->graph->getScreenHeight() / 2);
	this->saveButton = new Button(this->graph->getAsset2DHandler()->create2DAsset(Graphics::BUTTON_SAVE_DEF, this->graph->getScreenWidth() / 2 - 100 - (this->graph->getTextureByType(Graphics::BUTTON_SAVE_DEF)->getSize().Width), this->graph->getScreenHeight() / 2), Graphics::BUTTON_SAVE_DEF, Graphics::BUTTON_SAVE_PRESSED, this->input, false, this->graph, sceneChanging::NONE, this->soundMachine);
	this->loadButton = new Button(this->graph->getAsset2DHandler()->create2DAsset(Graphics::BUTTON_LOAD_DEF, this->graph->getScreenWidth() / 2 + 100, this->graph->getScreenHeight() / 2), Graphics::BUTTON_LOAD_DEF, Graphics::BUTTON_LOAD_PRESSED, this->input, false, this->graph, sceneChanging::NONE, this->soundMachine);
}

void	GraphicsGame::display()
{
	this->displayObject();
}

void	GraphicsGame::displayPause()
{
	this->graph->drawAll();
	this->graph->getAsset2DHandler()->displayById(this->pauseBackgroundId);
	this->graph->getAsset2DHandler()->displayById(this->pauseTitleId);
	this->graph->getAsset2DHandler()->displayById(this->saveButton->getId());
	this->graph->getAsset2DHandler()->displayById(this->loadButton->getId());
	if (this->saveButton->execStateAction())
		this->game->saveGame();
	if (this->loadButton->execStateAction())
		this->game->loadGame();
}

void	GraphicsGame::setGame(Game *game)
{
	this->game = game;
}

void	GraphicsGame::destroyAll()
{
	this->destroyAllParticles();
	this->playerInList.clear();
	this->bombInList.clear();
	this->fireInList.clear();
	this->boxInList.clear();
	this->bonusInList.clear();
	this->idWallList.clear();
	this->idFloorList.clear();
	delete this->saveButton;
	delete this->loadButton;
}

void	GraphicsGame::createWall()
{
	std::vector<Wall>		list = this->game->getMap().getWalls();
	std::vector<Wall>::iterator	it;
	irr::core::vector3df		pos;
	BoxPosModel			*box;

	for (it = list.begin(); it != list.end(); ++it)
	{
		pos = (*it).getPos();
		pos.X = pos.X * UNIT_MODEL;
		pos.Y = pos.Y * UNIT_MODEL;
		pos.Z = pos.Z * UNIT_MODEL;
		if ((*it).isBreakable()) {
			box = new BoxPosModel();
			box->idModel = this->graph->getAsset3DHandler()->createMeshModel3D(Graphics::BOX, pos);
			box->idBox = (*it).getId();
			this->boxInList.push_back(box);
		} else {
			this->idWallList.push_back(
				this->graph->getAsset3DHandler()->createMeshModel3D(Graphics::WALL, pos));
		}
	}
}

void	GraphicsGame::createWin()
{
	irr::core::vector3df	pos(300, 300, 200);
	irr::core::vector3df	rot(45, 0, 0);
	unsigned		id;

	id = this->playerInList.front()->idModel;
	this->graph->getAsset3DHandler()->setPositionbyId(pos, id);
	this->graph->getAsset3DHandler()->setRotationbyId(rot, id);
	this->graph->getAsset3DHandler()->changeAnimationById(id, animation::WALK);
}

void	GraphicsGame::createFloor()
{
	std::vector<Floor>		list = this->game->getMap().getFloors();
	std::vector<Floor>::iterator	it;
	irr::core::vector3df		pos;
	unsigned			id;
	unsigned			index = 0;

	for (it = list.begin(); it != list.end(); ++it)
	{
		pos = (*it).getPos();
		pos.X = pos.X * UNIT_MODEL;
		pos.Y = -UNIT_MODEL;
		pos.Z = pos.Z * UNIT_MODEL;
		id = this->graph->getAsset3DHandler()->createMeshModel3D(Graphics::FLOOR, pos);
		this->idFloorList.push_back(id);
		if (index % 2)
			this->graph->getAsset3DHandler()->changeTexture(id, Graphics::GROUND2_T);
		index++;
	}
	pos = irr::core::vector3df(6.5 * UNIT_MODEL, -UNIT_MODEL - 1, 6.5 * UNIT_MODEL);
	id = this->graph->getAsset3DHandler()->createMeshModel3D(Graphics::FLOOR2, pos);
}

bool	GraphicsGame::bombExist(unsigned id)
{
	std::list<BombPosModel *>::iterator	it;

	for (it = this->bombInList.begin(); it != this->bombInList.end(); ++it)
	{
		if ((*it)->idBomb == id)
			return (true);
	}
	return (false);
}

bool	GraphicsGame::fireExist(unsigned id)
{
	std::list<FirePosModel *>::iterator	it;

	for (it = this->fireInList.begin(); it != this->fireInList.end(); ++it)
	{
		if ((*it)->id == id)
			return (true);
	}
	return (false);
}

bool	GraphicsGame::bonusExist(unsigned id)
{
	std::list<BonusPosModel *>::iterator	it;

	for (it = this->bonusInList.begin(); it != this->bonusInList.end(); ++it)
	{
		if ((*it)->id == id)
			return (true);
	}
	return (false);
}

void	GraphicsGame::createBomb()
{
	std::vector<Bomb>		list = this->game->getMap().getBombs();
	std::vector<Bomb>::iterator	it;
	irr::core::vector3df		pos;
	BombPosModel			*bomb;

	for (it = list.begin(); it != list.end(); ++it)
	{
		if (!this->bombExist((*it).getId()))
		{
			pos = (*it).getPos();
			pos.X = pos.X * UNIT_MODEL - 20;
			pos.Y = pos.Y * UNIT_MODEL;
			pos.Z = pos.Z * UNIT_MODEL - 20;
			bomb = new BombPosModel();
			bomb->idBomb = (*it).getId();
			bomb->idModel = this->graph->getAsset3DHandler()->createMeshModel3D(Graphics::BOMB, pos);
			this->bombInList.push_back(bomb);
		}
	}
}

void	GraphicsGame::createPlayer()
{
	std::vector<Bomberman>			list = this->game->getMap().getPlayers();
	std::vector<Bomberman>::iterator	it;
	irr::core::vector3df			pos;
	PlayerPosModel				*player;

	for (it = list.begin(); it != list.end(); ++it)
	{
		player = new PlayerPosModel();
		pos = (*it).getPos();
		pos.X = pos.X * UNIT_MODEL - 20;
		pos.Y = pos.Y * UNIT_MODEL;
		pos.Z = pos.Z * UNIT_MODEL - 20;
		player->idPlayer = (*it).getId();
		player->idModel = this->graph->getAsset3DHandler()->createMeshModel3D((*it).getType(), pos);
		this->playerInList.push_back(player);
	}
}

void	GraphicsGame::changeAnimPlayer(Bomberman bomberman, PlayerPosModel *player)
{
	irr::core::vector3df	pos;
	irr::core::vector3df	rot;

	pos = bomberman.getPos();
	pos.X = pos.X * UNIT_MODEL - 20;
	pos.Y = pos.Y * UNIT_MODEL;
	pos.Z = pos.Z * UNIT_MODEL - 20;
	switch (bomberman.getDir())
	{
		case (dir_e::UP):
			rot = irr::core::vector3df(0, 180, 0);
			break;
		case (dir_e::LEFT):
			rot = irr::core::vector3df(0, 90, 0);
			break;
		case (dir_e::RIGHT):
			rot = irr::core::vector3df(0, 270, 0);
			break;
		default:
			rot = irr::core::vector3df(0, 0, 0);
			break;
	}
	this->graph->getAsset3DHandler()->setPositionbyId(pos, player->idModel);
	this->graph->getAsset3DHandler()->setRotationbyId(rot, player->idModel);
	this->graph->getAsset3DHandler()->changeAnimationById(player->idModel, bomberman.getState());
}

void	GraphicsGame::updatePlayer()
{
	std::vector<Bomberman>				list = this->game->getMap().getPlayers();
	std::vector<Bomberman>::iterator		it;
	std::list<PlayerPosModel *>::iterator		itSelf;
	bool						checkPlayer;

	for (itSelf = this->playerInList.begin(); itSelf != this->playerInList.end(); ++itSelf) {
		checkPlayer = false;
		for (it = list.begin(); it != list.end(); ++it) {
			if ((*it).getId() == (*itSelf)->idPlayer) {
				this->changeAnimPlayer((*it), (*itSelf));
				checkPlayer = true;
			}
		}
		if (!checkPlayer) {
			this->graph->getAsset3DHandler()->destroyById(((*itSelf)->idModel));
			itSelf = this->playerInList.erase(itSelf);
			if (this->playerInList.size() > 1)
				this->soundMachine->playSound(SoundMachine::DYING);
		}
	}
}

void	GraphicsGame::updateFire()
{
	std::vector<Fire>			list = this->game->getMap().getFire();
	std::vector<Fire>::iterator		it;
	std::list<FirePosModel *>::iterator	itSelf;
	bool					checkFire;

	for (itSelf = this->fireInList.begin(); itSelf != this->fireInList.end(); ++itSelf) {
		checkFire = false;
		for (it = list.begin(); it != list.end(); ++it) {
				if ((*it).getId() == (*itSelf)->id) {
					checkFire = true;
				}
		}
		if (!checkFire) {
			(*itSelf)->particleSystem->setEmitter(0);
			itSelf = this->fireInList.erase(itSelf);
		}
	}
}

void	GraphicsGame::updateBonus()
{
	std::vector<Bonus>			list = this->game->getMap().getBonus();
	std::vector<Bonus>::iterator		it;
	std::list<BonusPosModel *>::iterator	itSelf;
	bool					checkBonus;

	for (itSelf = this->bonusInList.begin(); itSelf != this->bonusInList.end(); ++itSelf) {
		checkBonus = false;
		for (it = list.begin(); it != list.end(); ++it) {
			if ((*it).getId() == (*itSelf)->id) {
				checkBonus = true;
			}
		}
		if (!checkBonus) {
			(*itSelf)->particleSystem->setEmitter(0);
			itSelf = this->bonusInList.erase(itSelf);
		}
	}
}

void	GraphicsGame::updateBomb()
{
	std::vector<Bomb>			list = this->game->getMap().getBombs();
	std::vector<Bomb>::iterator		it;
	std::list<BombPosModel *>::iterator	itSelf;
	bool					checkBomb;

	for (itSelf = this->bombInList.begin(); itSelf != this->bombInList.end(); ++itSelf) {
		checkBomb = false;
		for (it = list.begin(); it != list.end(); ++it) {
			if ((*it).getId() == (*itSelf)->idBomb) {
				checkBomb = true;
			}
		}
		if (!checkBomb) {
			this->graph->getAsset3DHandler()->destroyById(((*itSelf)->idModel));
			itSelf = this->bombInList.erase(itSelf);
		}
	}
}

void	GraphicsGame::createFire()
{
	irr::scene::IParticleEmitter*	emitter;
	std::vector<Fire>		list = this->game->getMap().getFire();
	std::vector<Fire>::iterator	it;
	irr::core::vector3df		pos;
	FirePosModel			*fire;

	for (it = list.begin(); it != list.end(); ++it)
	{
		if (!this->fireExist((*it).getId())) {
			fire = new FirePosModel();
			fire->particleSystem = this->graph->createParticleSystem(false);
			fire->id = (*it).getId();
			pos = (*it).getPos();
			pos.X = pos.X * UNIT_MODEL - 17;
			pos.Z = pos.Z * UNIT_MODEL - 17;
			emitter = fire->particleSystem->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(pos.X - 3, 0, pos.Z - 3, pos.X + 3, 1, pos.Z + 3),
				irr::core::vector3df(0.0f, 0.02f, 0.0f),
				100,
				120,
				irr::video::SColor(0, 255, 255, 255),
				irr::video::SColor(0, 255, 255, 255),
				600, 1200,
				50,
				irr::core::dimension2df(15.0f, 15.0f),
				irr::core::dimension2df(20.0f, 20.0f));
			fire->particleSystem->setEmitter(emitter);
			emitter->drop();
			fire->particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			fire->particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			fire->particleSystem->setMaterialTexture(0, this->graph->getTextureByType(Graphics::FIRE_T));
			fire->particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
			this->fireInList.push_back(fire);
		}
	}
}

void	GraphicsGame::createBonus()
{
	irr::scene::IParticleEmitter*	emitter;
	std::vector<Bonus>		list = this->game->getMap().getBonus();
	std::vector<Bonus>::iterator	it;
	irr::core::vector3df		pos;
	BonusPosModel			*bonus;

	for (it = list.begin(); it != list.end(); ++it)
	{
		if (!this->bonusExist((*it).getId())) {
			bonus = new BonusPosModel();
			bonus->particleSystem = this->graph->createParticleSystem(false);
			bonus->id = (*it).getId();
			pos = (*it).getPos();
			pos.X = pos.X * UNIT_MODEL - 17;
			pos.Z = pos.Z * UNIT_MODEL - 17;
			emitter = bonus->particleSystem->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(pos.X - 3, 0, pos.Z - 3, pos.X + 3, 1, pos.Z + 3),
				irr::core::vector3df(0.0f, 0.02f, 0.0f),
				100,
				120,
				irr::video::SColor(0, 255, 255, 255),
				irr::video::SColor(0, 255, 255, 255),
				600, 1200,
				50,
				irr::core::dimension2df(15.0f, 15.0f),
				irr::core::dimension2df(20.0f, 20.0f));
			bonus->particleSystem->setEmitter(emitter);
			emitter->drop();
			bonus->particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			bonus->particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			switch ((*it).getType()) {
				case (type_e::BOMB_UP):
					bonus->particleSystem->setMaterialTexture(0, this->graph->getTextureByType(Graphics::BONUS_T));
					break;
				case (type_e::SPEED_UP):
					bonus->particleSystem->setMaterialTexture(0, this->graph->getTextureByType(Graphics::BONUS2_T));
					break;
				case (type_e::FIRE_UP):
					bonus->particleSystem->setMaterialTexture(0, this->graph->getTextureByType(Graphics::BONUS3_T));
					break;
				case (type_e::WALL_PASS):
					bonus->particleSystem->setMaterialTexture(0, this->graph->getTextureByType(Graphics::BONUS4_T));
					break;
			}
			bonus->particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
			this->bonusInList.push_back(bonus);
		}
	}
}

void	GraphicsGame::destroyAllParticles()
{
	std::list<BonusPosModel *>::iterator	itBonus;
	std::list<FirePosModel *>::iterator	itFire;

	for (itBonus = this->bonusInList.begin(); itBonus != this->bonusInList.end(); ++itBonus) {
		(*itBonus)->particleSystem->setEmitter(0);
	}
	this->bonusInList.clear();
	for (itFire = this->fireInList.begin(); itFire != this->fireInList.end(); ++itFire) {
		(*itFire)->particleSystem->setEmitter(0);
	}
	this->fireInList.clear();
}

void	GraphicsGame::updateBox()
{
	std::vector<Wall>			list = this->game->getMap().getWalls();
	std::vector<Wall>::iterator		it;
	std::list<BoxPosModel *>::iterator	itSelf;
	bool					checkBox;

	for (itSelf = this->boxInList.begin(); itSelf != this->boxInList.end(); ++itSelf) {
		checkBox = false;
		for (it = list.begin(); it != list.end(); ++it) {
			if ((*it).getId() == (*itSelf)->idBox) {
				checkBox = true;
			}
		}
		if (!checkBox) {
			this->graph->getAsset3DHandler()->destroyById(((*itSelf)->idModel));
			itSelf = this->boxInList.erase(itSelf);
		}
	}
}

void	GraphicsGame::displayObject()
{
	this->updatePlayer();
	this->createBomb();
	this->updateBomb();
	this->createFire();
	this->updateFire();
	this->updateBox();
	this->createBonus();
	this->updateBonus();
	this->graph->drawAll();
}

Graphics*	GraphicsGame::getGraphics() const
{
	return (this->graph);
}

Settings*	GraphicsGame::getSetting() const
{
	return (this->settings);
}

unsigned	GraphicsGame::getWinnerTitleId()
{
	return (this->winnerTitleId);
}
