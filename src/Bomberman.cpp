/*
** Bomberman.cpp
*/

#include "Bomberman.hpp"

/*	Constructor	*/
Bomberman::Bomberman(int id, playerConfig config, pos_t pos)
{
	this->id = id;
	this->actionKeyList = config.key;
	this->type = config.objectType;
	this->state = animation::IDLE;
	this->pos = pos;
	this->fireUp = DEFAULT_FIRE_UP;
	this->nbBombActive = DEFAULT_NB_BOMB_ACTIVE;
	this->nbBomb = DEFAULT_NB_BOMB;
	this->speed = DEFAULT_SPEED;
	this->passWall = DEFAULT_WALLPASS;
	this->alive = DEFAULT_ALIVE;
	this->ai = config.isAi;
}

Bomberman::Bomberman(int id, playerConfig config, pos_t pos, int bonus, int bomb, float speed, bool wall, bool alive)
{
	this->id = id;
	this->actionKeyList = config.key;
	this->pos = pos;
	this->fireUp = bonus;
	this->nbBomb = bomb;
	this->nbBombActive = 0;
	this->speed = speed;
	this->passWall = wall;
	this->alive = alive;
	this->dir = dir_e::DOWN;
	this->state = animation::IDLE;
}

/*	Action		*/
void		Bomberman::move(dir_e dir)
{
	if (dir == dir_e::UP) {
		this->dir = dir_e::UP;
		this->pos.Z += this->speed;
		this->pos.X = trunc(this->pos.X) + HALF_CASE;
	}
	else if (dir == dir_e::LEFT) {
		this->dir = dir_e::LEFT;
		this->pos.X -= this->speed;
		this->pos.Z = trunc(this->pos.Z) + HALF_CASE;
	}
	else if (dir == dir_e::RIGHT) {
		this->dir = dir_e::RIGHT;
		this->pos.X += this->speed;
		this->pos.Z = trunc(this->pos.Z) + HALF_CASE;
	}
	else if (dir == dir_e::DOWN) {
		this->dir = dir_e::DOWN;
		this->pos.Z -= this->speed;
		this->pos.X = trunc(this->pos.X) + HALF_CASE;
	}
	this->state = animation::WALK;
}

/*	Getter		*/
ActionKeyList		Bomberman::getActionKeyList(void)
{
	return (this->actionKeyList);
}

Graphics::typeObj	Bomberman::getType(void)
{
	return (this->type);
}

animation		Bomberman::getState(void)
{
	return (this->state);
}

dir_e			Bomberman::getDir(void)
{
	return (this->dir);
}

pos_t			Bomberman::getPos(void)
{
	return (this->pos);
}

float			Bomberman::getSpeed(void)
{
	return (this->speed);
}

int			Bomberman::getNbBombActive(void)
{
	return (this->nbBombActive);
}

int			Bomberman::getNbBomb(void)
{
	return (this->nbBomb);
}

int			Bomberman::getFireUp(void)
{
	return (this->fireUp);
}

bool			Bomberman::canPassWall(void)
{
	return (this->passWall);
}

bool			Bomberman::isAlive(void)
{
	return (this->alive);
}

bool			Bomberman::isAi(void)
{
	return (this->ai);
}

int			Bomberman::getId(void)
{
	return (this->id);
}

/*	Setter		*/
void			Bomberman::setState(animation anim)
{
	this->state = anim;
}

void			Bomberman::setPos(pos_t pos)
{
	this->pos = pos;
}

void			Bomberman::setSpeed(float speed)
{
	this->speed = speed;
}

void			Bomberman::setNbBombActive(int nbBombActive)
{
	this->nbBombActive = nbBombActive;
}

void			Bomberman::setNbBomb(int nbBomb)
{
	this->nbBomb = nbBomb;
}

void			Bomberman::setFireUp(int fireUp)
{
	this->fireUp = fireUp;
}

void			Bomberman::canPassWall(bool passWall)
{
	this->passWall = passWall;
}

void			Bomberman::isAlive(bool alive)
{
	this->alive = alive;
}
