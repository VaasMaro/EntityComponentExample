#pragma once
#include "Layer.h"
#include "PathLayer.h"
#include "Tile.h"
#include "WaterShader.h"
#include "ManagersAccess.h"
class TileMap 
{
public:
	TileMap();
	TileMap(ManagersAccess *managerAccess, unsigned int width = 32, unsigned int height = 32);
	~TileMap();
	void initialize(std::string textureName, std::string mapName);
	void update(sf::RenderTexture& renderTexture);
	void drawForeground(sf::RenderTexture& renderTexture);
	sf::Vector2i getSize();
	PathLayer * getPathLayer();
private:
	
	WaterShader *m_waterShader;
	Layer m_layerGround;
	Layer m_layerDecoration;
	Layer m_layerForeground;
	Layer m_layerWater;
	PathLayer m_pathLayer;

	unsigned int m_width;
	unsigned int m_height;
	// access to managers
	ManagersAccess *m_managerAccess;


};
