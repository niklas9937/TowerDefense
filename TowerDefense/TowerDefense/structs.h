#pragma once

#ifndef structs_h
#define structs_h
enum EnemyType { notEnemy, goblin, goblin_knite, slim_goblin };
enum AffinityType { nothing, small, medium, large, fire, water, wind, lightning, plant, toxic };
enum Destination { nowhere, right, left, top, bottom};
typedef struct Point
{
	int x;
	int y;

};


#endif