/*
** Game.cpp
*/

#include "Game.hpp"

/*	Constructor		*/
Game::Game(PlayerConfigList playerConfigList, HandleInput *handleInput, SoundMachine *soundMachine)
{
	int	i = 1;

	this->playerConfigList = playerConfigList;
	this->handleInput = handleInput;
	this->soundMachine = soundMachine;
	for (struct playerConfig *playerConfig : this->playerConfigList) {
		if (i == 1)
			this->map.addPlayer(Bomberman(1, *playerConfig,
				{DOWN_LEFT_X, DOWN_LEFT_Y, DOWN_LEFT_Z}));
		else if (i == 2)
			this->map.addPlayer(Bomberman(2, *playerConfig,
				{UP_LEFT_X, UP_LEFT_Y, UP_LEFT_Z}));
		else if (i == 3)
			this->map.addPlayer(Bomberman(3, *playerConfig,
				{DOWN_RIGHT_X, DOWN_RIGHT_Y, DOWN_RIGHT_Z}));
		else if (i == 4)
			this->map.addPlayer(Bomberman(4, *playerConfig,
				{UP_RIGHT_X, UP_RIGHT_Y, UP_RIGHT_Z}));
		i += 1;
	}
	this->nbPlayer = i;
	this->gameEnd = false;
}

/*	Action			*/
int					Game::startGame(void)
{
	static auto			timer = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli>	time_span = std::chrono::high_resolution_clock::now() - timer;

	while (time_span.count() < 50)
		time_span = std::chrono::high_resolution_clock::now() - timer;
	timer = std::chrono::high_resolution_clock::now();
	if (!this->playerAreFighting())
		this->gameEnd = true;
	this->manageAutoPlayers();
	this->manageInputs();
	this->manageBombs();
	this->manageFire();
	this->manageBonus();
	return (0);
}

int				Game::saveGame(void)
{
	std::string		mapInfos;
	std::ofstream 		file;

	mapInfos += this->savePlayersInfos();
	mapInfos += this->saveWallsInfos();
	mapInfos += this->saveBombsInfos();
	mapInfos += this->saveBonusInfos();
	file.open(CONFIG_FILE);
	file << mapInfos;
	file.close();
	std::cout << "Map Successfully Saved !" << std::endl;
	return (0);
}

int				Game::loadGame(void)
{
	std::ifstream		file;
	std::string		line;

	this->map.removePlayers();
	this->map.removeWalls();
	file.open(CONFIG_FILE);
	while(!file.eof()) {
		getline(file, line);
		if (!line.find("player")) {
			this->createPlayerFromFile(line);
		} else if (!line.find("wall")) {
			this->createWallFromFile(line);
		} else if (!line.find("bomb")) {
			this->createBombFromFile(line);
		} else if (!line.find("bonus")) {
			this->createBonusFromFile(line);
		} else if (line.find("Player") == std::string::npos 
			&& line.find("Wall") == std::string::npos
			&& line.find("Bomb") == std::string::npos
			&& line.find("Bonus") == std::string::npos
			&& line.length() > 1) {
			std::cout << "File Corrompted" << std::endl;
			return (1);
		}
	}
	file.close();
	std::cout << "Map Successfully Loaded !" << std::endl;	
	return (0);
}

/*	Getter			*/
PlayerConfigList		Game::getPlayerConfigList(void)
{
	return (this->playerConfigList);
}

HandleInput			*Game::getHandleInput(void)
{
	return (this->handleInput);
}

Map				Game::getMap(void)
{
	return (this->map);
}

int				Game::getNbPlayer(void)
{
	return (this->nbPlayer);
}

bool				Game::getGameEnd()
{
	return (this->gameEnd);
}

/*	Setter			*/
void				Game::setNbPlayer(int nbPlayer)
{
	this->nbPlayer = nbPlayer;
}

/*	Private			*/
/*	Manage AutoPlayers	*/
int				Game::manageAutoPlayers(void)
{
	for (Bomberman &player : this->map.getRealPlayers()) {
		if (player.isAi())
			this->autoPlayer.autoPlay(player, &this->map);
	}
	return (0);
}

