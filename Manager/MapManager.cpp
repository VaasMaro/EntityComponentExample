#include "MapManager.h"
#include "ManagersAccess.h"
#include "TileMap.h"
MapManager::MapManager()
{

}

MapManager::~MapManager()
{
}

void MapManager::create(ManagersAccess *managerAccess)
{
	m_tileMap = new TileMap(managerAccess);
	m_tileMap->initialize("Evil", "sewer-3");
}
void MapManager::update()
{

}

TileMap * MapManager::getTileMap()
{
	return m_tileMap;
}
