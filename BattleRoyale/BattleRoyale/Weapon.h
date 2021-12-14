#pragma once
#include <iostream>

using namespace std;

class Weapon
{
private:
	string name;
	int damage;

public:
	Weapon();
	Weapon(string, int);
	string GetName();
	void SetName(string);
	int GetDamage();
	void SetDamage(int);
};

