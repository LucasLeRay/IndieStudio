/*
** Map.hpp
*/

#ifndef MAP_HPP_
# define MAP_HPP_

# include "IMap.hpp"
# include "Bomberman.hpp"
# include "Bonus.hpp"
# include "Wall.hpp"
# include "Bomb.hpp"
# include "Fire.hpp"
# include "Floor.hpp"

/*	Class Map		*/
class				Map : public IMap {
private:
	std::vector<Bomberman>	players;
	std::vector<Wall>	walls;
	std::vector<Bomb>	bombs;
	std::vector<Bonus>	bonus;
	std::vector<Fire>	fire;
	std::vector<Floor>	floors;
	pos_t			pos;
	int			size;
	int			id;
public:
	/*	Constructor	*/
	Map(void);
	~Map(void) = default;
	/*	Action		*/
	int 			addPlayer(Bomberman player) override;
	int 			addWall(Wall wall) override;
	int			addBomb(Bomb bomb) override;
	int			addBonus(Bonus bonus) override;
	int			addFire(Fire fire) override;
	int			addFloor(Floor floor) override;
	int			destroyPlayer(pos_t pos) override;
	int			destroyWall(pos_t pos) override;
	int			destroyBomb(pos_t pos) override;
	int			destroyBonus(pos_t pos) override;
	int			destroyFire(pos_t origin) override;
	int			destroyPlayerById(int id) override;
	int			destroyWallById(int id) override;
	int			destroyBombById(int id) override;
	int			destroyBonusById(int id) override;
	int			destroyFireById(int id) override;
	int			removePlayers(void) override;
	int			removeWalls(void) override;
	std::vector<Bomberman>	&getRealPlayers(void) override;
	std::vector<Wall>	&getRealWalls(void) override;
	std::vector<Bomb>	&getRealBombs(void) override;
	std::vector<Fire>	&getRealFire(void) override;
	std::string		checkPos(pos_t pos) override;
	void			displayMap(void) override;
	int			newWallId(void) override;
	int			newBombId(void) override;
	int			newBonusId(void) override;
	int			newFireId(void) override;
	int			givebackBombToPlayer(int id) override;
	/*	Getter		*/
	std::vector<Bomberman>	getPlayers(void) override;
	std::vector<Wall>	getWalls(void) override;
	std::vector<Bomb>	getBombs(void) override;
	std::vector<Bonus>	getBonus(void) override;
	std::vector<Fire>	getFire(void) override;
	std::vector<Floor>	getFloors(void) override;
	pos_t			getPos(void) override;
	int			getSize(void) override;
	int			getId(void) override;
	/*	Setter		*/
private:
	/*	Generation	*/
	void			borderWall(void);
	void			mapPattern(int nb);
	void			fillMap(void);
	void			generate(void);
};

#endif /* !MAP_HPP_ */