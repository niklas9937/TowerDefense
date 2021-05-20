#include "enemy.h"

Enemy::Enemy() {

}
Enemy::Enemy(EnemyType race, Point coords)
{
	Enemy::posi = coords;
	Enemy::racename = race;
	Enemy::healthPoints = 100;
	
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

void Enemy::setHaste(int haste)
{
	Enemy::haste = haste;
}

int Enemy::getHaste()
{
	return haste;
}

void Enemy::damage(int d)
{
	healthPoints = healthPoints - d;
	if (healthPoints <= 0)
	{
		racename = notEnemy;
	}
}

int Enemy::getHealthPoints()
{
	return healthPoints;
}