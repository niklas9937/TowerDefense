#pragma once
#ifndef defense_h
#define defense_h
#include <stdio.h>

class Defense {

public:
	Defense();
	enum AffinityType { small, medium, large, fire, water, wind, lightning, plant, toxic };
private:
	AffinityType affinity;
	int range;
	typedef struct Point 
	{ 
		int x; 
		int y;

	}posi;
};

#endif 