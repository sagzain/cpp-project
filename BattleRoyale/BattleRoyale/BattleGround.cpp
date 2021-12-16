#include "BattleGround.h"
#include <chrono>
#include <thread>

#define TOTAL_PROB 100 // Total probability for the rand function
#define PROB_BATTLE_PLAYER 100 // Accumulative prob 50 to 100 (50%)
#define PROB_BATTLE_ANIMAL 50 // 25 to 50 (25%)
#define PROB_SAFE_TURN 25 // 0 to 25 (25%)

BattleGround::BattleGround(Player* players)
{
	this->players = players;
}

void BattleGround::PrintPlayers()
{
	int length = players[0].GetTotalPlayers(); // array length

	// Players alive displayed on screen
	std::cout << std::endl;
	std::cout << "Players alive:" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	// Print the name of each player that is still alive
	for (int i = 0; i < length; i++)
	{
		std::cout << players[i].GetName();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		if (i < length - 1) std::cout << ",";
	}

	std::cout << "." << std::endl;
}

void BattleGround::NextEvent()
{
	// Random seed initialization
	srand(time(NULL));

	// Get a random player to play an event 
	int turn = rand() % players[0].GetTotalPlayers();

	// Generate a probability to check which event is going to be played
	int prob = rand() % TOTAL_PROB + 1;

	if(prob <= PROB_SAFE_TURN)
	{
		SafeTurn(turn); // Safe turn is played, nothing happens
	}
	else if (prob > PROB_SAFE_TURN && prob <= PROB_BATTLE_ANIMAL)
	{
		std::cout << players[turn].GetName() << " has encountered an animal.";
		std::cout << std::endl;
		
		Combatant animal = GenerateAnimalOponent(); // Generate animal
		StartBattle(players[turn], animal); // Battle with the animal
	}
	else if (prob > PROB_BATTLE_ANIMAL && prob <= PROB_BATTLE_PLAYER)
	{
		std::cout << players[turn].GetName() << " has encountered other opponent.";
		std::cout << std::endl;

		int oponent = GetPlayerOponent(turn); // Get another player
		StartBattle(players[turn], players[oponent]); // Fight p1 vs p2
	}
}

void BattleGround::SafeTurn(int playerIndex)
{
	// Display information about the turn
	std::cout << std::endl;
	std::cout << players[playerIndex].GetName();
	std::cout << " is having a great time walking around.";
	std::cout << std::endl;
}

int BattleGround::GetPlayerOponent(int playerIndex)
{
	// Random seed initialization
	srand(time(NULL));

	int oponentIndex = rand() % players[0].GetTotalPlayers();
	
	while (oponentIndex == playerIndex)
	{
		oponentIndex = rand() % players[0].GetTotalPlayers();
	}

	return oponentIndex;
}

Combatant BattleGround::GenerateAnimalOponent()
{
	// Generates a random animal combatant to fight with
	Combatant oponent = Combatant("Oso", 10, 1, 1);
	return oponent;
}

void BattleGround::StartBattle(Combatant& fighter1, Combatant& fighter2)
{
	// Structured like this instead of having all in one line
	// in order to be able to debug Combatant references
	std::cout << std::endl;
	std::cout << "[Battle] ";
	std::cout << fighter1.GetName(); // if error -> compiler shows us this line
	std::cout << " vs ";
	std::cout << fighter2.GetName(); // if error -> compiler shows us this line
	std::cout << std::endl;

	// Pause for player to press Enter and continue the execution
	system("pause");

	Combatant winner;
	bool haveWinner = false;

	// In order to handle easier the fight, we will put the combatants
	// in an array
	Combatant combatants [] = {fighter1, fighter2};

	// Turn is selected based on speed (if equals, first fighter starts)
	int turn = fighter1.GetSpeed() >= fighter2.GetSpeed() ? 0 : 1;
	
	// while we don't have a winner, continue turn base combat
	while (!haveWinner)
	{
		int target = (turn + 1) % 2; // Target is the other position in array
		
		
		// Combatant deals damage to target on its turn
		combatants[turn].Attack(combatants[target]);

		// Checks if target is dead, so we have a winner
		// Continue while loop otherwhise
		if (combatants[target].IsDead())
		{
			haveWinner = true;
			winner = combatants[turn];
		}

		turn = target; // Next player's turn

		system("pause");
	}


	// Shows winner information for this encounter 
	std::cout << std::endl;
	std::cout << "Winner is " << winner.GetName() << "." << std::endl;

	// Remove player from the players array (if it is an animal, it won't be removed)
	RemovePlayer(combatants[turn]);
}

// This method looks for the player in the players array
// removing it and changing the size of the array
// (Array's size will be the same but we won't be able to access last spot)
void BattleGround::RemovePlayer(Combatant& player)
{
	int length = players[0].GetTotalPlayers(); // array length

	int index; // Ocurrency of the desired player in the array

	// Iterate through the array to find player
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

Player BattleGround::FinalWinner()
{
	return players[0];
}

bool BattleGround::IsOneLeft()
{
	return players[0].GetTotalPlayers() == 1;
}