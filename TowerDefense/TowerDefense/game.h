#pragma once
#ifndef game_h
#define game_h

#include <stdio.h>
#include <SDL.h>
#include "structs.h"
#include "defense.h"
#include "enemy.h"
#include "attack.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#define xField 25
#define yField 20
#define MaxTower 20	
#define MaxEnemy 60
#define MaxAttack 100
class Game
{
	enum Terrain { gras, weg, burg };
public:
	Game();
	int init(int width, int height);
	void loop();
	void cleanup();
	int setDefense(int xC, int yC, AffinityType type, int price);
	int setEnemy(int xC, int yC, EnemyType type);
	Terrain field[xField][yField];
	AffinityType towers[3][3];
	void render();
	void loadLevel();
	void goEnemy(int index);
	void loadField();
	SDL_Texture* loadTexture(std::string path);
	void isInside(int);
	int setAttack(int indexTower, int indexEnemy);
	void renderAttack(int index);

private:
	int indexTowerArray = 0;
	int indexEnemyArray = 0;
	int indexAttackArray = 0;
    Defense towerArray[MaxTower];
	Enemy enemyArray[MaxEnemy];
	Attack attackArray[MaxAttack];
	int height;
	int width;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Renderer* m_renderer2;
	SDL_Texture* m_background;
	int gold = 300;
	void renderGoblin(int);
	
};
#endif