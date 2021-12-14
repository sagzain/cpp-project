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
	cout << endl;

	for (int i = 0; i < size.M; i++)
	{
		for (int j = 0; j < size.N; j++)
		{
			string name = map[i][j].GetName();
			cout <<  (name == "" ? "......" : name) << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void Map::SetPlayerAtPosition(Player player, Position position)
{
	map[position.x][position.y] = player;
	player.SetPosition(position);
}

Player Map::GetPlayerAtPosition(Position position)
{
	return map[position.x][position.y];
}

Position Map::GeneratePosition()
{
	Position position;
	srand(time(NULL));

	do 
	{
		position.x = rand() % size.M;
		position.y = rand() % size.N;
	} while (GetPlayerAtPosition(position).GetName() != "");

	return position;
}

bool Map::IsPositionOccupied()
{
	return true;
}