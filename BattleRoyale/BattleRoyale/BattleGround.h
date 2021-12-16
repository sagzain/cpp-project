#pragma once
#include "Combatant.h"
#include "Player.h"

class BattleGround
{
private:
	Player* players; // Reference to the players inside the game
	
	// Methods
	void RemovePlayer(Combatant&); // Remove player from pointer when dead

public:
	BattleGround(Player*); // Constructor

	// Other methods
	void PrintPlayers(); // Shows which players are still alive
	
	// Randomized methods
	void NextEvent(); // Generate a random event 
	int GetPlayerOponent(int); // Get player to fight with
	Combatant GenerateAnimalOponent(); // Generate animal to figth with

	// Events 
	void SafeTurn(int); // Event for safe turn
	
	

	// Start Battle vs Player/Animal
	void StartBattle(Combatant&, Combatant&);
	
	// Returns the winner of the Battle Royale
	//Player Winner();
};

