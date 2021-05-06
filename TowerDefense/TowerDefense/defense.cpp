#include "defense.h"

Defense::Defense()
{

}
Defense::Defense(AffinityType type, Point coords, int p)
{
	Defense::affinity = type;
	Defense::posi = coords;
	Defense::price = p;
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