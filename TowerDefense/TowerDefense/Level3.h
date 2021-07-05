#pragma once
#ifndef level3_h
#define level3_h

#include "enemy.h"
#include "structs.h"
#include "Level.h"
#include <stack>
#include <iostream>

using namespace std;

class Level3 : public Level {
public:
	Level3();


	typedef struct startWeg1
	{
		int x = 576;
		int y = 0;

	};
	startWeg1 weg1;
	typedef struct startWeg2
	{
		int x = 0;
		int y = 256;

	};
	startWeg2 weg2;
	typedef struct startWeg3
	{
		int x = 480;
		int y = 608;

	};
	startWeg3 weg3;
};

#endif
