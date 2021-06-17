#include "defense.h"

Defense::Defense()
{

}
Defense::Defense(AffinityType type, Point coords, int p)
{
	Defense::affinity = type;


	switch (type)
	{
	default: Defense::posi = coords; Defense::price = 0; Defense::damage = 0;
		case AffinityType::small: Defense::posi = coords; Defense::price = 50; Defense::damage = 10; Defense::range = 40; break;
		case AffinityType::medium: Defense::posi = coords; Defense::price = 100; Defense::damage = 10; Defense::range = 60; break;
		case AffinityType::large: Defense::posi = coords; Defense::price = 150; Defense::damage = 10; Defense::range = 70; break;
		case AffinityType::fire: Defense::posi = coords; Defense::price = 200; Defense::damage = 15; Defense::range = 70; break;
		case AffinityType::lightning: Defense::posi = coords; Defense::price = 250; Defense::damage = 0; Defense::range = 70; break;
		case AffinityType::plant: Defense::posi = coords; Defense::price = 200; Defense::damage = 1; Defense::range = 70; break;
		case AffinityType::toxic: Defense::posi = coords; Defense::price = 200; Defense::damage = 15; Defense::range = 70; break;
		case AffinityType::water: Defense::posi = coords; Defense::price = 200; Defense::damage = 15; Defense::range = 70; break;
		case AffinityType::wind: Defense::posi = coords; Defense::price = 200; Defense::damage = 5; Defense::range = 70; break;
		case AffinityType::nothing: Defense::posi = coords; Defense::price = 0; Defense::damage = 0; Defense::range = 0; break;
	}

}

AffinityType Defense::getAffinity()
{
	return affinity;
}

int Defense::getXPosi()
{
	return posi.x;
}
int Defense::getYPosi()
{
	return posi.y;
}

int Defense::getPrice()
{
	return price;
}
int Defense::getRange()
{
	return range;
}

int Defense::getDamage()
{
	return damage;
}

int Defense::getIndexAttackOfEnemy()
{
	return indexAttackOnEnemy;
}

void Defense::setIndexAttackOfEnemy(int index)
{
	indexAttackOnEnemy = index;
}