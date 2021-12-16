#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(std::string name, int damage) 
	: Item(name)
{
	this->damage = damage;
}

Weapon::~Weapon() {}

int Weapon::GetDamage()
{
	return damage;
}