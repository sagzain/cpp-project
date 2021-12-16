#pragma once
#include "Combatant.h"

class Animal : public Combatant
{
private:
	static int totalAnimals;

public:

	Animal(std::string, int, int, int);
	~Animal();

	//Getters & Setters
	int GetTotalAnimals();
};

