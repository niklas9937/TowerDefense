#pragma once
#ifndef enemy_h
#define enemy_h
#include <stdio.h>
#include "structs.h"
class Enemy
{
	
public:
	Enemy();
	Enemy(EnemyType, Point);
	int getType();
	int getXPosi();
	int getYPosi();
	void setPosi(Point pos);
private:
	Point posi;
	EnemyType racename;
	int healthPoints;
	int maxHealthPoints;
	int haste;				//geschwindigkeit
};

#endif