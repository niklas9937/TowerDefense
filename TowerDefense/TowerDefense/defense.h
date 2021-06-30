#pragma once
#ifndef defense_h
#define defense_h
#include <stdio.h>
#include "structs.h"
#include <string>

class Defense {

public:
	Defense();
	Defense(AffinityType, Point, int);
	int getXPosi();
	int getYPosi();
	AffinityType getAffinity();
	int getPrice();
	int getRange();
	int getDamage();
	int getIndexAttackOfEnemy();
	void setIndexAttackOfEnemy(int index);
private:
	AffinityType affinity;
	int range;
	std::string beschreibung;
	Point posi;
	int price;
	int damage;
	int indexAttackOnEnemy;
};

#endif 