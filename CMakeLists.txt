cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 11)
##set(CMAKE_CXX_FLAGS "-W -Wall -Werror -Wextra")

include_directories(include)
include_directories(include/Game)
include_directories(include/Graphics)
include_directories(irrlicht/include)
include_directories(irrklang/include)

LINK_DIRECTORIES(irrlicht/lib/Linux irrklang/lib/Linux /usr/X11R6/lib64)

add_executable(cpp_indie_studio
	src/AutoPlayer.cpp
	src/Bomberman.cpp
        src/Bonus.cpp
        src/Game.cpp
        src/Bomb.cpp
        src/Wall.cpp
        src/Fire.cpp
        src/Floor.cpp
        src/Map.cpp
        src/main.cpp
        src/Graphics/Graphics.cpp
        src/Graphics/GraphicsGame.cpp
        src/Graphics/GraphicsMenu.cpp
        src/Graphics/Settings.cpp
        src/Graphics/HandleInput.cpp
        src/Graphics/SoundMachine.cpp
        src/Graphics/PlayerSelect.cpp
        src/Graphics/Assets2DHandler.cpp
        src/Graphics/Assets3DHandler.cpp
        src/Graphics/Launcher.cpp
        src/Graphics/Button.cpp)

target_link_libraries (cpp_indie_studio IrrKlang Irrlicht GL Xxf86vm Xext X11 Xcursor)
