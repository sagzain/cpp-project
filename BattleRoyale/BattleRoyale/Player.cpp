#include "Player.h"

int Player::totalPlayers = 0;

Player::Player(std::string name, Weapon pWeapon, int health, int damage, int speed)
	: Combatant(name, health, damage + pWeapon.GetDamage(), speed), weapon(pWeapon)
{
	totalPlayers ++;
}

Player::~Player()
{
	totalPlayers--;
}

void Player::Attack(Combatant &other)
{
	std::cout << name << " attacks " << other.GetName();
	std::cout << " using " << weapon.GetName() << "." << std::endl;

	other.TakeDamage(damage);
}

int Player::GetTotalPlayers()
{
	return totalPlayers;
}

void Player::DecreaseTotalPlayers()
{
	totalPlayers--;
}
