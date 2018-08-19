/*
** Bonus.cpp
*/

#include "Bonus.hpp"

/*	Constructor	*/
Bonus::Bonus(pos_t pos, int id)
{	
	this->type = type_e::FIRE_UP;
	if (std::rand() % 2 == 0)
		this->type = type_e::BOMB_UP;
	else if (std::rand() % 4 == 0)
		this->type = type_e::SPEED_UP;
	else if (std::rand() % 6 == 0)
		this->type = type_e::WALL_PASS;
	this->pos = pos;
	this->id = id;
}

Bonus::Bonus(int id, pos_t pos, int type)
{
	this->id = id;
	this->pos = pos;
	this->type = static_cast<type_e>(type);
}

/*	Action		*/
int		Bonus::applyEffect(Bomberman &player)
{
	if (this->type == type_e::BOMB_UP)
		player.setNbBomb(player.getNbBomb() + 1);
	else if (this->type == type_e::SPEED_UP)
		player.setSpeed(player.getSpeed() + 1);
	else if (this->type == type_e::FIRE_UP)
		player.setFireUp(player.getFireUp() + 1);
	else if (this->type == type_e::WALL_PASS)
		player.canPassWall(true);
	return (0);
}

/*	Getter		*/
type_e		Bonus::getType(void)
{
	return (this->type);
}

pos_t		Bonus::getPos(void)
{
	return (this->pos);
}

int		Bonus::getId(void)
{
	return (this->id);
}