#include "Item.h"

Item::Item() {}

Item::Item(std::string name)
{
	this->name = name;
}

Item::~Item() {}

std::string Item::GetName()
{
	return name;
}