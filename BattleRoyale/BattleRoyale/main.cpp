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
#include "Player.h"
#include "Weapon.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

void WelcomeMessage()
{
    cout << "Welcome to C++ Battle Royale" << endl;
    sleep_for(milliseconds(750));
    cout << "Are you prepared to witness a Battle?" << endl << endl;
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

void PlayGame()
{
    Weapon weapon = Weapon("Navaja", 1);

    Player player1 = Player("Samuel", weapon, 5, 1, 1);
    Player player2 = Player("Paula", weapon, 5, 1, 2);
    Player player3 = Player("Random", weapon, 5, 1, 1);

    Player players [] = { player1, player2 , player3};

    BattleGround bg = BattleGround(players);
    bg.PrintPlayers();
    bg.StartBattle(player1, player2);
    
    system("pause");
       
    //bg.PrintPlayers();

    cout << player1.GetTotalPlayers() << endl;
}

int main()
{
    WelcomeMessage();
    PlayGame();
}