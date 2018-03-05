#include "PathLayer.h"

PathLayer::PathLayer()
{
}

PathLayer::PathLayer(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
}

PathLayer::~PathLayer()
{
}

void PathLayer::load(const std::string & layer)
{

	std::ifstream dataLayer(layer);
	std::string layerContent;
	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int j = 0; j < m_width; ++j)
	{
		std::vector<Tile*> row;
		for (unsigned int i = 0; i < m_height; ++i)
		{
			getline(dataLayer, layerContent, ',');
			// on récupère le numéro de tuile courant
			int tileNumber = std::stoi(layerContent);
			Tile *tile = new Tile();

			if (tileNumber == -1)
			{
				tile->isWalkable = false;
			}
			else tile->isWalkable = true;
			row.push_back(tile);
		}
		m_pathArray.push_back(row);
	}

}

void PathLayer::draw(sf::RenderTexture & renderTexture)
{
	for (unsigned int j = 0; j < m_width; ++j)
	{
		for (unsigned int i = 0; i < m_height; ++i)
		{
			if (m_pathArray[i][j]->isWalkable)
			{
				sf::RectangleShape rectangle(sf::Vector2f(32, 32));
				rectangle.setPosition(sf::Vector2f(j * 32, i * 32));
				renderTexture.draw(rectangle);
			}
		}
	}
}

bool PathLayer::isWalkable(int x, int y)
{
	if (x < 0 || y < 0)
	{
		std::cout << "warning : negative position" << std::endl;
		return false;
	}
		
	if (x > m_width || y > m_height)
	{
		std::cout << "warning : position out of bound" << std::endl;
		return false;
	}
	if (m_pathArray[x][y]->isWalkable) return true;
	else return false;
	
}
