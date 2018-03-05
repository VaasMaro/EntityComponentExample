#include "SpellBookComponent.h"

SpellBookComponent::SpellBookComponent()
{
}

SpellBookComponent::~SpellBookComponent()
{
	for (auto spell : m_spellContainer)
	{
		delete spell;
	}
}

void SpellBookComponent::initialize(ManagersAccess * managerAccess)
{
	m_managerAccess = managerAccess;
}

void SpellBookComponent::addSpell(Spell *spell)
{
	m_spellContainer.push_back(spell);
}

void SpellBookComponent::cast(int spellId, float rotation, const sf::Vector2f &position)
{
	m_spellContainer[spellId]->cast(rotation, position);
}

void SpellBookComponent::update(const sf::Time & time)
{
	for (auto spell : m_spellContainer)
	{
		spell->update(time);
	}
}
