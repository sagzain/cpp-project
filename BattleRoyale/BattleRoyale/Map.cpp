#include "Map.h"


Map::Map(Size size)
{
	map = new Player*[size.M];
	for (int i = 0; i < size.M; i++)
	{
		map[i] = new Player[size.N];
	}

	totalPlayers = 0;
	this->size = size;
}

void Map::PrintBattleground()
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

void Map::SetPlayerAtPosition(Player player, Position position)
{
	map[position.x][position.y] = player;
}

Player Map::GetPlayerAtPosition(Position position)
{
	return map[position.x][position.y];
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