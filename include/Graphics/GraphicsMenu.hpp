/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_GRAPHICSMENU_HPP
#define CPP_INDIE_STUDIO_GRAPHICSMENU_HPP

#include "Settings.hpp"
#include "Graphics.hpp"
#include "HandleInput.hpp"
#include "SoundMachine.hpp"
#include "PlayerSelect.hpp"
#include "Button.hpp"

#define BUTTON_HEIGHT (this->graph->getTextureByType(Graphics::BUTTON_PLAY_DEF)->getSize().Height)
#define BUTTON_WIDTH (this->graph->getTextureByType(Graphics::BUTTON_PLAY_DEF)->getSize().Width)

class IObject;

class GraphicsMenu
{
	public:

	enum sceneMenu
	{
		MAINMENU,
		PLAY,
		CREDITS,
		QUIT
	};

	GraphicsMenu(Graphics *graph, Settings *settings, SoundMachine *soundMachine);

	~GraphicsMenu();

	void            display();

	Graphics        *getGraphics() const;

	Settings        *getSetting() const;

	bool		isQuit();

	private:

	void	createButton(Graphics::typeTexture texture, Graphics::typeTexture textureFocus, int pos_x, int pos_y, sceneChanging scene, bool decalFocus);

	bool    handleEventMenu();

	void    createAssetsMenu();

	void    displayMainMenu();

	void    displayPlay();

	void    displayCredits();

	bool    changeScene(Button *button);

	void    launchGame();

	void    quit();

	bool	checkPlayerSelect();

	std::list<unsigned>             asset2DIdList;
	std::list<Button *>             buttonList;
	HandleInput                     *input;
	Graphics                        *graph;
	Settings                        *settings;
	SoundMachine                    *soundMachine;
	sceneMenu                       scene;
	std::list<PlayerSelect *>       playerSelectList;
	bool				quit_menu;
};

#endif //CPP_INDIE_STUDIO_GRAPHICSMENU_HPP
