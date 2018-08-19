/*
** IBomb.hpp
*/

#ifndef IBOMB_HPP_
# define IBOMB_HPP_

# include "IObject.hpp"

/*	Interface		*/
class				IBomb : public IObject  {
public:
	/*	Constructor	*/
	virtual ~IBomb(void) = default;
	/*	Action		*/
	virtual	void		explode(void) = 0;
	/*	Getter		*/
	virtual std::time_t	getDropTime(void) = 0;
	virtual	pos_t		getPos(void) = 0;
	virtual	int		getRange(void) = 0;
	virtual	int		getPlayerId(void) = 0;
	virtual bool		isUsed(void) = 0;
	virtual int		getId(void) = 0;
	/*	Setter		*/
	virtual	void		setPos(pos_t pos) = 0;
	virtual	void		setRange(int range) = 0;
};

#endif /* !IBOMB_HPP_ */