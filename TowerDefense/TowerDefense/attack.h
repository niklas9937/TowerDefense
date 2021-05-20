#pragma once
#ifndef attayk_h
#define attack_h
#include <stdio.h>
#include "SDL_image.h"
#include "structs.h"
#include <string>
class Attack
{

public:
	Attack();
	Attack(Point,Point);
	bool fly();
	Point getPosi();
	bool isInitialized;

private:
	Point posi;		
	Point destination;
	Point formel;
};

#endif#pragma once
