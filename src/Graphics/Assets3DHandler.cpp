/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "Assets3DHandler.hpp"

Assets3DHandler::Assets3DHandler(irr::scene::ISceneManager *smgr,
                                 std::map<Graphics::typeTexture, irr::video::ITexture *> textures,
                                 std::map<Graphics::typeMesh, irr::scene::IAnimatedMesh *> mesh)
{
	this->smgr = smgr;
	this->mesh = mesh;
	this->textures = textures;
	this->index = 0;
	this->fillPosRotTab();
}

Assets3DHandler::~Assets3DHandler()
{
}

bool	Assets3DHandler::destroyById(unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			(*it)->animMeshNode->remove();
			it = this->assets3DList.erase(it);
			return (true);
		}
	}
	return (false);
}

void	Assets3DHandler::destroyAllAsset()
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		(*it)->animMeshNode->remove();
	}
	this->assets3DList.clear();
}

void	Assets3DHandler::destroyByListId(std::list<unsigned> listId)
{
	std::list<unsigned>::iterator	it;

	for (it = listId.begin(); it != listId.end(); ++it)
	{
		this->destroyById((*it));
	}
}

unsigned	Assets3DHandler::createMeshModel3D(Graphics::typeObj type, irr::core::vector3df pos, irr::core::vector3df rot)
{
	MeshModel3D	*model = new MeshModel3D;

	switch (type)
	{
		case (Graphics::CHARA1):
			model->animLoopList[IDLE] = this->mesh[Graphics::CHARA1_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::CHARA1_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::CHARA1_DIFFUSE]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::CHARA1_DIFFUSE];
			break;
		case (Graphics::CHARA2):
			model->animLoopList[IDLE] = this->mesh[Graphics::CHARA2_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::CHARA2_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::CHARA2_DIFFUSE]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::CHARA2_DIFFUSE];
			break;
		case (Graphics::CHARA3):
			model->animLoopList[IDLE] = this->mesh[Graphics::CHARA3_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::CHARA3_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::CHARA3_DIFFUSE]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::CHARA3_DIFFUSE];
			break;
		case (Graphics::CHARA4):
			model->animLoopList[IDLE] = this->mesh[Graphics::CHARA4_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::CHARA4_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::CHARA4_DIFFUSE]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::CHARA4_DIFFUSE];
			break;
		case (Graphics::CRASH):
			model->animLoopList[IDLE] = this->mesh[Graphics::CRASH_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::CRASH_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::CRASH_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::CRASH_T];
			break;
		case (Graphics::DEADPOOL):
			model->animLoopList[IDLE] = this->mesh[Graphics::DEADPOOL_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::DEADPOOL_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::DEADPOOL_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::DEADPOOL_T];
			model->animMeshNode->setScale(irr::core::vector3df(1.3f, 1.3f, 1.3f));
			break;
		case (Graphics::IMPA):
			model->animLoopList[IDLE] = this->mesh[Graphics::IMPA_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::IMPA_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::IMPA_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::IMPA_T];
			model->animMeshNode->setScale(irr::core::vector3df(0.9f, 0.9f, 0.9f));
			break;
		case (Graphics::IRONMAN):
			model->animLoopList[IDLE] = this->mesh[Graphics::IRONMAN_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::IRONMAN_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::IRONMAN_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::IRONMAN_T];
			model->animMeshNode->setScale(irr::core::vector3df(1.2f, 1.2f, 1.2f));
			break;
		case (Graphics::MICKEY):
			model->animLoopList[IDLE] = this->mesh[Graphics::MICKEY_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::MICKEY_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::MICKEY_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::MICKEY_T];
			model->animMeshNode->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
			break;
		case (Graphics::LITTLEMAC):
			model->animLoopList[IDLE] = this->mesh[Graphics::LITTLEMAC_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::LITTLEMAC_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::LITTLEMAC_T]);
			model->animMeshNode->setFrameLoop(0, 60);
			model->animMeshNode->setAnimationSpeed(30);
			model->texture = this->textures[Graphics::LITTLEMAC_T];
			model->animMeshNode->setScale(irr::core::vector3df(1.1f, 1.1f, 1.1f));
			break;
		case (Graphics::SNAKE):
			model->animLoopList[IDLE] = this->mesh[Graphics::SNAKE_IDLE];
			model->animLoopList[WALK] = this->mesh[Graphics::SNAKE_WALK];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[IDLE]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::SNAKE_3]);
			model->animMeshNode->setFrameLoop(0, 72);
			model->animMeshNode->setAnimationSpeed(30);
			model->animMeshNode->setScale(irr::core::vector3df(10, 10, 10));
			model->texture = this->textures[Graphics::SNAKE_1];
			break;
		case (Graphics::FLOOR):
			model->animLoopList[animation::NONE_A] = this->mesh[Graphics::BOX_M];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[animation::NONE_A]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::GROUND1_T]);
			model->texture = this->textures[Graphics::GROUND1_T];
			break;
		case (Graphics::FLOOR2):
			model->animLoopList[animation::NONE_A] = this->mesh[Graphics::BOX_M];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[animation::NONE_A]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::GROUND3_T]);
			model->texture = this->textures[Graphics::GROUND3_T];
			model->animMeshNode->setScale(irr::core::vector3df(55, 1, 55));
			break;
		case (Graphics::WALL):
			model->animLoopList[animation::NONE_A] = this->mesh[Graphics::WALL_M];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[animation::NONE_A]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::WALL_T]);
			model->texture = this->textures[Graphics::WALL_T];
			break;
		case (Graphics::BOX):
			model->animLoopList[animation::NONE_A] = this->mesh[Graphics::BOX_M];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[animation::NONE_A]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::BOX_T]);
			model->texture = this->textures[Graphics::BOX_T];
			break;
		case (Graphics::BOMB):
			model->animLoopList[animation::NONE_A] = this->mesh[Graphics::BOMB_M];
			model->animMeshNode = this->smgr->addAnimatedMeshSceneNode(model->animLoopList[animation::NONE_A]);
			model->animMeshNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			model->animMeshNode->setMaterialTexture(0, this->textures[Graphics::BOMB_T]);
			model->animMeshNode->setScale(irr::core::vector3df(2, 2, 2));
			model->texture = this->textures[Graphics::BOMB_T];
			break;
		default:
			return (-1);
	}
	model->id = this->index;
	this->index++;
	this->assets3DList.push_back(model);
	this->setPositionbyId(pos, model->id);
	this->setRotationbyId(rot, model->id);
	return (model->id);
}

