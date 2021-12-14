#include "Player.h"

Player::Player() {}

Player::Player(string playerName, Weapon playerWeapon)
{
	name = playerName;
	health = 10;
	baseDamage = 1;
	weapon = playerWeapon;
}

Player::~Player() {}

string Player::GetName()
{
	return name;
}

int Player::CalculateDamage()
{
	return weapon.GetDamage() + baseDamage;
}

bool Player::IsDead()
{
	return health <= 0;
}

void Player::TakeDamage(int damage)
{
	health -= damage;
	cout << endl << name << "takes " << damage << "damage." << endl;
	cout << health << " left." << endl;
}