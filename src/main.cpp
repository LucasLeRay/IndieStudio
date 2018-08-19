/*
** CPP Indie Studio
**
** main
*/

# include <Game/Game.hpp>
#include "indie.hpp"
#include "Graphics.hpp"
#include "GraphicsMenu.hpp"
#include "GraphicsGame.hpp"
#include "SoundMachine.hpp"
#include "Assets3DHandler.hpp"
#include "Launcher.hpp"

int			main(void)
{
 	Launcher	*launcher = new Launcher();

 	launcher->launch();
	return (0);
}