irr::core::vector3df	Assets3DHandler::getPositionById(unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			return ((*it)->animMeshNode->getPosition());
		}
	}
}
void	Assets3DHandler::setPositionbyId(irr::core::vector3df pos, unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			(*it)->animMeshNode->setPosition(pos);
			break;
		}
	}
}

void	Assets3DHandler::setRotationbyId(irr::core::vector3df pos, unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			(*it)->animMeshNode->setRotation(pos);
			break;
		}
	}
}

void	Assets3DHandler::fillPosRotTab()
{
	this->menuPosTab.push_back(irr::core::vector3df(-175, 0, 0));
	this->menuPosTab.push_back(irr::core::vector3df(-55, 0, 0));
	this->menuPosTab.push_back(irr::core::vector3df(55, 0, 0));
	this->menuPosTab.push_back(irr::core::vector3df(175, 0, 0));

	this->menuRotTab.push_back(irr::core::vector3df(0, -30, 0));
	this->menuRotTab.push_back(irr::core::vector3df(0, -15, 0));
	this->menuRotTab.push_back(irr::core::vector3df(0, 15, 0));
	this->menuRotTab.push_back(irr::core::vector3df(0, 30, 0));
}

irr::core::vector3df	Assets3DHandler::getBasicMenuPosbyId(int id)
{
	int						i = 0;
	std::vector<irr::core::vector3df>::iterator	it;

	for (it = this->menuPosTab.begin(); it != this->menuPosTab.end(); ++it)
	{
		if (i == id)
			return((*it));
		i += 1;
	}
	return (irr::core::vector3df(0, 0, 0));
}

irr::core::vector3df	Assets3DHandler::getBasicMenuRotbyId(int id)
{
	int						i = 0;
	std::vector<irr::core::vector3df>::iterator	it;

	for (it = this->menuRotTab.begin(); it != this->menuRotTab.end(); ++it)
	{
		if (i == id)
			return((*it));
		i += 1;
	}
	return (irr::core::vector3df(0, 0, 0));
}

MeshModel3D*	Assets3DHandler::getModelById(unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
			return ((*it));
	}
}

bool	Assets3DHandler::modifyMesh(Graphics::typeObj type, unsigned id)
{
	std::list<MeshModel3D *>::iterator	it;
	MeshModel3D				*model;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			model = this->getModelById(this->createMeshModel3D(type, (*it)->animMeshNode->getPosition(), (*it)->animMeshNode->getRotation()));
			this->destroyById(id);
			model->id = id;
			return (true);
		}
	}
	return (false);
}

void	Assets3DHandler::changeTexture(unsigned id, Graphics::typeTexture texture)
{
	std::list<MeshModel3D *>::iterator	it;
	MeshModel3D				*model;

	for (it = this->assets3DList.begin(); it != this->assets3DList.end(); ++it)
	{
		if ((*it)->id == id)
		{
			model = this->getModelById(id);
			model->animMeshNode->setMaterialTexture(0, this->textures[texture]);
			model->texture = this->textures[texture];
			return;
		}
	}
}

void	Assets3DHandler::changeAnimationById(unsigned id, animation anim)
{
	MeshModel3D	*model = this->getModelById(id);

	if (model->animMeshNode->getMesh() != model->animLoopList[anim]) {
		model->animMeshNode->setMesh(model->animLoopList[anim]);
		model->animMeshNode->setMaterialTexture(0, model->texture);
	}
}
