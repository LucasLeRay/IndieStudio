/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Button by Lucas Le Ray
*/

#include "Button.hpp"
#include "GraphicsMenu.hpp"

Button::Button(unsigned assetId, Graphics::typeTexture texture, Graphics::typeTexture textureFocus, HandleInput *inputs, bool decal_focus, Graphics *graph, sceneChanging scene, SoundMachine *soundMachine)
{
	this->assetId = assetId;
	this->textureFocus = textureFocus;
	this->texture = texture;
	this->inputs = inputs;
	this->focus = false;
	this->decalFocus = decal_focus;
	this->graph = graph;
	this->scene = scene;
	this->soundMachine = soundMachine;
}

Button::~Button()
{
	this->graph->getAsset2DHandler()->destroy2DAsset(this->assetId);
}

HandleInput::MouseStateOnAsset2D	Button::getState(void)
{
	HandleInput::MouseStateOnAsset2D state = this->inputs->getMouseStateOnAsset2D(this->graph->getAsset2DHandler()->getAsset2DById(this->assetId));
	return (state);
}

bool	Button::execStateAction(void)
{
	HandleInput::MouseStateOnAsset2D	state = this->getState();

	if (state == HandleInput::FOCUS && !this->focus) {
		this->soundMachine->playSound(SoundMachine::typeSound::SELECT_1);
		if (this->decalFocus)
			this->graph->getAsset2DHandler()->modify2DAsset(this->textureFocus, this->assetId, (SCREEN_WIDTH) - this->graph->getTextureByType(this->texture)->getSize().Width + 100, -1);
		else
			this->graph->getAsset2DHandler()->modify2DAsset(this->textureFocus, this->assetId);
		this->focus = true;
	}
	if (state == HandleInput::NONE && this->focus) {
		if (this->decalFocus)
			this->graph->getAsset2DHandler()->modify2DAsset(this->texture, this->assetId, (SCREEN_WIDTH) - this->graph->getTextureByType(this->texture)->getSize().Width + 200, -1);
		else
			this->graph->getAsset2DHandler()->modify2DAsset(this->texture, this->assetId);
		this->focus = false;
	}
	if (state == HandleInput::CLICK)
		return (true);
	return (false);
}

unsigned	Button::getId()
{
	return (this->assetId);
}