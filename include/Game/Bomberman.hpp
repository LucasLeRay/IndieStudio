/*
** Bomberman.hpp
*/

#ifndef BOMBERMAN_HPP_
# define BOMBERMAN_HPP_

# include "IBomberman.hpp"
# include "IObject.hpp"

/*	Class Bomberman		*/
class				Bomberman : public IBomberman {
private:
	ActionKeyList		actionKeyList;
	Graphics::typeObj	type;
	animation		state;
	dir_e			dir;
	pos_t			pos;
	float			speed;
	int			nbBombActive;
	int			nbBomb;
	int			fireUp;
	int			id;
	bool			passWall;
	bool			alive;
	bool			ai;
public:
	/*	Constructor	*/
	Bomberman(int id, playerConfig config, pos_t pos);
	Bomberman(int id, playerConfig config, pos_t pos, int bonus, int bomb, float speed, bool wall, bool alive);
	~Bomberman(void) = default;
	/*	Action		*/
	void			move(dir_e dir) override;
	/*	Getter		*/
	ActionKeyList		getActionKeyList(void) override;
	Graphics::typeObj	getType(void) override;
	animation		getState(void) override;
	dir_e			getDir(void) override;
	pos_t			getPos(void) override;
	float			getSpeed(void) override;
	int			getNbBombActive(void) override;
	int			getNbBomb(void) override;
	int			getFireUp(void) override;
	int			getId(void) override;
	bool			canPassWall(void) override;
	bool			isAlive(void) override;
	bool			isAi(void) override;
	/*	Setter		*/
	void			setState(animation anim) override;
	void			setPos(pos_t pos) override;
	void			setSpeed(float speed) override;
	void			setNbBombActive(int nbBombActive) override;
	void			setNbBomb(int nbBomb) override;
	void			setFireUp(int fireRange) override;
	void			canPassWall(bool passWall) override;
	void			isAlive(bool alive) override;
};

#endif /* !BOMBERMAN_HPP_ */
