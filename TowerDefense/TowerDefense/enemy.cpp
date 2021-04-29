#include "enemy.h"

Enemy::Enemy() {

}
Enemy::Enemy(EnemyType race, Point coords)
{
	Enemy::posi = coords;
	Enemy::racename = race;
}