#pragma once

#ifndef level_h
#define level_h

#include "enemy.h"
#include "structs.h"
#include <stack>
#include <iostream>

using namespace std;
class Level
{

public:
	Level() {};
	stack <Enemy> welle1;
	stack <Enemy> welle2;
	stack <Enemy> welle3;
	bool welle2Angefangen = false;
	bool welle3Angefangen = false;






	bool fertig = false;
	unsigned int timeBetweenWelle12 = 20000;
	unsigned int timeBetweenWelle23 = 25000;


	Terrain field[25][20];

private:


};





#endif