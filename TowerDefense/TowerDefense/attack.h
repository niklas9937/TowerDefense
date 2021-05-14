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
	void fly();

private:
	Point posi;		
	Point destination;
};

#endif#pragma once
