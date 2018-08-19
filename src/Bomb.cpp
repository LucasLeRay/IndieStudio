/*
** Bomb.cpp
*/

#include "Bomb.hpp"

/*	Constructor	*/
Bomb::Bomb(pos_t pos, int range, int playerId, int id)
{
	this->dropTime = std::time(nullptr);
	this->pos = pos;
	this->range = DEFAULT_BOMB_RANGE;
	this->playerId = playerId;
	this->id = id;
	this->used = DEFAULT_BOMB_USED;
}

Bomb::Bomb(int id, pos_t pos, int range)
{
	this->dropTime = std::time(nullptr);
	this->id = id;
	this->pos = pos;
	this->range = range;
	this->used = DEFAULT_BOMB_USED;
}

/*	Action		*/
void		Bomb::explode(void)
{
	this->used = true;
}

/*	Getter		*/
std::time_t	Bomb::getDropTime(void)
{
	return (this->dropTime);
}

pos_t		Bomb::getPos(void)
{
	return (this->pos);
}

int		Bomb::getRange(void)
{
	return (this->range);
}

int		Bomb::getPlayerId(void)
{
	return (this->playerId);
}

int		Bomb::getId(void)
{
	return (this->id);
}

bool		Bomb::isUsed(void)
{
	return (this->used);
}

/*	Setter		*/
void		Bomb::setPos(pos_t pos)
{
	this->pos = pos;
}

void		Bomb::setRange(int range)
{
	this->range = range;
}
