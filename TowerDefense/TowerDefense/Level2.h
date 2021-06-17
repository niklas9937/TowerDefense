#pragma once
#ifndef level2_h
#define level2_h

#include "enemy.h"
#include "structs.h"
#include <stack>
#include <iostream>

using namespace std;

class Level2 {
public:
	Level2();
	stack <Enemy> welle1;
	stack <Enemy> welle2;
	bool welle2Angefangen = false;
	typedef struct startWeg1
	{
		int x = 0;
		int y = 96;

	};
	startWeg1 weg1;
	typedef struct startWeg2
	{
		int x = 0;
		int y = 320;

	};
	startWeg2 weg2;
	typedef struct startWeg3
	{
		int x = 0;
		int y = 448;

	};
	startWeg3 weg3;
	bool fertig = false;
	unsigned int timeBetweenWelle12 = 200000;
	unsigned int timeBetweenWelle23 = 250000;


	Terrain field[25][20];
};

#endif
