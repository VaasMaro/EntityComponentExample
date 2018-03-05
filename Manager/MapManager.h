#pragma once
#include <SFML/Graphics.hpp>
class TileMap;
struct ManagersAccess;
class MapManager
{
public:
	MapManager();
	~MapManager();
	void create(ManagersAccess *managerAccess);
	void update();
	TileMap *getTileMap();
private:
	TileMap *m_tileMap;
	ManagersAccess *m_managerAccess;
};
