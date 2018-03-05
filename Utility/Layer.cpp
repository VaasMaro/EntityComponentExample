#include "Layer.h"

Layer::Layer()
{
}

Layer::Layer(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
}

Layer::~Layer()
{
}

void Layer::load(const std::string& tileset, const std::string& layer, int m_tileSize)
{
	// on charge la texture du tileset
	if (!m_texture.loadFromFile(tileset)) std::cout << "texture tileset introuvable" << std::endl;
	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_width * m_height * 4);

	std::ifstream dataLayer(layer);
	std::string layerContent;
	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int j = 0; j < m_width; ++j)
		for (unsigned int i = 0; i < m_height; ++i)
		{
			getline(dataLayer, layerContent, ',');
			// on récupère le numéro de tuile courant
			int tileNumber = std::stoi(layerContent);

			if (tileNumber != -1)
			{
				// on en déduit sa position dans la texture du tileset
				int tu = tileNumber % (m_texture.getSize().x / m_tileSize);
				int tv = tileNumber / (m_texture.getSize().x / m_tileSize);

				// on récupère un pointeur vers le quad à définir dans le tableau de vertex
				sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];
				// on définit ses quatre coins
				quad[0].position = sf::Vector2f(i * m_tileSize, j * m_tileSize);
				quad[1].position = sf::Vector2f((i + 1) * m_tileSize, j * m_tileSize);
				quad[2].position = sf::Vector2f((i + 1) * m_tileSize, (j + 1) * m_tileSize);
				quad[3].position = sf::Vector2f(i * m_tileSize, (j + 1) * m_tileSize);

				// on définit ses quatre coordonnées de texture
				quad[0].texCoords = sf::Vector2f(tu * m_tileSize, tv * m_tileSize);
				quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize, tv * m_tileSize);
				quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize, (tv + 1) * m_tileSize);
				quad[3].texCoords = sf::Vector2f(tu * m_tileSize, (tv + 1) * m_tileSize);
			}
		}
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &m_texture;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}