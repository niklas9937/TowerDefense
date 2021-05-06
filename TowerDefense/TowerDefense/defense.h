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
private:
	AffinityType affinity;
	int range;
	Point posi;
	int price;
};

#endif 