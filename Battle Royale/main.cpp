// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln


#include <iostream> 
#include "Battle.h"

using namespace std;

void EnterPlayers(int n_players, Player* players)
{
    for (int i = 0; i < n_players; i++)
    {
        string name;
        cout << "Introduce el nombre para el jugador " << i << ":\n";
        cin >> name;
        players[i].SetName(name);
    }
}

int main()
{
    int n_players;

    cout << "Introduce el numero de jugadores:\n";
    cin >> n_players;

    Player* players = new Player[n_players];

    EnterPlayers(n_players, players);

    Battle battle;
    Player winner = battle.Fight(&players[0], &players[1]);

    cout << winner.GetName() << " won the encounter.\n";

    cout << "Siguen vivos:\n";

    for (int i = 0; i < n_players; i++)
    {
        cout << players[i].GetName() << endl;
    }
}

