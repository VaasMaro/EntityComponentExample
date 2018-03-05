#pragma once
#include <SFML/Graphics.hpp>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(sf::TrianglesFan, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0)
	{
	}

	void setEmitter(sf::Vector2f position)
	{
		m_emitter = position;
	}

	void update(sf::Time elapsed)
	{
		for (std::size_t i = 0; i < m_particles.size(); ++i)
		{
			// on met � jour la dur�e de vie de la particule
			Particle& p = m_particles[i];
			p.lifetime -= elapsed;

			// si la particule est arriv�e en fin de vie, on la r�initialise
			if (p.lifetime <= sf::Time::Zero)
				resetParticle(i);

			// on met � jour la position du vertex correspondant
			m_vertices[i].position += p.velocity * elapsed.asSeconds();

			// on met � jour l'alpha (transparence) de la particule en fonction de sa dur�e de vie
			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

		}
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// on applique la transformation
		states.transform *= getTransform();

		// nos particules n'utilisent pas de texture
		states.texture = NULL;

		// on dessine enfin le vertex array
		target.draw(m_vertices, states);
	}

private:

	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
	};

	void resetParticle(std::size_t index)
	{
		// on donne une vitesse et une dur�e de vie al�atoires � la particule
		float angle = (std::rand() % 100) * 3.14f / 180.f;
		float speed = (std::rand() % 50) + 50.f;
		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

		// on remet � z�ro la position du vertex correspondant � la particule
		m_vertices[index].position = m_emitter;
		m_vertices[index].color.g = std::rand() % 255;
		m_vertices[index].color.b = std::rand() % 255;
	}

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
};