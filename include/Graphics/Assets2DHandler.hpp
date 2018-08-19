/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_ASSETS2DHANDLER_HPP
#define CPP_INDIE_STUDIO_ASSETS2DHANDLER_HPP

#include "Graphics.hpp"

struct Asset2D
{
	unsigned		id;
	float			posX;
	float			posY;
	Graphics::typeTexture	type;
	irr::video::ITexture	*img;
};

class Assets2DHandler
{
public:

	Assets2DHandler(std::map<Graphics::typeTexture, irr::video::ITexture*> textures, irr::video::IVideoDriver *driver);

	~Assets2DHandler();

	bool		destroy2DAsset(unsigned id);

	unsigned	create2DAsset(Graphics::typeTexture typeTexture, float posX, float posY);

	bool		modify2DAsset(Graphics::typeTexture typeTexture, unsigned id, float posX = -1, float posY = -1);

	bool		destroyAll2DAsset();

	bool		displayAll2DAsset();

	bool		displayById(unsigned id);

	unsigned long	getSizeList();

	Asset2D		*getAsset2DById(unsigned id);

private:

	irr::video::IVideoDriver				*driver;
	std::map<Graphics::typeTexture, irr::video::ITexture*>	textures;
	std::list<Asset2D *>					Asset2DList;
	unsigned						index;
};

#endif //CPP_INDIE_STUDIO_ASSETS2DHANDLER_HPP
