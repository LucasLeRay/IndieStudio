/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_GRAPH_HPP
#define CPP_INDIE_STUDIO_GRAPH_HPP

#include "irrlicht.h"
#include "indie.hpp"

#define SCREEN_HEIGHT	(this->graph->getScreenHeight())
#define SCREEN_WIDTH	(this->graph->getScreenWidth())
#define BITPIXEL	32
#define FULLSCREEN	false
#define CAPTION_NAME	L"Indie BomberTek"

class Assets2DHandler;
class Assets3DHandler;
class HandleInput;

class   Graphics
{
public:

	enum typeMesh
	{
		CHARA1_IDLE,
		CHARA1_WALK,
		CHARA2_IDLE,
		CHARA2_WALK,
		CHARA3_IDLE,
		CHARA3_WALK,
		CHARA4_IDLE,
		CHARA4_WALK,
		CRASH_IDLE,
		CRASH_WALK,
		DEADPOOL_IDLE,
		DEADPOOL_WALK,
		IMPA_IDLE,
		IMPA_WALK,
		IRONMAN_IDLE,
		IRONMAN_WALK,
		MICKEY_IDLE,
		MICKEY_WALK,
		LITTLEMAC_IDLE,
		LITTLEMAC_WALK,
		SNAKE_IDLE,
		SNAKE_WALK,
		WALL_M,
		BOX_M,
		GROUND_M,
		BOMB_M
	};

	enum typeTexture
	{
		PAUSE_BACKGROUND,
		PAUSE_TITLE,
		WINNER_TITLE,
		MENU_BACKGROUND,
		MENU_TITLE,
		CHARA1_DIFFUSE,
		CHARA2_DIFFUSE,
		CHARA3_DIFFUSE,
		CHARA4_DIFFUSE,
		CRASH_T,
		DEADPOOL_T,
		IMPA_T,
		IRONMAN_T,
		MICKEY_T,
		LITTLEMAC_T,
		SNAKE_1,
		SNAKE_2,
		SNAKE_3,
		SNAKE_4,
		INPUT_CONTROLLER1,
		INPUT_CONTROLLER2,
		INPUT_OKLM,
		INPUT_ZQSD,
		PLAYER_BACK1,
		PLAYER_BACK2,
		PLAYER_BACK3,
		PLAYER_BACK4,
		PLAYER_NAME_JOUEUR,
		PLAYER_NAME_ORDI,
		PLAYER_NAME_SANS,
		SELECT_LEFT,
		SELECT_RIGHT,
		BUTTON_PLAY_DEF,
		BUTTON_PLAY_PRESSED,
		BUTTON_OPTIONS_DEF,
		BUTTON_OPTIONS_PRESSED,
		BUTTON_CREDITS_DEF,
		BUTTON_CREDITS_PRESSED,
		BUTTON_QUIT_DEF,
		BUTTON_QUIT_PRESSED,
		BUTTON_BACK_DEF,
		BUTTON_BACK_PRESSED,
		BUTTON_GO_DEF,
		BUTTON_GO_PRESSED,
		BUTTON_SAVE_DEF,
		BUTTON_SAVE_PRESSED,
		BUTTON_LOAD_DEF,
		BUTTON_LOAD_PRESSED,
		WALL_T,
		BOX_T,
		GROUND1_T,
		GROUND2_T,
		GROUND3_T,
		BOMB_T,
		FIRE_T,
		BONUS_T,
		BONUS2_T,
		BONUS3_T,
		BONUS4_T,
		CREDITS_LOGO,
		CREDITS_DEV
	};

	enum typeObj
	{
		CHARA1,
		CHARA2,
		CHARA3,
		CHARA4,
		CRASH,
		DEADPOOL,
		IMPA,
		IRONMAN,
		MICKEY,
		LITTLEMAC,
		SNAKE,
		BOMB,
		BOX,
		BONUS,
		FIRE,
		FLOOR,
		FLOOR2,
		DESTRWALL,
		WALL
	};

	Graphics(HandleInput *input);

	~Graphics();

	HandleInput				*getInput();

	void					beginScene();

	void					endScene();

	bool					isDeviceRunning();

	bool					isWindowActive();

	bool					isReloadScreen();

	void					setReloadScreen(bool reloadScreen);

	int					getScreenHeight();

	int					getScreenWidth();

	void					addCamera(irr::core::vector3df pos, irr::core::vector3df lookat);

	irr::video::ITexture			*getTextureByType(Graphics::typeTexture typeTexture);

	Assets3DHandler				*getAsset3DHandler();

	Assets2DHandler				*getAsset2DHandler();

	void					drawAll();

	irr::scene::IParticleSystemSceneNode	*createParticleSystem(bool test);

	void					addLight(irr::core::vector3df pos, irr::video::SColorf color, float radius);

	void					activateJoystick(irr::core::array<irr::SJoystickInfo> joystickInfo);

private:

	void					fillTextures();

	void					fillMeshs();

	bool						reloadScreen;
	HandleInput					*input;
	Assets3DHandler					*asset3D;
	Assets2DHandler					*asset2D;
	std::map<typeTexture, irr::video::ITexture*>	textures;
	std::map<typeMesh, irr::scene::IAnimatedMesh*>	mesh;
	irr::IrrlichtDevice				*device;
	irr::video::IVideoDriver			*driver;
	irr::scene::ISceneManager			*smgr;
	irr::scene::IParticleSystemSceneNode		*particleSystem;
};


#endif //CPP_INDIE_STUDIO_GRAPH_HPP
