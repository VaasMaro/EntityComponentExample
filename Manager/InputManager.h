#pragma once
#include "InputOrder.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class InputManager
{
public:
	InputManager();
	~InputManager();
	InputOrder getOrder();
	void update();
private:
	InputOrder m_order;
	bool isJoystickOn = false;
};
