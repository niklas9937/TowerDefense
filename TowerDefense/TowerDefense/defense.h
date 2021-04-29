#pragma once
#ifndef defense_h
#define defense_h
#include <stdio.h>
#include "structs.h"


class Defense {
	
public:
	Defense();
	Defense(AffinityType, Point);
	
private:
	AffinityType affinity;
	int range;
	Point posi;
};

#endif 