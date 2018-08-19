/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_ASSETS3DHANDLER_HPP
#define CPP_INDIE_STUDIO_ASSETS3DHANDLER_HPP

#include "Graphics.hpp"
#include "indie.hpp"

enum animation
{
	IDLE,
	WALK,
	NONE_A
};

struct  MeshModel3D
{
	unsigned						id;
	std::map<animation, irr::scene::IAnimatedMesh *>	animLoopList;
	irr::scene::IAnimatedMeshSceneNode			*animMeshNode;
	irr::video::ITexture					*texture;
};

class Assets3DHandler
{
public:

	Assets3DHandler(irr::scene::ISceneManager *smgr,
	                std::map<Graphics::typeTexture, irr::video::ITexture*> textures,
	                std::map<Graphics::typeMesh, irr::scene::IAnimatedMesh*>   mesh);

	~Assets3DHandler();

	bool				destroyById(unsigned id);

	void				destroyAllAsset();

	void				destroyByListId(std::list<unsigned> listId);

	unsigned			createMeshModel3D(Graphics::typeObj type,
							  irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), irr::core::vector3df rot = irr::core::vector3df(0, 0, 0));

	irr::core::vector3df		getPositionById(unsigned id);

	void				setPositionbyId(irr::core::vector3df pos, unsigned id);

	void				setRotationbyId(irr::core::vector3df pos, unsigned id);

	irr::core::vector3df		getBasicMenuPosbyId(int id);

	irr::core::vector3df		getBasicMenuRotbyId(int id);

	MeshModel3D			*getModelById(unsigned id);

	bool				modifyMesh(Graphics::typeObj type, unsigned id);

	void				changeTexture(unsigned id, Graphics::typeTexture texture);

	void				changeAnimationById(unsigned id, animation anim);

private:

	void				fillPosRotTab();

	std::vector<irr::core::vector3df>				menuPosTab;
	std::vector<irr::core::vector3df>				menuRotTab;
	irr::scene::ISceneManager					*smgr;
	std::map<Graphics::typeTexture, irr::video::ITexture*>		textures;
	std::map<Graphics::typeMesh, irr::scene::IAnimatedMesh*>	mesh;
	std::list<MeshModel3D *>					assets3DList;
	unsigned							index;
};

#endif //CPP_INDIE_STUDIO_ASSETS3DHANDLER_HPP
