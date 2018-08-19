/*
** Floor.hpp
*/

#ifndef FLOOR_HPP_
# define FLOOR_HPP_

# include "IFloor.hpp"

/*	Class Floor		*/
class				Floor : public IFloor {
private:
	pos_t			pos;
	int			id;
public:
	/*	Constructor	*/
	Floor(pos_t pos);
	~Floor(void) = default;
	/*	Action		*/
	/*	Getter		*/
	pos_t			getPos(void) override;
	int			getId(void) override;
	/*	Setter		*/
};

#endif /* !FLOOR_HPP_ */