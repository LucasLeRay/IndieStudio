/*
** AutoPlayer.cpp
*/

#include "AutoPlayer.hpp"

/*	Constructor	*/
AutoPlayer::AutoPlayer(void)
{
	this->dangerPos.X = NO_POS_X;
	this->dangerPos.Z = NO_POS_Z;
}

/*	Action		*/
action_e		AutoPlayer::autoPlay(Bomberman &player, Map *map)
{
	action_e	action;

	if (!this->posIsDangerous(player, map)){
		action = this->playOffensive(player, map);
	} else {
		action = this->playDefensive(player, map);
		this->desactivateDanger();
	}
	player.move(static_cast<dir_e>(action));
	return (action);
}

/*	AI Strategie	*/
void				AutoPlayer::desactivateDanger(void)
{
	this->dangerPos.X = NO_POS_X;
	this->dangerPos.Z = NO_POS_Z;
}

bool				AutoPlayer::playerCanMove(Bomberman &player, Map *map, dir_e dir)
{
	for (Wall wall : map->getWalls()) {
		if (dir == dir_e::UP
			&& trunc(player.getPos().X) == trunc(wall.getPos().X)
			&& trunc(player.getPos().Z + 1) == trunc(wall.getPos().Z)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::DOWN
			&& trunc(player.getPos().X) == trunc(wall.getPos().X)
			&& trunc(player.getPos().Z - 1) == trunc(wall.getPos().Z)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::LEFT
			&& trunc(player.getPos().Z) == trunc(wall.getPos().Z)
			&& trunc(player.getPos().X - 1) == trunc(wall.getPos().X)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::RIGHT
			&& trunc(player.getPos().Z) == trunc(wall.getPos().Z)
			&& trunc(player.getPos().X + 1) == trunc(wall.getPos().X)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
	}
	return (true);
}

action_e		AutoPlayer::playOffensive(Bomberman &player, Map *map)
{
	return (action_e::K_NOTHING);
}

action_e		AutoPlayer::playDefensive(Bomberman &player, Map *map)
{
	if (trunc(this->dangerPos.X) == trunc(player.getPos().X)) {
		if (this->playerCanMove(player, map, dir_e::LEFT))
			return (action_e::K_LEFT);
		if (this->playerCanMove(player, map, dir_e::RIGHT))
			return (action_e::K_RIGHT);
		if (this->dangerPos.Z > player.getPos().Z
			&& this->playerCanMove(player, map, dir_e::DOWN)) {
			return (action_e::K_DOWN);
		} else if (this->dangerPos.Z < player.getPos().Z
			&& this->playerCanMove(player, map, dir_e::UP)) {
			return (action_e::K_UP);
		}
	} else if (trunc(this->dangerPos.Z) == trunc(player.getPos().Z)) {
		if (this->playerCanMove(player, map, dir_e::UP))
			return (action_e::K_UP);
		if (this->playerCanMove(player, map, dir_e::DOWN))
			return (action_e::K_DOWN);
		if (this->dangerPos.X > player.getPos().X
			&& this->playerCanMove(player, map, dir_e::LEFT)) {
			return (action_e::K_LEFT);
		} else if (this->dangerPos.X < player.getPos().X
			&& this->playerCanMove(player, map, dir_e::RIGHT)) {
			return (action_e::K_RIGHT);
		}
	}
	return (action_e::K_NOTHING);
}

bool			AutoPlayer::posIsDangerous(Bomberman &player, Map *map)
{
	for (Bomb bomb : map->getBombs()) {
		if (trunc(bomb.getPos().X) == trunc(player.getPos().X) || trunc(bomb.getPos().Z) == trunc(player.getPos().Z)) {
			this->dangerPos = bomb.getPos();
			return (true);
		}
	}
	return (false);
}