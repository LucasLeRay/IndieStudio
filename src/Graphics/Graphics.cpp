/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "Graphics.hpp"
#include "HandleInput.hpp"
#include "Settings.hpp"
#include "Assets2DHandler.hpp"
#include "Assets3DHandler.hpp"

Graphics::Graphics(HandleInput *receiver)
{
	this->device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(Settings::defaultScreenWidth,
		Settings::defaultScreenHeight), BITPIXEL, FULLSCREEN, true, true, receiver);
	this->driver = device->getVideoDriver();
	this->smgr = device->getSceneManager();
	device->setWindowCaption(CAPTION_NAME);
	this->fillTextures();
	this->fillMeshs();
	this->reloadScreen = true;
	this->input = receiver;
	this->asset2D = new Assets2DHandler(this->textures, this->driver);
	this->asset3D = new Assets3DHandler(this->smgr, this->textures, this->mesh);
}

Graphics::~Graphics()
{
        this->driver->drop();
}

HandleInput*	Graphics::getInput()
{
	return (this->input);
}

void	Graphics::fillMeshs()
{
	this->mesh[Graphics::CHARA1_IDLE] = this->smgr->getMesh("assets/models/Chara1/chara1_idle.MD3");
	this->mesh[Graphics::CHARA1_WALK] = this->smgr->getMesh("assets/models/Chara1/chara1_walk.MD3");
	this->mesh[Graphics::CHARA2_IDLE] = this->smgr->getMesh("assets/models/Chara2/chara2_idle.MD3");
	this->mesh[Graphics::CHARA2_WALK] = this->smgr->getMesh("assets/models/Chara2/chara2_walk.MD3");
	this->mesh[Graphics::CHARA3_IDLE] = this->smgr->getMesh("assets/models/Chara3/chara3_idle.MD3");
	this->mesh[Graphics::CHARA3_WALK] = this->smgr->getMesh("assets/models/Chara3/chara3_walk.MD3");
	this->mesh[Graphics::CHARA4_IDLE] = this->smgr->getMesh("assets/models/Chara4/chara4_idle.MD3");
	this->mesh[Graphics::CHARA4_WALK] = this->smgr->getMesh("assets/models/Chara4/chara4_walk.MD3");
	this->mesh[Graphics::CRASH_IDLE] = this->smgr->getMesh("assets/models/Crash/Crash_idle.MD3");
	this->mesh[Graphics::CRASH_WALK] = this->smgr->getMesh("assets/models/Crash/Crash_run.MD3");
	this->mesh[Graphics::DEADPOOL_IDLE] = this->smgr->getMesh("assets/models/Deadpool/Deadpool_idle.MD3");
	this->mesh[Graphics::DEADPOOL_WALK] = this->smgr->getMesh("assets/models/Deadpool/Deadpool_run.MD3");
	this->mesh[Graphics::IMPA_IDLE] = this->smgr->getMesh("assets/models/Impa/Impa_idle.MD3");
	this->mesh[Graphics::IMPA_WALK] = this->smgr->getMesh("assets/models/Impa/Impa_run.MD3");
	this->mesh[Graphics::IRONMAN_IDLE] = this->smgr->getMesh("assets/models/Iron-man/Iron-man_idle.MD3");
	this->mesh[Graphics::IRONMAN_WALK] = this->smgr->getMesh("assets/models/Iron-man/Iron-man_run.MD3");
	this->mesh[Graphics::MICKEY_IDLE] = this->smgr->getMesh("assets/models/Mickey/Mickey_idle.MD3");
	this->mesh[Graphics::MICKEY_WALK] = this->smgr->getMesh("assets/models/Mickey/Mickey_run.MD3");
	this->mesh[Graphics::LITTLEMAC_IDLE] = this->smgr->getMesh("assets/models/Little-mac/Little-mac_idle.MD3");
	this->mesh[Graphics::LITTLEMAC_WALK] = this->smgr->getMesh("assets/models/Little-mac/Little-mac_run.MD3");
	this->mesh[Graphics::SNAKE_IDLE] = this->smgr->getMesh("assets/models/Snake/Snake_idle.MD3");
	this->mesh[Graphics::SNAKE_WALK] = this->smgr->getMesh("assets/models/Snake/Snake_run.MD3");
	this->mesh[Graphics::typeMesh::BOX_M] = this->smgr->getMesh("assets/models/Object/box.MD3");
	this->mesh[Graphics::typeMesh::WALL_M] = this->smgr->getMesh("assets/models/Object/mur.MD3");
	this->mesh[Graphics::typeMesh::GROUND_M] = this->smgr->getMesh("assets/models/Object/sol.MD3");
	this->mesh[Graphics::typeMesh::BOMB_M] = this->smgr->getMesh("assets/models/Object/Bomb.MD3");

}

