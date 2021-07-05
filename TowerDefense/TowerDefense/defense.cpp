#include "defense.h"

Defense::Defense()
{

}
Defense::Defense(AffinityType type, Point coords, int p)
{
	Defense::affinity = type;


	switch (type)
	{
	default: Defense::posi = coords; Defense::price = 0; Defense::damage = 0; Defense::beschreibung = "N/A";
	case AffinityType::small: Defense::posi = coords; Defense::price = 70; Defense::damage = 4; Defense::range = 40; Defense::beschreibung = "short range tower"; break;
		case AffinityType::medium: Defense::posi = coords; Defense::price = 100; Defense::damage = 5; Defense::range = 60; Defense::beschreibung = "medium range tower"; break;
		case AffinityType::large: Defense::posi = coords; Defense::price = 150; Defense::damage = 5; Defense::range = 70; Defense::beschreibung = "long range tower"; break;
		case AffinityType::fire: Defense::posi = coords; Defense::price = 200; Defense::damage = 10; Defense::range = 70; Defense::beschreibung = "fire attribute"; break;
		case AffinityType::lightning: Defense::posi = coords; Defense::price = 250; Defense::damage = 0; Defense::range = 70; Defense::beschreibung = "slows enemies"; break;
		case AffinityType::plant: Defense::posi = coords; Defense::price = 200; Defense::damage = 1; Defense::range = 70; Defense::beschreibung = "low DMG but AOE"; break;
		case AffinityType::toxic: Defense::posi = coords; Defense::price = 200; Defense::damage = 10; Defense::range = 70; Defense::beschreibung = "toxic"; break;
		case AffinityType::water: Defense::posi = coords; Defense::price = 200; Defense::damage = 10; Defense::range = 70; Defense::beschreibung = "water attribute"; break;
		case AffinityType::wind: Defense::posi = coords; Defense::price = 200; Defense::damage = 10; Defense::range = 70; Defense::beschreibung = "wind attribute"; break;
		case AffinityType::nothing: Defense::posi = coords; Defense::price = 0; Defense::damage = 0; Defense::range = 0; Defense::beschreibung = "N/A"; break;
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