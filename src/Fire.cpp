/*
** Fire.cpp
*/

#include "Fire.hpp"

/*	Constructor		*/
Fire::Fire(pos_t origin, pos_t pos, int id)
{
	this->origin = origin;
	this->pos = pos;
	this->id = id;
}

/*	Action			*/

/*	Getter			*/
pos_t			Fire::getOrigin(void)
{
	return (this->origin);
}

pos_t			Fire::getPos(void)
{
	return (this->pos);
}

int			Fire::getId(void)
{
	return (this->id);
}

/*	Setter			*/
