#pragma once
#include <iostream>

class Item
{
protected:
	std::string name;
public:
	Item();
	Item(std::string);
	~Item();
	std::string GetName();
};

