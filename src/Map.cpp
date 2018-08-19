/*
** Map.cpp
*/

#include "Map.hpp"

/*	Constructor			*/
Map::Map(void)
{
	this->id = NO_ID;
	this->size = MAP_SIZE;
	this->pos.X = 0;
	this->pos.Y = 0;
	this->pos.Z = 0;
	this->generate();
}

/*	Action				*/
/*	Add Object On The Map		*/
int 			Map::addPlayer(Bomberman player)
{
	this->players.push_back(player);
}

int 			Map::addWall(Wall wall)
{
	this->walls.push_back(wall);
}

int			Map::addBomb(Bomb bomb)
{
	this->bombs.push_back(bomb);
}

int			Map::addBonus(Bonus bonus)
{
	this->bonus.push_back(bonus);
}

int			Map::addFire(Fire fire)
{
	this->fire.push_back(fire);
}

int			Map::addFloor(Floor floor)
{
	this->floors.push_back(floor);
}

void			Map::displayMap(void)
{
	for (float i = 0; i < this->size; i++) {
		for (float j = 0; j < this->size; j++) {
			if (this->checkPos({i, 0, j}) == "Bomb")
				std::cout << "db";
			else if (this->checkPos({i, 0, j}) == "Fire")
				std::cout << "SS";
			else if (this->checkPos({i, 0, j}) == "Breakable")
				std::cout << "==";
			else if (this->checkPos({i, 0, j}) == "Unbreakable")
				std::cout << "||";
			else if (this->checkPos({i, 0, j}) == "Bonus")
				std::cout << "**";
			else if (this->checkPos({i, 0, j}) == "")
				std::cout << "  ";
			else 
				std::cout << ":" << this->checkPos({i, 0, j});
		}
		std::cout << std::endl;
	}
}

int			Map::newWallId(void)
{
	int		id = 0;

	for (Wall wall : this->walls) {
		if (id == wall.getId())
			id += 1;
	}
	return (id);
}

int			Map::newBombId(void)
{
	int		id = 0;

	for (Bomb bomb : this->bombs) {
		if (id == bomb.getId())
			id += 1;
	}
	return (id);
}

int			Map::newBonusId(void)
{
	int		id = 0;

	for (Bonus bonus : this->bonus) {
		if (id == bonus.getId())
			id += 1;
	}
	return (id);
}

int			Map::newFireId(void)
{
	int		id = 0;

	for (Fire fire : this->fire) {
		if (id == fire.getId())
			id += 1;
	}
	return (id);
}

