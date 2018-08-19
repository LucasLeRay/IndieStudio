/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_GRAPHICSGAME_HPP
#define CPP_INDIE_STUDIO_GRAPHICSGAME_HPP

#include "Settings.hpp"
#include "Graphics.hpp"
#include "Game.hpp"
#include "SoundMachine.hpp"

class IObject;
class Button;
class Bomberman;

#define UNIT_MODEL 40

struct BombPosModel {
	unsigned		idModel;
	unsigned                idBomb;
};

struct FirePosModel {
	irr::scene::IParticleSystemSceneNode	*particleSystem;
	unsigned				id;
};

struct BonusPosModel {
	irr::scene::IParticleSystemSceneNode	*particleSystem;
	unsigned				id;
};

struct BoxPosModel {
	unsigned	idModel;
	unsigned	idBox;
};

struct PlayerPosModel {
	unsigned	idModel;
	unsigned	idPlayer;
};

class GraphicsGame
{
public:

	GraphicsGame(Graphics *graph, Settings *settings, Game *game, SoundMachine *soundMachine, HandleInput *input);

	~GraphicsGame();

	void		createAll();

	void            display();

	void		displayPause();

	void		setGame(Game *game);

	void		destroyAll();

	Graphics        *getGraphics() const;

	Settings        *getSetting() const;

	void		createWin();

	unsigned	getWinnerTitleId();

private:

	void		displayObject();

	void		destroyAllParticles();

	void            createFloor();

	void            createBomb();

	void            createBonus();

	void		updateBonus();

	void		updateFire();

	void            createFire();

	void            createPlayer();

	void            createWall();

	void		changeAnimPlayer(Bomberman bomberman, PlayerPosModel *player);

	void            updatePlayer();

	void            updateBomb();

	bool		bombExist(unsigned id);

	bool		fireExist(unsigned id);

	bool		bonusExist(unsigned id);

	void		updateBox();

	Graphics                        *graph;
	Settings                        *settings;
	Game		                *game;
	SoundMachine			*soundMachine;
	HandleInput			*input;
	std::list<PlayerPosModel *> 	playerInList;
	std::list<BombPosModel *>    	bombInList;
	std::list<FirePosModel *>    	fireInList;
	std::list<BoxPosModel *>	boxInList;
	std::list<BonusPosModel *>    	bonusInList;
	std::list<unsigned>             idWallList;
	std::list<unsigned>             idFloorList;
	unsigned			pauseBackgroundId;
	unsigned			pauseTitleId;
	unsigned			winnerTitleId;
	Button				*saveButton;
	Button				*loadButton;
};

#endif //CPP_INDIE_STUDIO_GRAPHICSGAME_HPP
