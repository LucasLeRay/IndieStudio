/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_LAUNCHER_HPP
#define CPP_INDIE_STUDIO_LAUNCHER_HPP

#include "indie.hpp"

class SoundMachine;
class Settings;
class HandleInput;
class Graphics;
class Game;
class GraphicsGame;
class GraphicsMenu;
class Assets2DHandler;

enum	display_e {
	GAME,
	MENU,
	NO_DISPLAY
};

class   Launcher
{
	public:

	Launcher();

	~Launcher();

	void	changeRelief();

	void	pauseGame();

	void	displayPause();

	void    launchMenu();

	void    launchGame();

	void    looping();

	void	settingsInputs();

	void    launch();

	private:
	Settings       			*settings;
	SoundMachine    		*soundMachine;
	HandleInput     		*input;
	Graphics        		*graphics;
	Game            		*game;
	GraphicsGame    		*graphicsGame;
	GraphicsMenu    		*graphicsMenu;
	unsigned			relief;
	std::map<std::string, bool>	toggleInput;
	bool				pause;
	display_e			sceneDisplay;
	bool				win;
};

#endif //CPP_INDIE_STUDIO_LAUNCHER_HPP
