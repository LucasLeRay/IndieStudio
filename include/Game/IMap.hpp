/*
** IMap.hpp
*/

#ifndef IMAP_HPP_
# define IMAP_HPP_

# include "IObject.hpp"
# include "Bomberman.hpp"
# include "Bonus.hpp"
# include "Wall.hpp"
# include "Bomb.hpp"
# include "Fire.hpp"
# include "Floor.hpp"

/*	Interface		*/
class					IMap : public IObject {
public:
	/*	Constructor	*/
	virtual ~IMap(void) = default;
	/*	Action		*/
	virtual int			addPlayer(Bomberman player) = 0;
	virtual int			addWall(Wall wall) = 0;
	virtual int			addBomb(Bomb bomb) = 0;
	virtual int			addBonus(Bonus bonus) = 0;
	virtual int			addFire(Fire fire) = 0;
	virtual int			addFloor(Floor floor) = 0;
	virtual int			destroyPlayer(pos_t pos) = 0;
	virtual int			destroyWall(pos_t pos) = 0;
	virtual int			destroyBomb(pos_t pos) = 0;
	virtual int			destroyBonus(pos_t pos) = 0;
	virtual int			destroyFire(pos_t origin) = 0;
	virtual int			destroyPlayerById(int id) = 0;
	virtual int			destroyWallById(int id) = 0;
	virtual int			destroyBombById(int id) = 0;
	virtual int			destroyBonusById(int id) = 0;
	virtual int			destroyFireById(int id) = 0;
	virtual int			removePlayers(void) = 0;
	virtual int			removeWalls(void) = 0;
	virtual std::vector<Bomberman>	&getRealPlayers(void) = 0;
	virtual std::vector<Wall>	&getRealWalls(void) = 0;
	virtual std::vector<Bomb>	&getRealBombs(void) = 0;
	virtual std::vector<Fire>	&getRealFire(void) = 0;
	virtual std::string		checkPos(pos_t pos) = 0;
	virtual void			displayMap(void) = 0;
	virtual int			newWallId(void) = 0;
	virtual int			newBombId(void) = 0;
	virtual int			newBonusId(void) = 0;
	virtual int			newFireId(void) = 0;
	virtual int			givebackBombToPlayer(int id) = 0;
	/*	Getter		*/
	virtual std::vector<Bomberman>	getPlayers(void) = 0;
	virtual std::vector<Wall>	getWalls(void) = 0;
	virtual std::vector<Bomb>	getBombs(void) = 0;
	virtual std::vector<Bonus>	getBonus(void) = 0;
	virtual std::vector<Fire>	getFire(void) = 0;
	virtual std::vector<Floor>	getFloors(void) = 0;
	virtual	pos_t			getPos(void) = 0;
	virtual int			getSize(void) = 0;
	virtual int			getId(void) = 0;
	/*	Setter		*/
};

#endif /* !IMAP_HPP_ */