void	Graphics::fillTextures()
{
	this->textures[Graphics::typeTexture::CHARA1_DIFFUSE] = this->driver->getTexture("assets/models/Chara1/chara1_diffuse.jpg");
	this->textures[Graphics::typeTexture::CHARA2_DIFFUSE] = this->driver->getTexture("assets/models/Chara2/chara2_diffuse.jpg");
	this->textures[Graphics::typeTexture::CHARA3_DIFFUSE] = this->driver->getTexture("assets/models/Chara3/chara3_diffuse.jpg");
	this->textures[Graphics::typeTexture::CHARA4_DIFFUSE] = this->driver->getTexture("assets/models/Chara4/chara4_diffuse.jpg");
	this->textures[Graphics::typeTexture::CRASH_T] = this->driver->getTexture("assets/models/Crash/Crash_texture.png");
	this->textures[Graphics::typeTexture::DEADPOOL_T] = this->driver->getTexture("assets/models/Deadpool/Deadpool_texture.png");
	this->textures[Graphics::typeTexture::IMPA_T] = this->driver->getTexture("assets/models/Impa/Impa_texture.png");
	this->textures[Graphics::typeTexture::IRONMAN_T] = this->driver->getTexture("assets/models/Iron-man/Iron-man_texture.png");
	this->textures[Graphics::typeTexture::MICKEY_T] = this->driver->getTexture("assets/models/Mickey/Mickey_texture.jpg");
	this->textures[Graphics::typeTexture::LITTLEMAC_T] = this->driver->getTexture("assets/models/Little-mac/AsfLittlemac.png");
	this->textures[Graphics::typeTexture::SNAKE_1] = this->driver->getTexture("assets/models/Snake/snakeTexture.png");
	this->textures[Graphics::typeTexture::SNAKE_2] = this->driver->getTexture("assets/models/Snake/fit_snake_article.png");
	this->textures[Graphics::typeTexture::SNAKE_3] = this->driver->getTexture("assets/models/Snake/fit_snake_body.png");
	this->textures[Graphics::typeTexture::SNAKE_4] = this->driver->getTexture("assets/models/Snake/fit_snake_bes.png");

	this->textures[Graphics::typeTexture::BOX_T] = this->driver->getTexture("assets/models/Object/box.jpg");
	this->textures[Graphics::typeTexture::WALL_T] = this->driver->getTexture("assets/models/Object/mur.jpg");
	this->textures[Graphics::typeTexture::GROUND1_T] = this->driver->getTexture("assets/models/Object/sol1.png");
	this->textures[Graphics::typeTexture::GROUND2_T] = this->driver->getTexture("assets/models/Object/sol2.png");
	this->textures[Graphics::typeTexture::GROUND3_T] = this->driver->getTexture("assets/models/Object/sol2.jpg");
	this->textures[Graphics::typeTexture::BOMB_T] = this->driver->getTexture("assets/models/Object/bomb.png");

	this->textures[Graphics::typeTexture::BUTTON_PLAY_DEF] = this->driver->getTexture("assets/Button/jouer_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_PLAY_PRESSED] = this->driver->getTexture("assets/Button/jouer_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_OPTIONS_DEF] = this->driver->getTexture("assets/Button/options_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_OPTIONS_PRESSED] = this->driver->getTexture("assets/Button/options_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_CREDITS_DEF] = this->driver->getTexture("assets/Button/credits_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_CREDITS_PRESSED] = this->driver->getTexture("assets/Button/credits_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_QUIT_DEF] = this->driver->getTexture("assets/Button/quitter_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_QUIT_PRESSED] = this->driver->getTexture("assets/Button/quitter_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_BACK_DEF] = this->driver->getTexture("assets/Button/retour_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_BACK_PRESSED] = this->driver->getTexture("assets/Button/retour_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_GO_DEF] = this->driver->getTexture("assets/Button/go_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_GO_PRESSED] = this->driver->getTexture("assets/Button/go_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_SAVE_DEF] = this->driver->getTexture("assets/Button/sauver_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_SAVE_PRESSED] = this->driver->getTexture("assets/Button/sauver_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_LOAD_DEF] = this->driver->getTexture("assets/Button/load_no_focus.png");
	this->textures[Graphics::typeTexture::BUTTON_LOAD_PRESSED] = this->driver->getTexture("assets/Button/load_focus.png");

	this->textures[Graphics::typeTexture::INPUT_CONTROLLER1] = this->driver->getTexture("assets/player_select/input_controller1.png");
	this->textures[Graphics::typeTexture::INPUT_CONTROLLER2] = this->driver->getTexture("assets/player_select/input_controller2.png");
	this->textures[Graphics::typeTexture::INPUT_OKLM] = this->driver->getTexture("assets/player_select/input_oklm.png");
	this->textures[Graphics::typeTexture::INPUT_ZQSD] = this->driver->getTexture("assets/player_select/input_zqsd.png");
	this->textures[Graphics::typeTexture::PLAYER_BACK1] = this->driver->getTexture("assets/player_select/player_back_1.png");
	this->textures[Graphics::typeTexture::PLAYER_BACK2] = this->driver->getTexture("assets/player_select/player_back_2.png");
	this->textures[Graphics::typeTexture::PLAYER_BACK3] = this->driver->getTexture("assets/player_select/player_back_3.png");
	this->textures[Graphics::typeTexture::PLAYER_BACK4] = this->driver->getTexture("assets/player_select/player_back_4.png");
	this->textures[Graphics::typeTexture::PLAYER_NAME_JOUEUR] = this->driver->getTexture("assets/player_select/player_name_joueur.png");
	this->textures[Graphics::typeTexture::PLAYER_NAME_ORDI] = this->driver->getTexture("assets/player_select/player_name_ordi.png");
	this->textures[Graphics::typeTexture::PLAYER_NAME_SANS] = this->driver->getTexture("assets/player_select/player_name_sans.png");
	this->textures[Graphics::typeTexture::SELECT_LEFT] = this->driver->getTexture("assets/player_select/select_left.png");
	this->textures[Graphics::typeTexture::SELECT_RIGHT] = this->driver->getTexture("assets/player_select/select_right.png");

	this->textures[Graphics::typeTexture::PAUSE_BACKGROUND] = this->driver->getTexture("assets/models/pause.png");
	this->textures[Graphics::typeTexture::PAUSE_TITLE] = this->driver->getTexture("assets/models/pause_title.png");
	this->textures[Graphics::typeTexture::WINNER_TITLE] = this->driver->getTexture("assets/models/winner.png");
	this->textures[Graphics::typeTexture::MENU_BACKGROUND] = this->driver->getTexture("assets/menu/background.png");
	this->textures[Graphics::typeTexture::MENU_TITLE] = this->driver->getTexture("assets/menu/title.png");
	this->textures[Graphics::typeTexture::FIRE_T] = this->driver->getTexture("assets/models/fire.bmp");
	this->textures[Graphics::typeTexture::BONUS_T] = this->driver->getTexture("assets/models/bonus.bmp");
	this->textures[Graphics::typeTexture::BONUS2_T] = this->driver->getTexture("assets/models/bonus2.png");
	this->textures[Graphics::typeTexture::BONUS3_T] = this->driver->getTexture("assets/models/bonus3.png");
	this->textures[Graphics::typeTexture::BONUS4_T] = this->driver->getTexture("assets/models/bonus4.png");

	this->textures[Graphics::typeTexture::CREDITS_LOGO] = this->driver->getTexture("assets/menu/logo_credits.png");
	this->textures[Graphics::typeTexture::CREDITS_DEV] = this->driver->getTexture("assets/menu/credits_us.png");
}

