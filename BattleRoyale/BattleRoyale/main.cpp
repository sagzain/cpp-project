// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

// BattleRoyale.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "BattleGround.h"
#include "DataBase.h"
#include "Player.h"
#include "Weapon.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

void WelcomeMessage()
{
    cout << "Welcome to C++ Battle Royale" << endl;
    sleep_for(milliseconds(750));
    cout << "Are you prepared to witness a Battle?" << endl;
    sleep_for(seconds(1));
}

bool PlayAgain()
{
    bool finished;
    do
    {
        finished = true;

        cout << endl << "Do you want to play another game? (y/n):" << endl;
        cout << "y/n: ";

        char response;
        cin >> response;

        switch (response)
        {
        case 'y':
        case 'Y':
            return true;
            break;
        case 'n':
        case 'N':
            finished = true;
            break;

        default:
            cout << "Selection error. Try again." << endl;
            finished = false;
        }
    } while (!finished);

    return false;
}

int SelectPlayerNumber()
{
    int nPlayers;

    cout << "Introduce the number of players that are going to participate." << endl;
    cout << "Nº: ";
    
    cin >> nPlayers;

    return nPlayers;
}

void AnnounceWinner(Player player)
{
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\tFinal winner is " << player.GetName() << "." << endl;
    cout << "-------------------------------------------" << endl;
    
    system("pause");
}

Weapon SelectWeapon(DataBase db)
{
    Weapon weapon = Weapon("", 1);
    return weapon;
}

Player* GeneratePlayers(DataBase db, int nPlayers)
{
    Player* players;
    for(int i = 0; i < nPlayers; i++)
    {
        string name = db.GetRandomName();
        cout << "Select a weapon for " << name << "." << endl;
        Weapon weapon = SelectWeapon(db);

        players = new Player(name, weapon, 10, 1, 1);
    }

    return players;
}

void PlayGame(Player* players, Animal* animals)
{
    BattleGround bg = BattleGround(players, animals);
    
    while (!bg.IsOneLeft())
    {
        bg.PrintPlayers();
        system("pause");

        bg.NextEvent();
        system("pause");
    }

    Player winner = bg.FinalWinner();
    AnnounceWinner(winner);
}

int main()
{
    WelcomeMessage();
    int n = SelectPlayerNumber();
    
    DataBase db;
    Player* players = GeneratePlayers(db, n);
    PlayGame(players, db.GetAnimals());
}