/*
** Bomb.hpp
*/

#ifndef BOMB_HPP_
# define BOMB_HPP_

# include "IBomb.hpp"
# include "indie.hpp"

/*	Interface	*/
class			Bomb : public IBomb {
private:
	std::time_t	dropTime;
	pos_t		pos;
	int		playerId;
	int		range;
	int		id;
	bool		used;
public:
	/*	Constructor	*/
	Bomb(pos_t pos, int range, int playerId, int id);
	Bomb(int id, pos_t pos, int range);
	~Bomb(void) = default;
	/*	Action		*/
	void		explode(void) override;
	/*	Getter		*/
	std::time_t	getDropTime(void) override;
	pos_t		getPos(void) override;
	int		getRange(void) override;
	int		getPlayerId(void) override;
	int		getId(void) override;
	bool		isUsed(void) override;
	/*	Setter		*/
	void		setPos(pos_t pos) override;
	void		setRange(int range) override;
};

#endif /* !BOMB_HPP_ */
