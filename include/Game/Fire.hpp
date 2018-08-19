/*
** Fire.hpp
*/

#ifndef FIRE_HPP_
# define FIRE_HPP_

# include "IFire.hpp"

/*	Class Fire		*/
class				Fire : public IFire {
private:
	pos_t			origin;
	pos_t			pos;
	int			id;
public:
	/*	Constructor	*/
	Fire(pos_t origin, pos_t pos, int id);
	~Fire(void) = default;
	/*	Action		*/
	/*	Getter		*/
	pos_t			getOrigin(void) override;
	pos_t			getPos(void) override;
	int			getId(void) override;
	/*	Setter		*/
};

#endif /* !FIRE_HPP_ */