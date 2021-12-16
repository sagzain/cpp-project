#include "Player.h"

int Player::totalPlayers = 0;

Player::Player(std::string name, Weapon pWeapon, int health, int damage, int speed)
	: Combatant(name, health, damage, speed), weapon(pWeapon)
{
	totalPlayers ++;
}

Player::~Player()
{
	totalPlayers--;
}

void Player::Attack(Combatant &other)
{
	int totalDamage = this->GetDamage() + weapon.GetDamage();
	other.TakeDamage(totalDamage);
}

int Player::GetTotalPlayers()
{
	return totalPlayers;
}

void Player::DecreaseTotalPlayers()
{
	totalPlayers--;
}
