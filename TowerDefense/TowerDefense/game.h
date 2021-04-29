#pragma once
#ifndef game_h
#define game_h

#include <stdio.h>
#include "SDL.h"
class Game
{
public:
	Game();
	int init(int width, int height);
	void loop();
	void cleanup();
private:
	int height;
	int width;
};
#endif