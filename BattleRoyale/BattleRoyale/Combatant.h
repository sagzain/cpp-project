#pragma once
#include "Actor.h"
#include "IDamageable.h"

class Combatant : public Actor,  public IDamageable
{
protected:
	int health;
	int damage;
	int speed;

public:
	Combatant();
	Combatant(std::string, int, int, int);
	~Combatant();

	//Getters y Setters
	int GetHealth();
	int GetDamage();
	int GetSpeed();

	//Other methods
	void TakeDamage(int); //Method from interface IDamageable
	virtual void Attack(Combatant&);
	bool IsDead();
};

