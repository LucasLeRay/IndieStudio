/*
** IFire.hpp
*/

#ifndef IFIRE_HPP_
# define IFIRE_HPP_

# include "IObject.hpp"

/*	Interface		*/
class				IFire : public IObject {
public:
	/*	Constructor	*/
	virtual ~IFire(void) = default;
	/*	Action		*/
	/*	Getter		*/
	virtual pos_t		getOrigin(void) = 0;
	virtual pos_t		getPos(void) = 0;
	virtual int		getId(void) = 0;
	/*	Setter		*/
};

#endif /* !IFIRE_HPP_ */