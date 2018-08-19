/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "Assets2DHandler.hpp"

Assets2DHandler::Assets2DHandler(std::map<Graphics::typeTexture, irr::video::ITexture*> textures, irr::video::IVideoDriver *driver)
{
	this->textures = textures;
	this->driver = driver;
	this->index = 0;
}

Assets2DHandler::~Assets2DHandler()
{
}

bool	Assets2DHandler::destroy2DAsset(unsigned id)
{
	std::list<Asset2D *>::iterator	it;

	for (it = this->Asset2DList.begin(); it != this->Asset2DList.end(); it++)
	{
		if ((*it)->id == id)
		{
			it = this->Asset2DList.erase(it);
			return (true);
		}
	}
	return (false);
}

unsigned	Assets2DHandler::create2DAsset(Graphics::typeTexture typeTexture, float posX, float posY)
{
	Asset2D	*obj = new Asset2D;

	obj->posX = posX;
	obj->posY = posY;
	obj->img = this->textures[typeTexture];
	obj->type = typeTexture;
	obj->id = this->index;
	this->index++;
	this->Asset2DList.push_back(obj);
	return (obj->id);
}

bool	Assets2DHandler::modify2DAsset(Graphics::typeTexture typeTexture, unsigned id, float posX, float posY)
{
	std::list<Asset2D *>::iterator	it;

	for (it = this->Asset2DList.begin(); it != this->Asset2DList.end(); it++)
	{
		if ((*it)->id == id)
		{
			(*it)->img = this->textures[typeTexture];
			if (posX != -1)
				(*it)->posX = posX;
			if (posY != -1)
				(*it)->posY = posY;
			(*it)->type = typeTexture;
			return (true);
		}
	}
	return (false);
}

bool	Assets2DHandler::destroyAll2DAsset()
{
	this->Asset2DList.clear();
	return (true);
}

bool	Assets2DHandler::displayAll2DAsset()
{
	std::list<Asset2D *>::iterator	it;

	for (it = this->Asset2DList.begin(); it != this->Asset2DList.end(); it++)
		this->driver->draw2DImage((*it)->img,
		                          irr::core::position2d<irr::s32>((*it)->posX, (*it)->posY),
		                          irr::core::rect<irr::s32>(0, 0, (*it)->img->getSize().Width, (*it)->img->getSize().Height),
		                          0,
		                          irr::video::SColor(255, 255, 255, 255),
		                          true);
	return (true);
}

bool	Assets2DHandler::displayById(unsigned id)
{
	std::list<Asset2D *>::iterator	it;

	for (it = this->Asset2DList.begin(); it != this->Asset2DList.end(); it++) {
		if ((*it)->id == id) {
			this->driver->draw2DImage((*it)->img,
						  irr::core::position2d<irr::s32>((*it)->posX, (*it)->posY),
						  irr::core::rect<irr::s32>(0, 0, (*it)->img->getSize().Width,
									    (*it)->img->getSize().Height),
						  0,
						  irr::video::SColor(255, 255, 255, 255),
						  true);
		}
	}
	return (true);
}

unsigned long	Assets2DHandler::getSizeList()
{
	return (this->Asset2DList.size());
}

Asset2D*	Assets2DHandler::getAsset2DById(unsigned id)
{
	std::list<Asset2D *>::iterator	it;

	for (it = this->Asset2DList.begin(); it != this->Asset2DList.end(); ++it)
	{
		if ((*it)->id == id)
			return ((*it));
	}
	return (nullptr);
}