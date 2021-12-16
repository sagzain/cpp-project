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
	void NextTurn(); // Makes players play next turn based on their speed
	void StartBattle(Combatant&, Combatant&);
	
	// Returns the winner of the Battle Royale
	//Player Winner();
};

