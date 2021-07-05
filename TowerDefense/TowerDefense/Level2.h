#pragma once
#ifndef level2_h
#define level2_h

#include "enemy.h"
#include "structs.h"
#include <stack>
#include <iostream>

#include "Level.h"

using namespace std;

class Level2 : public Level {
public:
	Level2();
	
	typedef struct startWeg1
	{
		int x = 0;
		int y = 192;

	};
	startWeg1 weg1;
	typedef struct startWeg2
	{
		int x = 0;
		int y = 416;

	};
	startWeg2 weg2;
	
};

#endif
