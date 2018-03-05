#pragma once
#include "Spell.h"
#include <vector>
#include "ManagersAccess.h"
class SpellBookComponent
{
public:
	SpellBookComponent();
	~SpellBookComponent();
	void initialize(ManagersAccess *managerAccess);
	void addSpell(Spell *spell);
	void cast(int spellId, float rotation, const sf::Vector2f &position);
	virtual void update(const sf::Time &time);
private:
	ManagersAccess *m_managerAccess;
	std::vector <Spell*> m_spellContainer;
};
