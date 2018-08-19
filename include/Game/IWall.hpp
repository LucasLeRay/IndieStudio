/*
** IWall.hpp
*/

#ifndef IWALL_HPP_
# define IWALL_HPP_

# include "IObject.hpp"

/*	Interface	*/
class			IWall : public IObject {
public:
	/*	Constructor	*/
	virtual ~IWall(void) = default;
	/*	Action		*/
	/*	Getter		*/
	virtual pos_t	getPos(void) = 0;
	virtual int	getId(void) = 0;
	virtual bool	isBreakable(void) = 0;
	/*	Setter		*/
};

#endif /* !IWALL_HPP_ */