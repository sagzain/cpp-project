#pragma once
#include "Weapon.h"
#include "Player.h"
#include "Animal.h"

class DataBase
{
private:
	static std::string adjectives[];
	static std::string names[];

	static Player* players;
	static Animal animals[];
	static Weapon weapons[];
public:
	std::string GetRandomName();
	Weapon GetRandomWeapon();

};

