#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
class Layer : public sf::Drawable, public sf::Transformable
{
public:
	Layer();
	Layer(unsigned int width, unsigned int height);
	~Layer();
	void load(const std::string& tileset, const std::string& layer, int m_tileSize = 32);

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

	sf::Texture m_texture;
	sf::VertexArray m_vertices;
	unsigned int m_width;
	unsigned int m_height;
};