void	Graphics::beginScene()
{
	this->driver->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));
}

void	Graphics::endScene()
{
	this->driver->endScene();
}

bool	Graphics::isDeviceRunning()
{
	return(this->device->run() && this->driver);
}

bool	Graphics::isWindowActive()
{
	return (this->device->isWindowActive());
}

bool	Graphics::isReloadScreen()
{
	return (this->reloadScreen);
}

void	Graphics::setReloadScreen(bool reloadScreen)
{
	this->reloadScreen = reloadScreen;
}

int	Graphics::getScreenHeight()
{
	return (this->driver->getScreenSize().Height);
}

int	Graphics::getScreenWidth()
{
	return (this->driver->getScreenSize().Width);
}

void	Graphics::addCamera(irr::core::vector3df pos, irr::core::vector3df lookat)
{
	this->smgr->addCameraSceneNode(0, pos, lookat);
}

irr::video::ITexture*	Graphics::getTextureByType(Graphics::typeTexture typeTexture)
{
	return (this->textures[typeTexture]);
}

Assets3DHandler		*Graphics::getAsset3DHandler()
{
	return (this->asset3D);
}

Assets2DHandler		*Graphics::getAsset2DHandler()
{
	return (this->asset2D);
}

void	Graphics::drawAll()
{
	this->smgr->drawAll();
}

irr::scene::IParticleSystemSceneNode	*Graphics::createParticleSystem(bool test)
{
	return (this->smgr->addParticleSystemSceneNode(test));
}

void	Graphics::addLight(irr::core::vector3df pos, irr::video::SColorf color, float radius)
{
	this->smgr->addLightSceneNode(0, pos, color, radius);
}

void	Graphics::activateJoystick(irr::core::array<irr::SJoystickInfo> joystickInfo)
{
	this->device->activateJoysticks(joystickInfo);
}