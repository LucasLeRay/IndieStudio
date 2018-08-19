/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_HANDLEINPUT_HPP
#define CPP_INDIE_STUDIO_HANDLEINPUT_HPP

#include "Assets2DHandler.hpp"
#include <IEventReceiver.h>
#include <map>
#include <vector2d.h>

class HandleInput : public irr::IEventReceiver {
	public:

	enum MouseStateOnAsset2D
	{
		FOCUS,
		CLICK,
		NONE
	};

	HandleInput();

	~HandleInput();

	void	setGraphics(Graphics *graph);

	virtual bool OnEvent(const irr::SEvent& event);

	std::map<std::string, bool>     getInput();

	irr::core::vector2d<int>        getMousePosition();

	MouseStateOnAsset2D             getMouseStateOnAsset2D(Asset2D *obj);

	void				resetInputs();

	private:

	void					handleJoystick1Inputs(float axis_x, float axis_y);

	void					handleJoystick2Inputs(float axis_x, float axis_y);

	Graphics                                *graph;
	std::map<std::string, bool>             inputs;
	irr::core::position2di                  mousePos;
	bool                                    leftButtonClick;
	bool                                    wait;
	irr::core::array<irr::SJoystickInfo>	joystickInfo;
};

#endif //CPP_INDIE_STUDIO_HANDLEINPUT_HPP
