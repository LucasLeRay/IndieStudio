/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "HandleInput.hpp"

HandleInput::HandleInput()
{
	this->inputs["MouseClickLeft"] = false;
	this->inputs["z"] = false;
	this->inputs["q"] = false;
	this->inputs["s"] = false;
	this->inputs["d"] = false;
	this->inputs["o"] = false;
	this->inputs["k"] = false;
	this->inputs["l"] = false;
	this->inputs["m"] = false;
	this->inputs["shiftLeft"] = false;
	this->inputs["shiftRight"] = false;
	this->inputs["cUp1"] = false;
	this->inputs["cLeft1"] = false;
	this->inputs["cDown1"] = false;
	this->inputs["cRight1"] = false;
	this->inputs["cAction1"] = false;
	this->inputs["cUp2"] = false;
	this->inputs["cLeft2"] = false;
	this->inputs["cDown2"] = false;
	this->inputs["cRight2"] = false;
	this->inputs["cAction2"] = false;
	this->inputs["space"] = false;
	this->inputs["esc"] = false;
	this->wait = true;
}

HandleInput::~HandleInput()
{
}

void	HandleInput::handleJoystick1Inputs(float axis_x, float axis_y)
{
	if (axis_x < -0.5f) {
		this->inputs["cLeft1"] = true;
		this->inputs["cRight1"] = false;
	} else if (axis_x > 0.5f) {
		this->inputs["cRight1"] = true;
		this->inputs["cLeft1"] = false;
	} else {
		this->inputs["cRight1"] = false;
		this->inputs["cLeft1"] = false;
	}
	if (axis_y < -0.5f) {
		this->inputs["cDown1"] = true;
		this->inputs["cUp1"] = false;
	} else if (axis_y > 0.5f) {
		this->inputs["cUp1"] = true;
		this->inputs["cDown1"] = false;
	} else {
		this->inputs["cUp1"] = false;
		this->inputs["cDown1"] = false;
	}
}

void	HandleInput::handleJoystick2Inputs(float axis_x, float axis_y)
{
	if (axis_x < -0.5f) {
		this->inputs["cLeft2"] = true;
		this->inputs["cRight2"] = false;
	} else if (axis_x > 0.5f) {
		this->inputs["cRight2"] = true;
		this->inputs["cLeft2"] = false;
	} else {
		this->inputs["cRight2"] = false;
		this->inputs["cLeft2"] = false;
	}
	if (axis_y < -0.5f) {
		this->inputs["cDown2"] = true;
		this->inputs["cUp2"] = false;
	} else if (axis_y > 0.5f) {
		this->inputs["cUp2"] = true;
		this->inputs["cDown2"] = false;
	} else {
		this->inputs["cUp2"] = false;
		this->inputs["cDown2"] = false;
	}
}

bool	HandleInput::OnEvent(const irr::SEvent& event)
{
	float	axis_x1;
	float	axis_y1;
	float	axis_x2;
	float	axis_y2;

	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
	{
		switch (event.MouseInput.Event)
		{
			case irr::EMIE_LMOUSE_PRESSED_DOWN:
				this->inputs["MouseClickLeft"] = true;
				break;
			case irr::EMIE_LMOUSE_LEFT_UP:
				this->wait = true;
				this->inputs["MouseClickLeft"] = false;
				break;
			case irr::EMIE_MOUSE_MOVED:
				this->mousePos.X = event.MouseInput.X;
				this->mousePos.Y = event.MouseInput.Y;
				break;
			default:
				break;
		}
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
		switch (event.KeyInput.Key)
		{
			case irr::KEY_RSHIFT:
				this->inputs["shiftRight"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_LSHIFT:
				this->inputs["shiftLeft"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_Z:
				this->inputs["z"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_Q:
				this->inputs["q"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_S:
				this->inputs["s"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_D:
				this->inputs["d"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_O:
				this->inputs["o"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_K:
				this->inputs["k"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_L:
				this->inputs["l"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_KEY_M:
				this->inputs["m"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_SPACE:
				this->inputs["space"] = event.KeyInput.PressedDown;
				break;
			case irr::KEY_ESCAPE:
				this->inputs["esc"] = event.KeyInput.PressedDown;
				break;
			default:
				break;
		}
	}
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
	    && event.JoystickEvent.Joystick == 0)
	{
		axis_x1 = (irr::f32)event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		axis_y1 = (irr::f32)event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		this->handleJoystick1Inputs(axis_x1, axis_y1);
		if (event.JoystickEvent.IsButtonPressed(0))
			this->inputs["cAction1"] = true;
		else
			this->inputs["cAction1"] = false;
	}
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
	    && event.JoystickEvent.Joystick == 1)
	{
		axis_x2 = (irr::f32)event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		axis_y2 = (irr::f32)event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		this->handleJoystick2Inputs(axis_x2, axis_y2);
		if (event.JoystickEvent.IsButtonPressed(0))
			this->inputs["cAction2"] = true;
		else
			this->inputs["cAction2"] = false;
	}
}

std::map<std::string, bool> HandleInput::getInput()
{
	return (this->inputs);
}

void	HandleInput::setGraphics(Graphics *graph)
{
	this->graph = graph;
	this->graph->activateJoystick(this->joystickInfo);
}

HandleInput::MouseStateOnAsset2D HandleInput::getMouseStateOnAsset2D(Asset2D *obj)
{
	irr::core::rect<int> rect;

	rect = irr::core::rect<int>(obj->posX,
	                            obj->posY,
	                            obj->posX + obj->img->getSize().Width,
	                            obj->posY + obj->img->getSize().Height);
	if (rect.isPointInside(this->mousePos))
	{
		if (!this->inputs["MouseClickLeft"])
			return (FOCUS);
		else
		{
			if (this->wait)
			{
				this->inputs["MouseClickLeft"] = true;
				this->wait = false;
				return (CLICK);
			}
			else
				this->inputs["MouseClickLeft"] = false;
			return (NONE);
		}
	}
	return (NONE);
}