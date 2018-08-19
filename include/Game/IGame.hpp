/*
** IGame.hpp
*/

#ifndef IGAME_HPP_
# define IGAME_HPP_

# include "indie.hpp"
# include "HandleInput.hpp"
# include "Map.hpp"
# include "SoundMachine.hpp"

/*	Typedef				*/
typedef std::list<struct playerConfig *>	PlayerConfigList;
typedef std::map<std::string, bool>		mapKey;

/*	Interface			*/
class					IGame {
public:
	/*	Constructor		*/
	virtual ~IGame(void) = default;
	/*	Action			*/
	virtual int			startGame(void) = 0;
	virtual int			saveGame(void) = 0;
	virtual int			loadGame(void) = 0;
	/*	Getter			*/
	virtual PlayerConfigList	getPlayerConfigList(void) = 0;
	virtual HandleInput		*getHandleInput(void) = 0;
	virtual Map			getMap(void) = 0;
	virtual int			getNbPlayer(void) = 0;
	virtual bool			getGameEnd(void) = 0;
	/*	Setter			*/
	virtual void			setNbPlayer(int nbPlayer) = 0;
};

#endif /* !IGAME_HPP_ */