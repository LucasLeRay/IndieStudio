/*
** Wall.hpp
*/

#ifndef WALL_HPP_
# define WALL_HPP_

# include "IObject.hpp"
# include "IWall.hpp"

/*	Class Wall		*/
class			Wall : public IWall {
private:
	pos_t		pos;
	int		id;
	bool		breakable;
public:
	/*	Constructor	*/
	Wall(pos_t pos, int id, bool breakable);
	Wall(int id, pos_t pos, bool breakable);
	~Wall(void) = default;
	/*	Action		*/
	/*	Getter		*/
	pos_t		getPos(void) override;
	int		getId(void) override;
	bool		isBreakable(void) override;
	/*	Setter		*/
};

#endif /* !WALL_HPP_ */