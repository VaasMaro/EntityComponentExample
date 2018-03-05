#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Tile.h"

class PathLayer
{
public:
	PathLayer();
	PathLayer(unsigned int width, unsigned int height);
	~PathLayer();
	void load(const std::string& layer);
	void draw(sf::RenderTexture & renderTexture);
	bool isWalkable(int x, int y);
private:
	std::vector< std::vector<Tile*> > m_pathArray;
	unsigned int m_width;
	unsigned int m_height;
};
