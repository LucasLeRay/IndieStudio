/*
** Floor.cpp
*/

#include "Floor.hpp"

/*	Constructor		*/
Floor::Floor(pos_t pos)
{
	this->pos = pos;
	this->id = NO_ID;
}

/*	Action			*/

/*	Getter			*/
pos_t			Floor::getPos(void)
{
	return (this->pos);
}

int			Floor::getId(void)
{
	return (this->id);
}

/*	Setter			*/