/*	Destroy Object On The Map	*/
int			Map::destroyPlayer(pos_t pos)
{
	int		i = 0;

	for (Bomberman player : this->players) {
		if (player.getPos().X == pos.X
			&& player.getPos().Z == pos.Z) {
			this->players.erase(this->players.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyWall(pos_t pos)
{
	int		i = 0;

	for (Wall wall : this->walls) {
		if (trunc(wall.getPos().X) == trunc(pos.X)
			&& trunc(wall.getPos().Z) == trunc(pos.Z)) {
			this->walls.erase(this->walls.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyBomb(pos_t pos)
{
	int		i = 0;

	for (Bomb bomb : this->bombs) {
		if (trunc(bomb.getPos().X) == trunc(pos.X)
			&& trunc(bomb.getPos().Z) == trunc(pos.Z)) {
			this->bombs.erase(this->bombs.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyBonus(pos_t pos)
{
	int		i = 0;

	for (Bonus bonus : this->bonus) {
		if (bonus.getPos().X == pos.X
			&& bonus.getPos().Z == pos.Z) {
			this->bonus.erase(this->bonus.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyFire(pos_t origin)
{
	int		i = 0;

	for (Fire fire : this->fire) {
		if (fire.getOrigin().X == origin.X
			&& fire.getOrigin().Z == origin.Z) {
			this->fire.erase(this->fire.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyPlayerById(int id)
{
	int		i = 0;

	for (Bomberman &player : this->players) {
		if (player.getId() == id) {
			this->players.erase(this->players.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyWallById(int id)
{
	int		i = 0;

	for (Wall &wall : this->walls) {
		if (wall.getId() == id) {
			this->walls.erase(this->walls.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyBombById(int id)
{
	int		i = 0;

	for (Bomb &bomb : this->bombs) {
		if (bomb.getId() == id) {
			this->bombs.erase(this->bombs.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyBonusById(int id)
{
	int		i = 0;

	for (Bonus &bonus : this->bonus) {
		if (bonus.getId() == id) {
			this->bonus.erase(this->bonus.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::destroyFireById(int id)
{
	int		i = 0;

	for (Fire &fire : this->fire) {
		if (fire.getId() == id) {
			this->fire.erase(this->fire.begin() + i);
			return (0);
		}
		i += 1;
	}
	return (1);
}

int			Map::givebackBombToPlayer(int id)
{
	for (Bomberman &player : this->players) {
		if (player.getId() == id) {
			player.setNbBombActive(player.getNbBombActive() - 1);
			return (0);
		}
	}
	return (1);
}


/*	Remove Objects On The Map	*/
int			Map::removePlayers(void)
{
	this->players.clear();
	return (0);
}

int			Map::removeWalls(void)
{
	this->walls.clear();
	return (0);
}

/*	Others				*/
std::vector<Bomberman>	&Map::getRealPlayers(void)
{
	return (this->players);
}

std::vector<Wall>	&Map::getRealWalls(void)
{
	return (this->walls);
}


std::vector<Bomb>	&Map::getRealBombs(void)
{
	return (this->bombs);
}

std::vector<Fire>	&Map::getRealFire(void)
{
	return (this->fire);
}

std::string		Map::checkPos(pos_t pos)
{
	for (Wall wall : this->walls) {
		if (trunc(pos.X) == trunc(wall.getPos().X)
			&& trunc(pos.Z) == trunc(wall.getPos().Z))
			return (wall.isBreakable() ? "Breakable": "Unbreakable");
	}
	for (Bomb bomb : this->bombs) {
		if (trunc(pos.X) == trunc(bomb.getPos().X)
			&& trunc(pos.Z) == trunc(bomb.getPos().Z))
			return ("Bomb");
	}
	for (Bonus bonus : this->bonus) {
		if (trunc(pos.X) == trunc(bonus.getPos().X)
			&& trunc(pos.Z) == trunc(bonus.getPos().Z))
			return ("Bonus");
	}
	return ("");
}

/*	Getter		*/
std::vector<Bomberman>	Map::getPlayers(void)
{
	return (this->players);
}

std::vector<Wall>	Map::getWalls(void)
{
	return (this->walls);
}

std::vector<Bomb>	Map::getBombs(void)
{
	return (this->bombs);
}

std::vector<Bonus>	Map::getBonus(void)
{
	return (this->bonus);
}

std::vector<Fire>	Map::getFire(void)
{
	return (this->fire);
}

std::vector<Floor>	Map::getFloors(void)
{
	return (this->floors);
}

pos_t			Map::getPos(void)
{
	return (this->pos);
}

int			Map::getSize(void)
{
	return (this->size);
}

int			Map::getId(void)
{
	return (this->id);
}

/*	Private		*/
void			Map::borderWall(void)
{
	for (int i = 0; i <= this->size; i += 1) {
		this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(0)}, this->newWallId(), false));
		this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(this->size)}, this->newWallId(), false));
	}
	for (int i = 0; i <= this->size; i += 1) {
		this->addWall(Wall({static_cast<float>(0), 0, static_cast<float>(i)}, this->newWallId(), false));
		this->addWall(Wall({static_cast<float>(this->size), 0, static_cast<float>(i)}, this->newWallId(), false));
	}
}

void			Map::mapPattern(int nb)
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			// let four free case per angle
			if (DOWN_LEFT_CORNER || DOWN_RIGHT_CORNER || UP_LEFT_CORNER || UP_RIGHT_CORNER)
				continue;
			// add one wall per angle at disagonale
			if ((i == 2 && j == 2) || (i == 2 && j == this->size - 2) || (i == this->size - 2 && j == 2) || (i == this->size - 2 && j == this->size - 2))
				this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(j)}, this->newWallId(), false));
			// other walls
			if (i % 2 != 0 && j % 2 != 0)
				this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(j)}, this->newWallId(), false));
			if (nb == 1 && i % 4 != 0 && j % 4 == 0)
				this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(j)}, this->newWallId(), false));
			else if (nb == 2 && i % 6 != 0 && j % 4 == 0)
				this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(j)}, this->newWallId(), false));
			else if (nb == 3 && i % 6 != 0 && j % 6 == 0)
				this->addWall(Wall({static_cast<float>(i), 0, static_cast<float>(j)}, this->newWallId(), false));
		}
	}
}

void			Map::fillMap(void)
{
	bool		check;

	for (float i = 0; i < this->size; i++) {
		for (float j = 0; j < this->size; j++) {
			this->addFloor(Floor({i, 0, j}));
			if (DOWN_LEFT_CORNER || DOWN_RIGHT_CORNER || UP_LEFT_CORNER || UP_RIGHT_CORNER)
				continue;
			if (this->checkPos({i, 0, j}) == "") {
				int nb = std::rand() % 5;
				if (nb < 4) {
					this->addWall(Wall({i, 0, j}, this->newWallId(), true));
				}
			}
		}
	}
}

void			Map::generate(void)
{
	this->borderWall();
	this->mapPattern(std::rand() % 4);
	this->fillMap();
}
