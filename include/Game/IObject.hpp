/*
** IObject.hpp
*/

#ifndef IOBJECT_HPP_
# define IOBJECT_HPP_

# include "indie.hpp"
# include "irrlicht.h"
# include "Settings.hpp"

/*	macros			*/
/*	default values		*/
# define DEFAULT_NB_BOMB_ACTIVE	0
# define DEFAULT_NB_BOMB	1
# define DEFAULT_FIRE_UP	0
# define DEFAULT_SPEED		0.2
# define DEFAULT_WALLPASS	false
# define DEFAULT_ALIVE		true
# define DEFAULT_BOMB_RANGE	range + 2
# define DEFAULT_BOMB_USED	false
# define NO_ID			0
# define NO_POS_X		-1
# define NO_POS_Z		-1

/*	default positions	*/
# define UP_LEFT_X		1.5f
# define UP_LEFT_Y		0
# define UP_LEFT_Z		static_cast<float>(this->map.getSize()) - 0.5f

# define UP_RIGHT_X		static_cast<float>(this->map.getSize()) - 0.5f
# define UP_RIGHT_Y		0
# define UP_RIGHT_Z		static_cast<float>(this->map.getSize()) - 0.5f

# define DOWN_LEFT_X		1.5f
# define DOWN_LEFT_Y		0
# define DOWN_LEFT_Z		1.5f

# define DOWN_RIGHT_X		static_cast<float>(this->map.getSize()) - 0.5f
# define DOWN_RIGHT_Y		0
# define DOWN_RIGHT_Z		1.5f


/*	Map Related Infos	*/
# define MAP_SIZE		15
# define UP_LEFT_CORNER		(i == 1 && j == this->size - 1) || (i == 2 && j == this->size - 1) || (i == 1 && j == this->size - 2)
# define UP_RIGHT_CORNER	(i == this->size - 1 && j == this->size - 1) || (i == this->size - 2 && j == this->size - 1) || (i == this->size - 1 && j == this->size - 2)
# define DOWN_LEFT_CORNER	(i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 1 && j == 3) || (i == 3 && j == 1)
# define DOWN_RIGHT_CORNER	(i == this->size - 1 && j == 1) || (i == this->size - 1 && j == 2) || (i == this->size - 2 && j == 1)

/*	others			*/
# define CONFIG_FILE		".map.conf"
# define HALF_CASE		0.5f

/*	typedef			*/
typedef std::map<action_e, std::string>		ActionKeyList;
typedef irr::core::vector3d<float>		pos_t;

/*	enumeration		*/
enum		dir_e {
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

enum		type_e {
	BOMB_UP = 0,
	SPEED_UP = 1,
	FIRE_UP = 2,
	WALL_PASS = 3
};

/*	Interface		*/
class				IObject {
public:
	/*	Constructor	*/
	virtual ~IObject(void) = default;
	/*	Getter		*/
	virtual pos_t		getPos(void) = 0;
	virtual int		getId(void) = 0;
	/*	Setter		*/
};

/*	Overload		*/
/*
bool		operator==(pos_t left, pos_t right)
{
	if (left.X == right.X && left.Y == right.Y)
		return (true);
	return (false);
}
*/

#endif /* !IOBJECT_HPP_ */