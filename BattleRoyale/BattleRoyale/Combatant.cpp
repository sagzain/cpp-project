#include "Combatant.h"

Combatant::Combatant() 
{
	health = 1;
	damage = 1;
	speed = 1;
}

Combatant::Combatant(std::string name, int health, int damage, int speed) 
	: Actor(name)
{
	this->health = health;
	this->damage = damage;
	this->speed = speed;
}

Combatant::~Combatant() {}

int Combatant::GetHealth()
{
	return health;
}

int Combatant::GetDamage()
{
	return damage;
}

int Combatant::GetSpeed()
{
	return speed;
}

void Combatant::Attack(Combatant &other)
{
	other.TakeDamage(other.GetDamage());
}

void Combatant::TakeDamage(int damage)
{
	this->health -= damage;
	std::cout << std::endl << name << " takes " << damage << " damage." << std::endl;
	std::cout << health << " left." << std::endl;
}

bool Combatant::IsDead()
{
	return health <= 0;
}