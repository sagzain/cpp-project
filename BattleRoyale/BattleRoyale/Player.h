#pragma once
#include <iostream>
#include "IDamageable.h"
#include "Weapon.h"

using namespace std;

class Player : public IDamageable
{
private:
	string name;
	int health;
	int baseDamage;

	Weapon weapon;
public:
	Player();
	Player(string, Weapon);
	~Player();
	string GetName();
	int CalculateDamage();
	bool IsDead();
	virtual void TakeDamage(int);
};

