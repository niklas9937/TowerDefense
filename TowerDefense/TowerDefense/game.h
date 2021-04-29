#pragma once
#ifndef game_h
#define game_h

#include <stdio.h>
#include <SDL.h>
#include "structs.h"
#include "defense.h"
#include "enemy.h"
#define xField 25
#define yField 20
#define MaxTower 20
#define MaxEnemy 60
class Game
{
	enum Terrain { gras, weg, burg };
public:
	Game();
	int init(int width, int height);
	void loop();
	void cleanup();
	int setDefense(int xC, int yC, AffinityType type);
	Terrain field[xField][yField];
private:

    Defense towerArray[MaxTower];
	Enemy enemyArray[MaxEnemy];
	int height;
	int width;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	
};
#endif