#pragma once
#include <iostream>
#include "Combatant.h"
#include "Weapon.h"

class Player : public Combatant
{
private:
	static int totalPlayers;

	Weapon weapon;
public:
	Player();
	Player(std::string, Weapon, int, int , int);
	~Player();

	virtual void Attack(Combatant&);

	int GetTotalPlayers();
	void DecreaseTotalPlayers();
};

