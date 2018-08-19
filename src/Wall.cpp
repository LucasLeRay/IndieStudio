/*
** Wall.cpp
*/

#include "Wall.hpp"

/*	Constructor	*/
Wall::Wall(pos_t pos, int id, bool breakable)
{
	this->pos = pos;
	this->id = id;
	this->breakable = breakable;
}

Wall::Wall(int id, pos_t pos, bool breakable)
{
	this->id = id;
	this->pos = pos;
	this->breakable = breakable;
}

/*	Getter		*/
pos_t		Wall::getPos(void)
{
	return (this->pos);
}

bool		Wall::isBreakable(void)
{
	return (this->breakable);
}

int		Wall::getId(void)
{
	return (this->id);
}

/*	Setter		*/