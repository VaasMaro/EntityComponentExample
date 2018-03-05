#include "TileMap.h"

TileMap::TileMap()
{
}

TileMap::TileMap(ManagersAccess *managerAccess,unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
	m_managerAccess = managerAccess;
}

TileMap::~TileMap()
{
}

void TileMap::initialize(std::string textureName, std::string mapName)
{
	m_managerAccess->viewManager->setMapLimit(m_width * 32, m_height * 32);
	m_layerGround = Layer(m_width, m_height);
	m_layerGround.load("Map/" + mapName + "/" + textureName + ".png", "Map/" + mapName + "/" + mapName + "_ground.csv");
	m_layerDecoration = Layer(m_width, m_height);
	m_layerDecoration.load("Map/" + mapName + "/" + textureName + ".png", "Map/" + mapName + "/" + mapName + "_decoration.csv");
	m_layerForeground = Layer(m_width, m_height);
	m_layerForeground.load("Map/" + mapName + "/" + textureName + ".png", "Map/" + mapName + "/" + mapName + "_foreground.csv");
	//m_layerWater = Layer(m_width, m_height);
	//m_layerWater.load("Map/sewer-02/" + textureName + ".png", "Map/sewer-02/" + mapName + "_water.csv");
	m_pathLayer = PathLayer(m_width, m_height);
	m_pathLayer.load("Map/" + mapName + "/" + mapName + "_path.csv");
}


void TileMap::update(sf::RenderTexture& renderTexture)
{
	//renderTexture.draw(m_layerWater);
	renderTexture.draw(m_layerGround);
	renderTexture.draw(m_layerDecoration);
	//m_pathLayer.draw(renderTexture);
}

void TileMap::drawForeground(sf::RenderTexture& renderTexture)
{
	renderTexture.draw(m_layerForeground);
}

sf::Vector2i TileMap::getSize()
{
	return sf::Vector2i(m_width, m_height);
}

PathLayer * TileMap::getPathLayer()
{
	return &m_pathLayer;
}
