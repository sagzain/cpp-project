#include "BattleGround.h"
#include <chrono>
#include <thread>

BattleGround::BattleGround(Player* players)
{
	this->players = players;
}

void BattleGround::PrintPlayers()
{
	int length = players[0].GetTotalPlayers();

	std::cout << "Players alive:" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	for (int i = 0; i < length; i++)
	{
		std::cout << players[i].GetName();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		if (i < length - 1) std::cout << ",";
	}

	std::cout << "." << std::endl;
}

void BattleGround::NextTurn()
{

}

void BattleGround::StartBattle(Combatant& fighter1, Combatant& fighter2)
{
	std::cout << std::endl;
	std::cout << "[Battle] " << fighter1.GetName() << " vs " << fighter2.GetName();
	std::cout << std::endl;

	system("pause");

	Combatant winner;
	bool haveWinner = false;

	Combatant combatants [] = {fighter1, fighter2};
	int turn = fighter1.GetSpeed() >= fighter2.GetSpeed() ? 0 : 1;
	
	while (!haveWinner)
	{
		int target = (turn + 1) % 2; // Target is the other position in array
		
		// Combatant deals damage to target on its turn
		combatants[turn].Attack(combatants[target]);

		if (combatants[target].IsDead())
		{
			haveWinner = true;
			winner = combatants[turn];
		}

		turn = target; // Next player's turn

		system("pause");
	}

	std::cout << std::endl;
	std::cout << "Winner is " << winner.GetName() << "." << std::endl;

	RemovePlayer(combatants[turn]);

}

// This method looks for the player in the players array
// removing it and changing the size of the array
// (Array's size will be the same but we won't be able to access last spot)
void BattleGround::RemovePlayer(Combatant& player)
{
	int length = players[0].GetTotalPlayers();

	int index; // Ocurrency of the desired player in the array

	for (index = 0; index < length; index++)
	{
		if (players[index].GetName() == player.GetName())
		{
			break;
		}
	}

	// Check if we have encountered the element (index will be greater if not)
	if (index < length)
	{
		players[0].DecreaseTotalPlayers();
		length = players[0].GetTotalPlayers();
 
		// Move every element to the left (last position will be unnaccesible)
		for (int i = index; i < length; i++)
		{
			players[i] = players[i + 1];
		}
	}
}