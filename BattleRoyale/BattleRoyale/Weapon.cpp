#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(string weaponName, int weaponDamage)
{
	name = weaponName;
	damage = weaponDamage;
}

string Weapon::GetName()
{
	return name;
}

int Weapon::GetDamage()
{
	return damage;
}