#pragma once
#ifndef enemy_h
#define enemy_h
#include <stdio.h>

class Enemy
{
public:
	Enemy();
private:
	typedef struct Point 
	{ 
		int x;
		int y;
	} posi;
	int healthPoints;
	int maxHealthPoints;
	int haste;				//geschwindigkeit
};

#endif