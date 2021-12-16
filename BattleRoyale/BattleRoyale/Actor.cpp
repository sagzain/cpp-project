#include "Actor.h"

Actor::Actor() {}

Actor::Actor(std::string name)
{
	this->name = name;
}

Actor::~Actor() {}

std::string Actor::GetName()
{	
	return name;
}