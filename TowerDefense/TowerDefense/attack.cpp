#include "attack.h"
#include <cstdlib>

Attack::Attack()
{

}
Attack::Attack(Point dest, Point posi)
{
	Attack::destination = dest;
	Attack::posi = posi;
	int xC = destination.x - posi.x;
	int yC = destination.y - posi.y;
	Point p;
	p.x = int(xC*0.2);
	p.y = int(yC*0.2);
	Attack::formel = p;
	isInitialized = true;
}
bool Attack::fly()
{
	//neuen Punkt berechnen
	if (5 > std::abs(destination.x - posi.x) and 5 > std::abs(destination.y - posi.y))
	{
		isInitialized = false;
		return true;
	}
	if (destination.x == posi.x && destination.y == posi.y)
	{
		isInitialized = false;
		return true;
	}
	else
	{
		posi.x = posi.x + formel.x;
		posi.y = posi.y + formel.y;
		return false;
	}
}



Point Attack::getPosi()
{
	return posi;
}