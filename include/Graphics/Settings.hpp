/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** created by Roméo Nahon
*/

#ifndef CPP_INDIE_STUDIO_SETTINGS_HPP
#define CPP_INDIE_STUDIO_SETTINGS_HPP

#include "indie.hpp"
#include "Graphics.hpp"

/*	enum		*/
enum		action_e {
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_ACTION,
	K_NOTHING
};

/*	structure	*/
struct  playerConfig {
	std::map<action_e, std::string>	key;
	Graphics::typeObj		objectType;
	bool				isAi;
};

class   PlayerSelect;

class   Settings
{
	public:

	static const int      defaultScreenWidth = 1920;

	static const int      defaultScreenHeight = 1080;

	static const int      defaultVolume = 100;

	Settings();

	~Settings();

	void    createPlayerConfig(std::string k1, std::string k2, std::string k3,
	                           std::string k4, std::string action, bool isPlayer, unsigned typeObj);

	int     getVolume() const;

	void    setVolume(int volume);

	irr::core::vector2d<int>     getResolution() const;

	void    setResolution(irr::core::vector2d<int> resolution);

	void    addPlayerConfig(PlayerSelect *player);

	unsigned long			getNbPlayerConfig();

	void				resetPlayerConfig();

	std::list<playerConfig *>	getPlayerConfigList();

	private:
	std::list<playerConfig *>         playerConfigList;
	int                               volume;
	irr::core::vector2d<int>          resolution;
};
#endif //CPP_INDIE_STUDIO_SETTINGS_HPP
