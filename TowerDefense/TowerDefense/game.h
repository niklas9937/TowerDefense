#pragma once
#ifndef game_h
#define game_h

#include <stdio.h>
#include <SDL.h>
#define xField 32
#define yField 28
class Game
{
public:
	Game();
	int init(int width, int height);
	void loop();
	void cleanup();
	enum Terrain {gras, weg, burg};

	Terrain field[xField][yField];

private:
	int height;
	int width;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	
};
#endif