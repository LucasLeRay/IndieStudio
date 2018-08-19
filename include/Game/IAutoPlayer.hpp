/*
** IAutoPlayer.hpp
*/

#ifndef IAUTOPLAYER_HPP_
# define IAUTOPLAYER_HPP_

# include "indie.hpp"
# include "IGame.hpp"

/*	Interface			*/
class				IAutoPlayer {
public:
	/*	Constructor		*/
	virtual	~IAutoPlayer(void) = default;
	/*	Action			*/
	virtual	action_e	autoPlay(Bomberman &player, Map *map) = 0;
};

#endif /* !IAUTOPLAYER_HPP_ */
