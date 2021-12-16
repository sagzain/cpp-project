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

Player* SelectPlayerNumber()
{
    int nPlayers;

    cout << "Introduce the number of players that are going to participate." << endl;
    cout << "Nº: ";
    
    cin >> nPlayers;

    return nullptr;
}

void AnnounceWinner(Player player)
{
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\tFinal winner is " << player.GetName() << "." << endl;
    cout << "-------------------------------------------" << endl;
    
    system("pause");
}

void PlayGame()
{
    DataBase db;

    Weapon weapon1 = Weapon("Knife", 2);
    Weapon weapon2 = Weapon("Hammer", 1);
    Weapon weapon3 = Weapon("Katana", 3);
    Weapon weapon4 = Weapon("Pistol", 5);

    Player player1 = Player("Wanda", weapon1, 8, 1, 3);
    Player player2 = Player("Steve", weapon2, 10, 1, 3);
    Player player3 = Player("Mike", weapon3, 5, 1, 3);
    Player player4 = Player("Morgana", weapon4, 4, 1, 2);
    Player player5 = Player("John Doe", weapon1, 8, 1, 3);
    Player player6 = Player("Doe John", weapon2, 10, 1, 3);
    Player player7 = Player("Cindy", weapon3, 6, 1, 2);

    Player players [] = { player1, player2 , player3, player4, player5, player6, player7};

    Animal animal1 = Animal("Hound", 4, 1, 3);
    Animal animal2 = Animal("Boar", 5, 2, 1);
    Animal animal3 = Animal("Snake", 3, 1, 5);
    Animal animal4 = Animal("Wolf", 3, 3, 5);
    Animal animal5 = Animal("Bear", 7, 4, 4);
 
    Animal animals[] = { animal1, animal2, animal3, animal4, animal5 };

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
    PlayGame();
}