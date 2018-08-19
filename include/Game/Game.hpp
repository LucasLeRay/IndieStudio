/*
** Game.hpp
*/

#ifndef GAME_HPP_
# define GAME_HPP_

# include "IGame.hpp"
# include "IObject.hpp"
# include "AutoPlayer.hpp"
# include "HandleInput.hpp"
# include "Settings.hpp"
# include "Map.hpp"
# include "SoundMachine.hpp"

/*	Class Game			*/
class				Game : public IGame {
private:
	SoundMachine		*soundMachine;
	PlayerConfigList	playerConfigList;
	HandleInput		*handleInput;
	Map			map;
	AutoPlayer		autoPlayer;
	int			nbPlayer;
	bool			gameEnd;
public:
	/*	Constructor		*/
	Game(PlayerConfigList playerConfigList, HandleInput *handleInput, SoundMachine *soundMachine);
	~Game(void) = default;
	/*	Action			*/
	int			startGame(void) override;
	int			saveGame(void) override;
	int			loadGame(void) override;
	/*	Getter			*/
	PlayerConfigList	getPlayerConfigList(void) override;
	HandleInput		*getHandleInput(void);
	Map			getMap(void) override;
	int			getNbPlayer(void) override;
	bool			getGameEnd(void) override;
	/*	Setter			*/
	void			setNbPlayer(int nbPlayer) override;
private:
	/*	Manage AutoPlayer	*/
	int			manageAutoPlayers(void);
	/*	Manage Inputs		*/
	bool			noWallBlock(Bomberman player, dir_e dir);
	bool			noBombBlock(Bomberman player, dir_e dir);
	bool			playerCanMove(Bomberman player, dir_e dir);
	int			manageInputs(void);
	/*	Manage Game Events	*/
	int			manageBonus(void);
	int			manageFire(void);
	bool			fireContinue(pos_t origin, pos_t pos, std::string object);
	int			setFire(Bomb bomb);
	int			secureUnsetFire(void);
	int			unsetFire(Bomb bomb);
	int			manageBombs(void);
	bool			playerAreFighting(void);
	/*	Save / Load the Game	*/
	std::string		savePlayersInfos(void);
	std::string		saveWallsInfos(void);
	std::string		saveBombsInfos(void);
	std::string		saveBonusInfos(void);
	std::vector<float>	getInfosFromLine(std::string line);
	int			createPlayerFromFile(std::string line);
	int			createWallFromFile(std::string line);
	int			createBombFromFile(std::string line);
	int			createBonusFromFile(std::string line);
};

#endif /* !GAME_HPP_ */
