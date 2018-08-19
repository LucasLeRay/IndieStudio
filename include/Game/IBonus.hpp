/*
** IBonus.hpp
*/

#ifndef IBONUS_HPP_
# define IBONUS_HPP_

# include "IObject.hpp"
# include "Bomberman.hpp"

/*	Interface	*/
class			IBonus : public IObject {
public:
	/*	Constructor	*/
	virtual ~IBonus(void) = default;
	/*	Constructor	*/
	/*	Action		*/
	virtual int		applyEffect(Bomberman &player) = 0;
	/*	Getter		*/
	virtual type_e		getType(void) = 0;
	virtual	pos_t		getPos(void) = 0;
	virtual int		getId(void) = 0;
	/*	Setter		*/
};

#endif /* !IBONUS_HPP_ */