/*
** IBomberman.hpp
*/

#ifndef IBOMBERMAN_HPP_
# define IBOMBERMAN_HPP_

# include "IObject.hpp"
# include "Graphics.hpp"
# include "Assets3DHandler.hpp"

/*	Interface		*/
class					IBomberman : public IObject {
public:
	/*	Constructor	*/
	virtual ~IBomberman(void) = default;
	/*	Action		*/
	virtual void			move(dir_e dir) = 0;
	/*	Getter		*/
	virtual ActionKeyList		getActionKeyList(void) = 0;
	virtual Graphics::typeObj	getType(void) = 0;
	virtual animation		getState(void) = 0;
	virtual dir_e			getDir(void) = 0;
	virtual pos_t			getPos(void) = 0;
	virtual float			getSpeed(void) = 0;
	virtual	int			getNbBombActive(void) = 0;
	virtual	int			getNbBomb(void) = 0;
	virtual	int			getFireUp(void) = 0;
	virtual int			getId(void) = 0;
	virtual	bool			canPassWall(void) = 0;
	virtual bool			isAlive(void) = 0;
	virtual bool			isAi(void) = 0;
	/*	Setter		*/
	virtual void			setState(animation anim) = 0;
	virtual void			setPos(pos_t pos) = 0;
	virtual void			setSpeed(float speed) = 0;
	virtual	void			setNbBombActive(int nbBombActive) = 0;
	virtual	void			setNbBomb(int nbBomb) = 0;
	virtual	void			setFireUp(int bonusFireRange) = 0;
	virtual	void			canPassWall(bool passWall) = 0;
	virtual void			isAlive(bool alive) = 0;
};

#endif /* !IBOMBERMAN_HPP_ */