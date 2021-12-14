#pragma once
#include "Player.h"

struct Size
{
	int N, M;
};

struct Position
{
	int x, y;
};

class Map
{
private:
	Player** map;
	Size size;
	int totalPlayers;
public:
	Map(Size);
	void PrintMap();
	void SetPlayerAtPosition(Player*, Position);
	Player* GetPlayerAtPosition(Position);
	Position GeneratePosition();
	//bool IsPositionOccupied();
};

