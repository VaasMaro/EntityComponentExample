#include "ResourcesManager.h"

ResourcesManager::ResourcesManager()
{
}

ResourcesManager::~ResourcesManager()
{
}

void ResourcesManager::initialize(ManagersAccess * managerAccess)
{
	m_managerAccess = managerAccess;
}
