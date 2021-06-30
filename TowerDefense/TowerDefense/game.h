#pragma once
#ifndef game_h
#define game_h

#include <stdio.h>
#include <SDL.h>
#include "structs.h"
#include "defense.h"
#include "enemy.h"
#include "attack.h"
#include "Level1.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <time.h>

#define xField 25
#define yField 20
#define MaxTower 20	
#define MaxEnemy 50
#define MaxAttack 70
class Game
{
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
	int getRandom(int grenze);
	void setNewRandomEnemy();
	void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);
	void isInside2(int indexDefense, int indexEnemy);
	bool level(unsigned int);
private:
	bool verloren = false;
	int indexTowerArray = 0;
	int indexEnemyArray = 0;
	int indexAttackArray = 0;
	int welle = 1;
	int hilfe = 30;
	int height;
	int width;
	AffinityType selectedDefense = AffinityType::nothing; 
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Renderer* m_renderer2;
	SDL_Texture* m_background;
	int gold = 300;
	void renderGoblin(int);
	Defense towerArray[MaxTower];
	Enemy enemyArray[MaxEnemy];
	Attack attackArray[MaxAttack];
	Level1 level1;
	int liveEnemy = 0;
	bool gewonnen = false;
};
#endif