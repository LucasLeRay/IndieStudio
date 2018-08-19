/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "Launcher.hpp"
#include "Settings.hpp"
#include "SoundMachine.hpp"
#include "Graphics.hpp"
#include "Game.hpp"
#include "GraphicsGame.hpp"
#include "GraphicsMenu.hpp"

Launcher::Launcher()
{
	this->settings = new Settings;
	this->soundMachine = new SoundMachine;
	this->input = new HandleInput();
	this->graphics = new Graphics(input);
	this->input->setGraphics(this->graphics);
	this->game = nullptr;
	this->relief = 0;
	this->toggleInput["space"] = false;
	this->toggleInput["esc"] = false;
	this->pause = false;
	this->sceneDisplay = NO_DISPLAY;
}

void Launcher::changeRelief()
{
	this->relief++;
	switch (this->relief % 3) {
		case (0):
			this->graphics->addCamera(irr::core::vector3df(300, 500, 120), irr::core::vector3df(300, 0, 250));
			break;
		case (1):
			this->graphics->addCamera(irr::core::vector3df(300, 400, 0), irr::core::vector3df(300, 0, 210));
			break;
		case (2):
			this->graphics->addCamera(irr::core::vector3df(300, 500, 299), irr::core::vector3df(300, 0, 300));
			break;
	}
	this->toggleInput["space"] = true;
}

void Launcher::pauseGame()
{
	if (this->graphicsGame)
		this->pause = !this->pause;
	this->toggleInput["esc"] = true;
}

void Launcher::launchMenu()
{
	this->pause = false;
	this->toggleInput["space"] = false;
	this->toggleInput["esc"] = false;
	this->win = false;
	this->settings->resetPlayerConfig();
	this->sceneDisplay = MENU;
	this->graphics->addCamera(irr::core::vector3df(0, 0, -230), irr::core::vector3df(0, 0, 0));
	if (!this->graphicsMenu)
		this->graphicsMenu = new GraphicsMenu(this->graphics, this->settings, this->soundMachine);
	else {
		this->soundMachine->stopAllSounds();
		this->soundMachine->playSound(SoundMachine::MAIN_MUSIC);
	}
	if (this->game)
		this->game = nullptr;
}

void Launcher::launchGame()
{
	this->win = false;
	this->sceneDisplay = GAME;
	this->graphics->addCamera(irr::core::vector3df(300, 500, 120), irr::core::vector3df(300, 0, 250));
	this->game = new Game(this->settings->getPlayerConfigList(), this->input, this->soundMachine);
	if (!this->graphicsGame) {
		this->graphicsGame = new GraphicsGame(this->graphics, this->settings, this->game, this->soundMachine, this->input);
	} else {
		this->graphicsGame->setGame(this->game);
		this->graphicsGame->createAll();
		this->soundMachine->stopAllSounds();
		this->soundMachine->playSound(SoundMachine::GAME_MUSIC);
	}
}

void Launcher::looping()
{
	if (this->sceneDisplay == NO_DISPLAY)
		this->launchMenu();
	if (this->sceneDisplay == GAME && !this->win) {
		if (!this->pause) {
			this->game->startGame();
		}
		if (!this->game->getGameEnd()) {
			this->graphicsGame->display();
		} else {
			this->soundMachine->playSound(SoundMachine::WINNER);
			this->win = true;
			this->graphics->addCamera(irr::core::vector3df(300, 500, 120), irr::core::vector3df(300, 0, 250));
			this->graphicsGame->createWin();
		}
		if (this->pause && !this->win)
			this->graphicsGame->displayPause();
	}
	if (this->win && !this->input->getInput()["esc"]) {
		this->graphics->drawAll();
		this->graphics->getAsset2DHandler()->displayById(this->graphicsGame->getWinnerTitleId());
	} else if (this->win) {
		this->graphics->getAsset3DHandler()->destroyAllAsset();
		this->graphicsGame->destroyAll();
		this->launchMenu();
	}
	if (this->sceneDisplay == MENU)
	{
		this->pause = false;
		this->graphicsMenu->display();
		if (this->settings->getNbPlayerConfig())
			this->launchGame();
	}
}

void Launcher::settingsInputs()
{
	if (this->input->getInput()["space"]) {
		if (!this->toggleInput["space"])
			this->changeRelief();
	} else {
		this->toggleInput["space"] = false;
	}
	if (this->input->getInput()["esc"]) {
		if (!this->toggleInput["esc"])
			this->pauseGame();
	} else {
		this->toggleInput["esc"] = false;
	}

}

void Launcher::launch()
{
	while (this->graphics->isDeviceRunning())
	{
		if (this->graphics->isWindowActive())
		{
			this->graphics->beginScene();
			this->looping();
			if (this->graphicsMenu && this->graphicsMenu->isQuit())
				return;
			if (!this->win)
				this->settingsInputs();
			this->graphics->endScene();
		}
	}
}