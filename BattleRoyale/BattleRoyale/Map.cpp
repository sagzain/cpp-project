#include "Map.h"

Map::Map()
{
	totalPlayers = 0;
}

void Map::PrintMap()
{
	for (int i = 0; i < size.M; i++)
	{
		for (int j = 0; j < size.N; j++)
		{
			string name = map[i][j].GetName();
			cout <<  (name == "" ? "X" : name) << " ";
		}

		cout << endl;
	}
}

void Map::SetPlayerAtPosition(Player* player, Position newPosition)
{
	map[newPosition.x, newPosition.y] = player;
}

Player* Map::GetPlayerAtPosition(Position position)
{
	return map[position.x, position.y];
}

Position Map::GeneratePosition()
{
	Position position;
	position.x = 1;
	position.y = 1;
	return position;
}

//bool Map::IsPositionOccupied()
//{
//	return true;
//}