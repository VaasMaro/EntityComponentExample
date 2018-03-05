#pragma once
struct StatisticsComponent
{
	int maxLifePoint;
	int maxManaPoint;
	int strength;
	int intelligence;
	float moveSpeed;
	StatisticsComponent(int life, int mana, int str, int intel, float speed)
	{
		maxLifePoint = life;
		maxManaPoint = mana;
		strength = str;
		intelligence = intel;
		moveSpeed = speed;
	}
};