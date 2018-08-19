/*
** AutoPlayer.hpp
*/

#ifndef AUTOPLAYER_HPP_
# define AUTOPLAYER_HPP_

# include "IAutoPlayer.hpp"

/*	Class AutoPlayer		*/
class				AutoPlayer : public IAutoPlayer {
private:
	pos_t			dangerPos;
public:
	/*	Constructor		*/
	AutoPlayer(void);
	~AutoPlayer(void) = default;
	/*	Action			*/
	action_e		autoPlay(Bomberman &player, Map *map) override;
private:
	/* 	AI Strategie		*/
	void			desactivateDanger(void);
	bool			playerCanMove(Bomberman &player, Map *map, dir_e dir);
	action_e		playOffensive(Bomberman &player, Map *map);
	action_e		playDefensive(Bomberman &player, Map *map);
	bool			posIsDangerous(Bomberman &player, Map *map);
};

#endif /* !AUTOPLAYER_HPP_ */