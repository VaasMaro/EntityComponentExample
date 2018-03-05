#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GraphicsComponent
{
public:
	virtual ~GraphicsComponent() {}
	virtual void update(sf::Time time) {}
	virtual void draw(sf::RenderTexture& renderTexture) = 0;
	virtual void setId(int id) { m_id = id; };
	virtual int getId() { return m_id; }
protected:
	int m_id;
	//std::vector<class Shader*> m_shaderContainer;
};
