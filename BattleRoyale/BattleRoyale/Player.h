#pragma once
#include <iostream>
#include "IDamageable.h"
#include "Weapon.h"
#include "Position.h"

using namespace std;

class Player : public IDamageable
{
private:
	string name;
	int health;
	int baseDamage;

	Weapon weapon;

	Position position;
public:
	Player();
	Player(string, Weapon);
	~Player();
	string GetName();
	int CalculateDamage();
	bool IsDead();
	virtual void TakeDamage(int);
	void SetPosition(Position);
};