/*	Manage Inputs		*/
bool				Game::noWallBlock(Bomberman player, dir_e dir)
{
	if (dir == dir_e::DOWN && player.getPos().Z - player.getSpeed() < 1)
		return (false);
	for (Wall wall : this->map.getWalls()) {
		if (dir == dir_e::UP
			&& trunc(player.getPos().X) == trunc(wall.getPos().X)
			&& trunc(player.getPos().Z + player.getSpeed()) == trunc(wall.getPos().Z)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::DOWN
			&& trunc(player.getPos().X) == trunc(wall.getPos().X)
			&& trunc(player.getPos().Z - player.getSpeed()) == trunc(wall.getPos().Z)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::LEFT
			&& trunc(player.getPos().Z) == trunc(wall.getPos().Z)
			&& trunc(player.getPos().X - player.getSpeed()) == trunc(wall.getPos().X)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
		else if (dir == dir_e::RIGHT
			&& trunc(player.getPos().Z) == trunc(wall.getPos().Z)
			&& trunc(player.getPos().X + player.getSpeed()) == trunc(wall.getPos().X)) {
			if (wall.isBreakable() && player.canPassWall())
				continue;
			return (false);
		}
	}
	return (true);
}

bool				Game::noBombBlock(Bomberman player, dir_e dir)
{
	for (Bomb bomb : this->map.getBombs()) {
		if (trunc(bomb.getPos().X) == trunc(player.getPos().X)
			&& trunc(bomb.getPos().Z) == trunc(player.getPos().Z))
			continue;
		if (dir == dir_e::UP
			&& trunc(player.getPos().X) == trunc(bomb.getPos().X)
			&& trunc(player.getPos().Z + player.getSpeed()) == trunc(bomb.getPos().Z)) {
			return (false);
		}
		else if (dir == dir_e::DOWN
			&& trunc(player.getPos().X) == trunc(bomb.getPos().X)
			&& trunc(player.getPos().Z - player.getSpeed()) == trunc(bomb.getPos().Z)) {
			return (false);
		}
		else if (dir == dir_e::LEFT
			&& trunc(player.getPos().Z) == trunc(bomb.getPos().Z)
			&& trunc(player.getPos().X - player.getSpeed()) == trunc(bomb.getPos().X)) {
			return (false);
		}
		else if (dir == dir_e::RIGHT
			&& trunc(player.getPos().Z) == trunc(bomb.getPos().Z)
			&& trunc(player.getPos().X + player.getSpeed()) == trunc(bomb.getPos().X)) {
			return (false);
		}
	}
	return (true);
}

bool				Game::playerCanMove(Bomberman player, dir_e dir)
{
	if (this->noWallBlock(player, dir)
		&& this->noBombBlock(player, dir))
		return (true);
	return (false);
}

int				Game::manageInputs(void)
{
	mapKey			inputs;
	int			id = 1;

	inputs = this->handleInput->getInput();
	for (Bomberman &player : this->map.getRealPlayers()) {
		player.setState(animation::IDLE);
		if (inputs[player.getActionKeyList()[action_e::K_UP]] == true
			&& this->playerCanMove(player, dir_e::UP)) {
			player.move(dir_e::UP);
		}
		if (inputs[player.getActionKeyList()[action_e::K_DOWN]] == true
			&& this->playerCanMove(player, dir_e::DOWN))
			player.move(dir_e::DOWN);
		if (inputs[player.getActionKeyList()[action_e::K_LEFT]] == true
			&& this->playerCanMove(player, dir_e::LEFT))
			player.move(dir_e::LEFT);
		if (inputs[player.getActionKeyList()[action_e::K_RIGHT]] == true
			&& this->playerCanMove(player, dir_e::RIGHT))
			player.move(dir_e::RIGHT);
		if (inputs[player.getActionKeyList()[action_e::K_ACTION]] == true) {
			if (player.getNbBombActive() < player.getNbBomb()) {
				player.setNbBombActive(player.getNbBombActive() + 1);
				this->map.addBomb(Bomb({(float)(trunc(player.getPos().X)) + 0.5f, 0, (float)(trunc(player.getPos().Z)) + 0.5f},
							player.getFireUp(), player.getId(), this->map.newBombId()));
			}
		}
	}
	return (0);
}

/*	Manage Game Events	*/
int				Game::manageBonus(void)
{
	std::vector<int>	bonusToDestroy;
	
	for (Bomberman &player : this->map.getRealPlayers()) {
		for (Bonus bonus : this->map.getBonus()) {
			if (trunc(player.getPos().X) == trunc(bonus.getPos().X)
				&& trunc(player.getPos().Z) == trunc(bonus.getPos().Z)) {
				this->soundMachine->playSound(SoundMachine::BONUS);
				if (bonus.getType() == type_e::BOMB_UP)
					player.setNbBomb(player.getNbBomb() + 1);
				else if (bonus.getType() == type_e::SPEED_UP)
					player.setSpeed(player.getSpeed() + 0.1);
				else if (bonus.getType() == type_e::FIRE_UP)
					player.setFireUp(player.getFireUp() + 1);
				else if (bonus.getType() == type_e::WALL_PASS)
					player.canPassWall(true);
				bonusToDestroy.push_back(bonus.getId());
			}
		}
	}
	for (int id : bonusToDestroy)
		this->map.destroyBonusById(id);
	return (0);
}

int				Game::manageFire(void)
{
	std::list<int>		playerToKill;

	for (Bomberman &player : this->map.getRealPlayers()) {
		for (Fire fire : this->map.getFire()) {
			if (trunc(player.getPos().X) == trunc(fire.getPos().X)
				&& trunc(player.getPos().Z) == trunc(fire.getPos().Z)) {
				playerToKill.push_back(player.getId());
			}
		}
	}
	for (int id : playerToKill)
		this->map.destroyPlayerById(id);
	return (0);
}

bool				Game::fireContinue(pos_t origin, pos_t pos, std::string object)
{
	if (object == "Breakable") {
		this->map.destroyWall(pos);
		if (std::time(nullptr) % 3 == 0)
			this->map.addBonus(Bonus(pos, this->map.newBonusId()));
		else
			this->map.addFire(Fire(origin, pos, this->map.newFireId()));
		return (false);
	} else if (object == "Unbreakable") {
		return (false);
	} else if (object == "Bonus") {
		this->map.destroyBonus(pos);
		return (true);
	} else if (object == "") {
		this->map.addFire(Fire(origin, pos, this->map.newFireId()));
		return (true);
	}
	return (false);
}

int				Game::setFire(Bomb bomb)
{
	bool			direction[] = {true, true, true, true};
	pos_t			pos;
	std::string		object;

	this->map.addFire(Fire(bomb.getPos(), bomb.getPos(), this->map.newFireId()));
	object = this->map.checkPos(bomb.getPos());
	pos = bomb.getPos();
	this->fireContinue(bomb.getPos(), pos, object);
	for (int i = 0; i <= bomb.getRange() && direction[RIGHT]; i++) {
		pos.Z += 1;
		object = this->map.checkPos(pos);
		if (!this->fireContinue(bomb.getPos(), pos, object))
			direction[RIGHT] = false;
	}
	pos = bomb.getPos();
	for (int i = 0; i <= bomb.getRange() && direction[LEFT]; i++) {
		pos.Z -= 1;
		object = this->map.checkPos(pos);
		if (!this->fireContinue(bomb.getPos(), pos, object))
			direction[LEFT] = false;
	}
	pos = bomb.getPos();
	for (int i = 0; i <= bomb.getRange() && direction[DOWN]; i++) {
		pos.X += 1;
		object = this->map.checkPos(pos);
		if (!this->fireContinue(bomb.getPos(), pos, object))
			direction[DOWN] = false;
	}
	pos = bomb.getPos();
	for (int i = 0; i <= bomb.getRange() && direction[UP]; i++) {
		pos.X -= 1;
		object = this->map.checkPos(pos);
		if (!this->fireContinue(bomb.getPos(), pos, object))
			direction[UP] = false;
	}
	return (0);
}

int				Game::secureUnsetFire(void)
{
	bool			bombExist;
	
	for (Fire fire : this->map.getRealFire()) {
		bombExist = false;
		for (Bomb bomb : this->map.getBombs()) {
			if (fire.getOrigin().X == bomb.getPos().X && fire.getOrigin().Y == bomb.getPos().Y) {
				bombExist = true;
				break;
			}
		}
		if (!bombExist)
			this->map.destroyFireById(fire.getId());
	}
	return (0);
}

int				Game::unsetFire(Bomb bomb)
{
	for (Fire fire : this->map.getRealFire()) {
		if (fire.getOrigin().X == bomb.getPos().X 
			&& fire.getOrigin().Z == bomb.getPos().Z) {
			this->map.destroyFire(bomb.getPos());
		}
	}
	return (0);
}

int				Game::manageBombs(void)
{
	std::vector<Bomb>	bombToDrop;
	std::time_t		dropTime;

	for (Bomb &bomb : this->map.getRealBombs()) {
		dropTime = std::time(nullptr) - bomb.getDropTime();
		if (dropTime >= 3 && !bomb.isUsed()) {
			this->setFire(bomb);
			bomb.explode();
			this->soundMachine->playSound(SoundMachine::BOMB_EXPLODE);
		}
		if (dropTime >= 4) {
			this->unsetFire(bomb);
			this->secureUnsetFire();
			bombToDrop.push_back(bomb);
		}
	}
	for (Bomb bomb : bombToDrop) {
		this->map.destroyBombById(bomb.getId());
		this->map.givebackBombToPlayer(bomb.getPlayerId());
	}
	return (0);
}

bool				Game::playerAreFighting(void)
{
	int		nbAlive = 0;

	for (Bomberman player : this->map.getPlayers()) {
		nbAlive += player.isAlive();
	}
	if (nbAlive > 1)
		return (true);
	return (false);
}

/*	Save / Load the Game	*/
std::string			Game::savePlayersInfos(void)
{
	std::string		infos;

	infos = "Player : {id, pos_x, pos_z, fire, bomb, speed, wall, alive}\n";
	for (Bomberman player : this->map.getPlayers()) {
		infos += "player : {";
		infos += std::to_string(player.getId());
		infos += ",";
		infos += std::to_string(player.getPos().X);
		infos += ",";
		infos += std::to_string(player.getPos().Z);
		infos += ",";
		infos += std::to_string(player.getFireUp());
		infos += ",";
		infos += std::to_string(player.getNbBomb());
		infos += ",";
		infos += std::to_string(player.getSpeed());
		infos += ",";
		infos += std::to_string(player.canPassWall());
		infos += ",";
		infos += std::to_string(player.isAlive());
		infos += "}\n";
	}
	return (infos);
}

std::string			Game::saveWallsInfos(void)
{
	std::string		infos;

	infos = "Wall : { id, x, z, break}\n";
	for (Wall wall : this->map.getWalls()) {
		infos += "wall : {";
		infos += std::to_string(wall.getId());
		infos += ",";
		infos += std::to_string(wall.getPos().X);
		infos += ",";
		infos += std::to_string(wall.getPos().Z);
		infos += ",";
		infos += std::to_string(wall.isBreakable());
		infos += "}\n";
	}
	return (infos);
}

std::string			Game::saveBombsInfos(void)
{
	std::string		infos;

	infos = "Bombs : { id, x, z, range}\n";
	for (Bomb bomb : this->map.getBombs()) {
		infos += "bomb : {";
		infos += std::to_string(bomb.getId());
		infos += ",";
		infos += std::to_string(bomb.getPos().X);
		infos += ",";
		infos += std::to_string(bomb.getPos().Z);
		infos += ",";
		infos += std::to_string(bomb.getRange());
		infos += "}\n";
	}
	return (infos);
}

std::string			Game::saveBonusInfos(void)
{
	std::string		infos;

	infos = "Bonus : { id, x, z, range}\n";
	for (Bonus bonus : this->map.getBonus()) {
		infos += "bonus : {";
		infos += std::to_string(bonus.getId());
		infos += ",";
		infos += std::to_string(bonus.getPos().X);
		infos += ",";
		infos += std::to_string(bonus.getPos().Z);
		infos += ",";
		infos += std::to_string(bonus.getType());
		infos += "}\n";
	}
	return (infos);
}

std::vector<float>		Game::getInfosFromLine(std::string line)
{
	std::vector<float>	infos;
	size_t			from = line.find("{") + 1;
	size_t			to = line.find(",", from);

	do {
		infos.push_back(atoi(line.substr(from, to - from).c_str()));
		from = to + 1;
		to = line.find(",", from);
	} while (to <= line.rfind(","));
	infos.push_back(atof(line.substr(from, 1).c_str()));
	return (infos);
}

int				Game::createPlayerFromFile(std::string line)
{
	std::vector<float>	infos = this->getInfosFromLine(line);
	int			i = 1;
	
	for (struct playerConfig *playerConfig : this->playerConfigList) {
		if (infos[0] == i) {
			this->map.addPlayer(Bomberman(infos[0], *playerConfig,
				{infos[1] + HALF_CASE, 0, infos[2] + HALF_CASE}, infos[3],
				infos[4], DEFAULT_SPEED, infos[6], infos[7]));
			return (0);
		}
		i += 1;
	}
	return (0);
}

int				Game::createWallFromFile(std::string line)
{
	std::vector<float>	infos = this->getInfosFromLine(line);

	this->map.addWall(Wall(infos[0], {infos[1], 0, infos[2]}, infos[3]));
	return (0);
}

int				Game::createBombFromFile(std::string line)
{
	std::vector<float>	infos = this->getInfosFromLine(line);

	this->map.addBomb(Bomb(infos[0], {infos[1] + HALF_CASE, 0, infos[2] + HALF_CASE}, infos[3]));
	return (0);
}

int				Game::createBonusFromFile(std::string line)
{
	std::vector<float>	infos = this->getInfosFromLine(line);

	this->map.addBonus(Bonus(infos[0], {infos[1] + HALF_CASE, 0, infos[2] + HALF_CASE}, infos[3]));
	return (0);
}
