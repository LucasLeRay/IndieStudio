/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Button by Lucas Le Ray
*/

#ifndef PROJECT_BUTTON_HPP
#define PROJECT_BUTTON_HPP

#include "HandleInput.hpp"
#include "Assets2DHandler.hpp"
#include "Graphics.hpp"
#include "SoundMachine.hpp"

enum	sceneChanging {
	PLAY,
	QUIT,
	BACK,
	CREDITS,
	GO,
	NONE
};

class Button
{
public:

	Button(unsigned assetId, Graphics::typeTexture texture, Graphics::typeTexture textureFocus, HandleInput *inputs, bool decal_focus, Graphics *graph, sceneChanging scene, SoundMachine *soundMachine);

	~Button();

	HandleInput::MouseStateOnAsset2D	getState();

	bool					execStateAction();

	sceneChanging				scene;

	unsigned				getId();

private:

	unsigned		assetId;
	Graphics::typeTexture	texture;
	Graphics::typeTexture	textureFocus;
	Assets2DHandler		*assets2DHandler;
	bool			focus;
	HandleInput		*inputs;
	bool			decalFocus;
	Graphics		*graph;
	SoundMachine		*soundMachine;
};

#endif //PROJECT_BUTTON_HPP
