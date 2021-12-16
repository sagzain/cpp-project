#pragma once
#include <iostream>

class Actor
{
protected:
	std::string name;

public:
	Actor();
	Actor(std::string);
	~Actor();
	std::string GetName();
};

