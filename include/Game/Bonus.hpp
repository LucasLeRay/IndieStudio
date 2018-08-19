/*
** Bonus.hpp
*/

#ifndef BONUS_HPP_
# define BONUS_HPP_

# include "IBonus.hpp"
# include "Bomberman.hpp"

/*	Class Bonus	*/
class			Bonus : public IBonus {
private:
	type_e		type;
	pos_t		pos;
	int		id;
public:
	/*	Constructor	*/
	Bonus(pos_t pos, int id);
	Bonus(int id, pos_t pos, int type);
	~Bonus(void) = default;
	/*	Action		*/
	int		applyEffect(Bomberman &player) override;
	/*	Getter		*/
	type_e		getType(void) override;
	pos_t		getPos(void) override;
	int		getId(void) override;
	/*	Setter		*/
};

#endif /* !BONUS_HPP_ */