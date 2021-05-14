#pragma once
#ifndef defense_h
#define defense_h
#include <stdio.h>
#include "structs.h"


class Defense {
	
public:
	Defense();
	Defense(AffinityType, Point,int);
	int getXPosi();
	int getYPosi();
	AffinityType getAffinity();
	int getPrice();
	int getRange();
	int getDamage();
private:
	AffinityType affinity;
	int range = 70;
	Point posi;
	int price;
	int damage ;
};

#endif 