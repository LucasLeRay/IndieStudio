/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "GraphicsMenu.hpp"
#include "Assets2DHandler.hpp"
#include "Assets3DHandler.hpp"

GraphicsMenu::GraphicsMenu(Graphics *graph, Settings *settings, SoundMachine *soundMachine)
{
	this->graph = graph;
	this->settings = settings;
	this->soundMachine = soundMachine;
	this->soundMachine->setLoopSound(SoundMachine::MAIN_MUSIC, true);
	this->scene = MAINMENU;
	this->input = graph->getInput();
	this->quit_menu = false;
}

GraphicsMenu::~GraphicsMenu()
{
	this->asset2DIdList.clear();
}

void GraphicsMenu::launchGame()
{
	std::list<PlayerSelect *>::iterator it;

	for (it = this->playerSelectList.begin(); it != this->playerSelectList.end(); ++it)
	{
		this->settings->addPlayerConfig((*it));
	}
}

bool GraphicsMenu::isQuit()
{
	return (this->quit_menu);
}

bool GraphicsMenu::checkPlayerSelect()
{
	std::list<PlayerSelect *>::iterator	it;
	unsigned				nbPlayer = 0;
	unsigned				nbAi = 0;

	for (it = this->playerSelectList.begin(); it != this->playerSelectList.end(); ++it)
	{
		switch ((*it)->getPlayerType()) {
			case (PlayerSelect::PlayerType::IA):
				nbAi++;
				break;
			case (PlayerSelect::PlayerType::NO_PLAYER):
				break;
			default:
				nbPlayer++;
				break;
		}
	}
	if (nbPlayer < 1 || (nbAi + nbPlayer) < 2)
		return (false);
	return (true);
}

bool GraphicsMenu::changeScene(Button *button)
{
	std::list<PlayerSelect *>::iterator it;

	switch (button->scene)
	{
		case (sceneChanging::PLAY):
			this->scene = PLAY;
			this->soundMachine->playSound(SoundMachine::START_1);
			break;
		case (sceneChanging::BACK):
			this->scene = MAINMENU;
			break;
		case (sceneChanging::QUIT):
			this->quit_menu = true;
			break;
		case (sceneChanging::GO):
			if (this->checkPlayerSelect()) {
				this->soundMachine->stopAllSounds();
				this->launchGame();
			} else {
				return (false);
			}
			break;
		case (sceneChanging::CREDITS):
			this->scene = CREDITS;
			break;
		default:
			return (false);

	}
	this->asset2DIdList.clear();
	for (it = this->playerSelectList.begin(); it != this->playerSelectList.end(); ++it)
	{
		(*it)->deleteModel();
	}
	this->playerSelectList.clear();
	return (true);
}

void	GraphicsMenu::createButton(Graphics::typeTexture texture, Graphics::typeTexture textureFocus, int pos_x, int pos_y, sceneChanging scene, bool decalFocus)
{
	this->buttonList.push_back(new Button(this->graph->getAsset2DHandler()->create2DAsset(texture, pos_x, pos_y), texture, textureFocus, this->input, decalFocus, this->graph, scene, this->soundMachine));
}

bool GraphicsMenu::handleEventMenu()
{
	std::list<Button *>::iterator           it;
	HandleInput::MouseStateOnAsset2D        state;

	for (it = this->buttonList.begin(); it != this->buttonList.end(); ++it)
	{
		if ((*it)->execStateAction() && this->changeScene((*it)))
			return (true);
	}
	return (false);
}

void GraphicsMenu::display()
{
	std::list<PlayerSelect *>::iterator	it;
	std::list<Button *>::iterator		itButton;

	if (this->graph->isReloadScreen())
	{
		this->buttonList.clear();
		this->graph->getAsset2DHandler()->destroyAll2DAsset();
		this->createAssetsMenu();
		this->graph->setReloadScreen(false);
	}
	if (this->handleEventMenu())
		this->graph->setReloadScreen(true);
	for (it = this->playerSelectList.begin(); it != this->playerSelectList.end(); ++it)
		(*it)->handleEvent();
	this->graph->getAsset2DHandler()->displayAll2DAsset();
	this->graph->drawAll();
}

void GraphicsMenu::createAssetsMenu()
{
	switch (this->scene)
	{
		case (MAINMENU):
			this->displayMainMenu();
			break;
		case (PLAY):
			this->displayPlay();
			break;
		case (CREDITS):
			this->displayCredits();
			break;
		case (QUIT):
			this->quit();
			break;
		default:
			break;
	}
}

void GraphicsMenu::displayMainMenu()
{
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::MENU_BACKGROUND, 0, 0));
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::MENU_TITLE, 100, 100));
	this->createButton(Graphics::BUTTON_PLAY_DEF, Graphics::BUTTON_PLAY_PRESSED, (SCREEN_WIDTH) - (BUTTON_WIDTH) + 200, (SCREEN_HEIGHT / 2) - (BUTTON_HEIGHT) * 2 - 15 + 200, sceneChanging::PLAY, true);
	this->createButton(Graphics::BUTTON_CREDITS_DEF, Graphics::BUTTON_CREDITS_PRESSED, (SCREEN_WIDTH) - (BUTTON_WIDTH) + 200, (SCREEN_HEIGHT / 2) - (BUTTON_HEIGHT + 5) + 200, sceneChanging::CREDITS, true);
	this->createButton(Graphics::BUTTON_QUIT_DEF, Graphics::BUTTON_QUIT_PRESSED, (SCREEN_WIDTH) - (BUTTON_WIDTH) + 200, (SCREEN_HEIGHT / 2) + 5 + 200, sceneChanging::QUIT, true);
}

void GraphicsMenu::displayPlay()
{
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::MENU_BACKGROUND, 0, 0));
	if (this->playerSelectList.empty())
		for (int i = 0; i < 4; i++)
			this->playerSelectList.push_back(new PlayerSelect(i, this->graph, this->input));
	this->createButton(Graphics::BUTTON_BACK_DEF, Graphics::BUTTON_BACK_PRESSED, SCREEN_WIDTH / 2 - this->graph->getTextureByType(Graphics::BUTTON_BACK_DEF)->getSize().Width - 300, SCREEN_HEIGHT - BUTTON_HEIGHT - 100, sceneChanging::BACK, false);
	this->createButton(Graphics::BUTTON_GO_DEF, Graphics::BUTTON_GO_PRESSED, SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT - BUTTON_HEIGHT - 100, sceneChanging::GO, false);
}

void GraphicsMenu::displayCredits()
{
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::MENU_BACKGROUND, 0, 0));
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::CREDITS_LOGO, 100, 100));
	this->asset2DIdList.push_back(this->graph->getAsset2DHandler()->create2DAsset(Graphics::CREDITS_DEV, SCREEN_WIDTH / 2 - this->graph->getTextureByType(Graphics::CREDITS_DEV)->getSize().Width / 2, SCREEN_HEIGHT / 2 - 100));
	this->createButton(Graphics::BUTTON_BACK_DEF, Graphics::BUTTON_BACK_PRESSED, SCREEN_WIDTH / 2 - this->graph->getTextureByType(Graphics::BUTTON_BACK_DEF)->getSize().Width - 300, SCREEN_HEIGHT - BUTTON_HEIGHT - 100, sceneChanging::BACK, false);
}

void GraphicsMenu::quit()
{}

Graphics* GraphicsMenu::getGraphics() const
{
	return (this->graph);
}

Settings* GraphicsMenu::getSetting() const
{
	return (this->settings);
}
