/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "../../include/Graphics/Settings.hpp"
#include "PlayerSelect.hpp"

Settings::Settings()
{
	this->resolution = irr::core::vector2d<int>(this->defaultScreenWidth, this->defaultScreenHeight);
	this->volume = this->defaultVolume;
}

Settings::~Settings()
{
}

int Settings::getVolume() const
{
	return(this->volume);
}

void Settings::setVolume(int volume)
{
	this->volume = volume;
}

irr::core::vector2d<int> Settings::getResolution() const
{
	return(this->resolution);
}

void Settings::setResolution(irr::core::vector2d<int> resolution)
{
	this->resolution = resolution;
}

void Settings::createPlayerConfig(std::string k1, std::string k2, std::string k3, std::string k4, std::string action,
                                  bool isAi, unsigned typeObj)
{
	playerConfig *playerConf = new playerConfig;

	playerConf->key[action_e::K_UP] = k1;
	playerConf->key[action_e::K_DOWN] = k3;
	playerConf->key[action_e::K_LEFT] = k2;
	playerConf->key[action_e::K_RIGHT] = k4;
	playerConf->key[action_e::K_ACTION] = action;
	playerConf->isAi = isAi;
	playerConf->objectType = (Graphics::typeObj)(typeObj);

	this->playerConfigList.push_back(playerConf);

}

std::list<playerConfig *>	Settings::getPlayerConfigList()
{
	return (this->playerConfigList);
}

unsigned long Settings::getNbPlayerConfig()
{
	return (this->playerConfigList.size());
}

void Settings::addPlayerConfig(PlayerSelect *player)
{
	switch (player->getPlayerType())
	{
		case (PlayerSelect::J1):
			this->createPlayerConfig("z", "q", "s", "d", "shiftLeft", false, player->getModelChoosing());
			break;
		case (PlayerSelect::J2):
			this->createPlayerConfig("o", "k", "l", "m", "shiftRight", false, player->getModelChoosing());
			break;
		case (PlayerSelect::J3):
			this->createPlayerConfig("cUp1", "cLeft1", "cDown1", "cRight1", "cAction1", false, player->getModelChoosing());
			break;
		case (PlayerSelect::J4):
			this->createPlayerConfig("cUp2", "cLeft2", "cDown2", "cRight2", "cAction2", false, player->getModelChoosing());
			break;
		case (PlayerSelect::IA):
			this->createPlayerConfig("", "", "", "", "", true, player->getModelChoosing());
			break;
		default:
			return;
	}
}

void	Settings::resetPlayerConfig()
{
	this->playerConfigList.clear();
}



