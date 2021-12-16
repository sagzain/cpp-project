#include "Animal.h"

int Animal::totalAnimals = 0;

Animal::Animal(std::string name, int health, int damage, int speed) 
	: Combatant(name, health, damage, speed)
{
	totalAnimals++;
}

Animal::~Animal() {}

int Animal::GetTotalAnimals()
{
	return totalAnimals;
}