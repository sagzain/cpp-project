#include "Player.h"

Player::Player()
{
	health = 10;
	baseDamage = 1;
}

Player::~Player(){}

string Player::GetName()
{
	return name;
}

void Player::SetName(string value)
{
	name = value;
}

void Player::Damage(Player enemy)
{
	enemy.TakeDamage(baseDamage);
}

void Player::TakeDamage(int damage)
{
	health -= damage;
	cout << name << " takes " << damage << " damage.\n";
	cout << health << " left.\n";
}

bool Player::IsDead()
{
	
	return health <= 0;
}
