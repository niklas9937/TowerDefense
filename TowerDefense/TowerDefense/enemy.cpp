#include "enemy.h"

Enemy::Enemy() {

}
Enemy::Enemy(EnemyType race, Point coords)
{
	Enemy::posi = coords;
	Enemy::racename = race;
}

int Enemy::getType()
{
	return racename;
}


int Enemy::getXPosi()
{
	return posi.x;
}
int Enemy::getYPosi()
{
	return posi.y;
}

void Enemy::setPosi(Point pos)
{
	Enemy::posi = pos;
}

