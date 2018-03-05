#pragma once
#include <map>
#include <SFML/Graphics.hpp>
class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();
	void initialize(struct ManagersAccess *managerAccess);
private:
	std::map<std::string, sf::Texture> m_textureMap;
	struct ManagersAccess *m_managerAccess;
};
