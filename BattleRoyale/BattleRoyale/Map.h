#pragma once
#include "Player.h"
#include "Position.h"

struct Size
{
	int N, M;
};

class Map
{
private:
	Player ** map;
	Size size;
	int totalPlayers;
public:
	Map(Size);
	void PrintBattleground();
	void SetPlayerAtPosition(Player, Position);
	Player GetPlayerAtPosition(Position);
	Position GeneratePosition();
	bool IsPositionOccupied();
};

