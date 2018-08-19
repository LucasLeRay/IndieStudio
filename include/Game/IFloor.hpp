/*
** IFloor.hpp
*/

#ifndef IFLOOR_HPP_
# define IFLOOR_HPP_

# include "IObject.hpp"

/*	Interface		*/
class				IFloor : public IObject {
public:
	/*	Constructor	*/
	virtual ~IFloor(void) = default;
	/*	Action		*/
	/*	Getter		*/
	virtual pos_t		getPos(void) = 0;
	virtual int		getId(void) = 0;
	/*	Setter		*/
};

#endif /* !IFLOOR_HPP_ */