#pragma once
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
private:
	int damage;

public:
	Weapon(std::string, int);
	~Weapon();

	int GetDamage();
};

