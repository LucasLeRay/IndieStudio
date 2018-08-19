//
// Created by yulirev on 03/06/18.
//

#ifndef CPP_INDIE_STUDIO_PLAYERSELECT_HPP
#define CPP_INDIE_STUDIO_PLAYERSELECT_HPP

#include "Graphics.hpp"
#include "HandleInput.hpp"
#include <vector>

#define SELECT_HEIGHT (this->graph->getTextureByType(Graphics::PLAYER_BACK1)->getSize().Height)
#define SELECT_WIDTH (this->graph->getTextureByType(Graphics::PLAYER_BACK1)->getSize().Width)
#define SELECT_POS_X ((SCREEN_WIDTH / 2) - (SELECT_WIDTH * 2) - 200 + ((SELECT_WIDTH + 100) * this->pos) + 50)
#define SELECT_POS_Y ((this->graph->getScreenHeight() / 2) - (this->graph->getTextureByType(Graphics::PLAYER_BACK1)->getSize().Height))

class PlayerSelect
{
	public:

	enum                            PlayerType {
		J1,
		J2,
		J3,
		J4,
		IA,
		NO_PLAYER
	};

	PlayerSelect(int pos, Graphics *graph, HandleInput *inputs);

	~PlayerSelect();

	void                            handleEvent(void);

	void                            deleteModel();

	PlayerType                      getPlayerType();

	unsigned                        getModelChoosing();

	private:

	void				createAssetInput(void);

	void				createAssetBackground(void);

	void				createAssetPlayer(void);

	void                            createAssetButtons();

	void                            createAssets(void);

	bool                            changeParam(unsigned);

	void                            deleteAssetList();

	Graphics                        *graph;

	HandleInput                     *inputs;

	int                             pos;

	std::list<unsigned>             asset2DIdList;

	PlayerType                      playerType;

	unsigned                        modelChara = -1;

	unsigned                        modelChoosing;
};


#endif //CPP_INDIE_STUDIO_PLAYERSELECT_HPP
