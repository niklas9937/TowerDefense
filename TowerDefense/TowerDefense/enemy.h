#pragma once
#ifndef enemy_h
#define enemy_h
#include <stdio.h>
#include "SDL_image.h"
#include "structs.h"
#include <string>
class Enemy
{
	
public:
	Enemy();
	Enemy(EnemyType, Point);
	int getType();
	int getXPosi();
	int getYPosi();
	void setPosi(Point pos);
	void setHaste(int haste);
	int getHaste();


	void setDestination(Destination newDest) { dest = newDest; }
	void setSteps(int steps) { stepsLeft = steps; }
	
	Destination getDestination() { return dest; }
	int getStepsLeft() { return stepsLeft; }
private:
	Destination dest;
	int stepsLeft = 0;
	Point posi;
	EnemyType racename;
	int healthPoints;
	int maxHealthPoints;
	int haste;				//geschwindigkeit
};

#endif