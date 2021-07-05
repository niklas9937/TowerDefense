#include "enemy.h"

Enemy::Enemy() {

}
Enemy::Enemy(EnemyType race, Point coords)
{
	Enemy::posi = coords;
	Enemy::racename = race;
	

	switch (race)
	{
		default: Enemy::haste = 1; Enemy::healthPoints = 100; Enemy::reward = 10;
		case EnemyType::notEnemy: Enemy::haste = 0; Enemy::healthPoints = 200; Enemy::reward = 0;
		case EnemyType::goblin: Enemy::haste = 1; Enemy::healthPoints = 350; Enemy::reward = 15; break;
		case EnemyType::goblin_knite: Enemy::haste = 1; Enemy::healthPoints = 500; Enemy::reward = 40; break;
		case EnemyType::slim_goblin: Enemy::haste = 2; Enemy::healthPoints = 300; Enemy::reward = 25; break;
	}

}

int Enemy::getType()
{
	return racename;
}

int Enemy::getReward()
{
	return reward;
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