#include <iostream>

using namespace std;

class Player
{
private:
	string name;
	int health;
	int baseDamage;

public:
	Player();
	~Player();
	string GetName();
	void SetName(string);
	void Damage(Player);
	void TakeDamage(int);
	bool IsDead();
};