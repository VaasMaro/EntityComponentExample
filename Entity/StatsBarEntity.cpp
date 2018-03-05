#include "StatsBarEntity.h"
#include "ColorPalette.h"
#include "ViewManager.h"
StatsBarEntity::StatsBarEntity()
{
}

StatsBarEntity::~StatsBarEntity()
{
}

void StatsBarEntity::initialize(sf::Vector2f position, PlayerEntity * player, ManagersAccess *managerAccess)
{
	m_managerAccess = managerAccess;
	m_player = player;

	// position
	m_position = new PositionComponent(position.x, position.y);
	// life bar
	m_lifeRect = new RectGraphicsComponent();
	m_lifeRect->initialize(sf::Vector2f(m_player->getNumberLife() * m_widthFactor, m_barSize));
	m_lifeRect->setId(m_managerAccess->drawManager->subscribeUILayer(m_lifeRect));
	m_lifeRect->setColor(Pomegranate);
	// life over bar
	m_lifeOverRect = new RectGraphicsComponent();
	m_lifeOverRect->initialize(sf::Vector2f(m_player->getMaximumLife() * m_widthFactor, m_barSize));
	m_lifeOverRect->setId(m_managerAccess->drawManager->subscribeUILayer(m_lifeOverRect));
	m_lifeOverRect->setColor(sf::Color::Transparent);
	m_lifeOverRect->setProperty(Wetasphalt, 5);
	// mana bar
	m_manaRect = new RectGraphicsComponent();
	m_manaRect->initialize(sf::Vector2f(m_player->getNumberMana() * m_widthFactor, m_barSize));
	m_manaRect->setId(m_managerAccess->drawManager->subscribeUILayer(m_manaRect));
	m_manaRect->setColor(Belizehole);
	// mana over bar
	m_manaOverRect = new RectGraphicsComponent();
	m_manaOverRect->initialize(sf::Vector2f(m_player->getNumberMana() * m_widthFactor, m_barSize));
	m_manaOverRect->setId(m_managerAccess->drawManager->subscribeUILayer(m_manaOverRect));
	m_manaOverRect->setColor(sf::Color::Transparent);
	m_manaOverRect->setProperty(Wetasphalt, 5);

	// set position
	setPosition(*m_position);
}

void StatsBarEntity::update(sf::Time time)
{
	setPosition(*m_position);
	m_lifeRect->setWidth((m_player->getNumberLife() * m_widthFactor));
	m_lifeOverRect->setWidth((m_player->getMaximumLife() * m_widthFactor));
	m_manaRect->setWidth((m_player->getNumberMana() * m_widthFactor));
	m_manaOverRect->setWidth((m_player->getMaximumMana() * m_widthFactor));
}

void StatsBarEntity::setPosition(sf::Vector2f position)
{
	sf::Vector2f pixelPos = m_managerAccess->viewManager->getViewCenter();


	m_lifeRect->setPosition(sf::Vector2f(pixelPos.x + m_position->x, pixelPos.y + m_position->y));
	m_lifeOverRect->setPosition(sf::Vector2f(pixelPos.x + m_position->x, pixelPos.y + m_position->y));
	m_manaRect->setPosition(sf::Vector2f(pixelPos.x + m_position->x, pixelPos.y + m_position->y + m_margin + m_barSize));
	m_manaOverRect->setPosition(sf::Vector2f(pixelPos.x + m_position->x, pixelPos.y + m_position->y + m_margin + m_barSize));
}
