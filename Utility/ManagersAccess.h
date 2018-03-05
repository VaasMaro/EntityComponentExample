#pragma once
// include managers
#include "EntityManager.h"
#include "MapManager.h"
#include "PhysicsHandler.h"
#include "ViewManager.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "ResourcesManager.h"
struct ManagersAccess
{
	EntityManager *entityManager;
	MapManager *mapManager;
	PhysicsHandler *physicsHandler;
	ViewManager *viewManager;
	InputManager *inputManager;
	DrawManager *drawManager;
	ResourcesManager *resourcesManager;
};