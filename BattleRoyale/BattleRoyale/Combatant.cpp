#include "Combatant.h"

#define TOTAL_PROB 100 // Total probability for the rand function
#define PROB_DODGE 25 // Probability for a Combatant to dodge an attack

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
	std::cout << std::endl;
	std::cout << name << " attacks " << other.GetName() << "." << std::endl;

	other.TakeDamage(damage);
}

void Combatant::TakeDamage(int damage)
{
	srand(time(NULL));
	int dodge = rand() % TOTAL_PROB + 1;

	if (dodge <= PROB_DODGE)
	{
		std::cout << name << " dodges the attack." << std::endl;
	}
	else
	{
		health -= damage;

		health = health < 0 ? 0 : health;

		std::cout << name << " takes " << damage << " damage." << std::endl;
		std::cout << health << " left." << std::endl;
	}
}

bool Combatant::IsDead()
{
	return health <= 0;
}