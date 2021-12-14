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

#include "Map.h"
#include "Player.h"
#include "Weapon.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

void WelcomeMessage()
{
    cout << "Welcome to C++ Battle Royale" << endl;
    sleep_for(seconds(1));
    cout << "Are you prepared to witness a Battle?" << endl;
    sleep_for(seconds(2));
}

Size MapSelector()
{
    Size size;
    bool finished;

    do
    {
        finished = true;

        cout << endl;
        cout << "Select map dimensions:" << endl;
        sleep_for(milliseconds(60));
        cout << "1 - Small (3x3)" << endl;
        sleep_for(milliseconds(40));
        cout << "2 - Normal (6x6)" << endl;
        sleep_for(milliseconds(40));
        cout << "3 - Large (10x10)" << endl;
        sleep_for(milliseconds(40));

        int selection;
        cout << endl << "Selection: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            size = { 3,3 };
            break;
        case 2:
            size = { 6,6 };
            break;
        case 3:
            size = { 10, 10 };
            break;
        default:
            cout << "Selection error. Try again." << endl;
            finished = false;
            break;
        }
    } while (!finished);

    return size;
}

bool PlayAgain()
{
    bool finished;
    do
    {
        finished = true;

        cout << "Do you want to play another game? (y/n):" << endl;
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
            return false;
            break;

        default:
            cout << "Selection error. Try again." << endl;
            finished = false;
        }
    } while (!finished);
}

void PlayGame()
{
    Size size = MapSelector();

    Map map = Map(size);

    Weapon weapon;
    Player player1 = Player("Samuel", weapon);
    Player player2 = Player("Adrian", weapon);
    Player player3 = Player("Miguel", weapon);
    Player player4 = Player("AnuelB", weapon);
    Player player5 = Player("Manuel", weapon);

    map.SetPlayerAtPosition(player1, map.GeneratePosition());
    map.SetPlayerAtPosition(player2, map.GeneratePosition());
    map.SetPlayerAtPosition(player3, map.GeneratePosition());
    map.SetPlayerAtPosition(player4, map.GeneratePosition());
    map.SetPlayerAtPosition(player5, map.GeneratePosition());

    map.PrintBattleground();
}

void InitMainMenu()
{
    bool repeat;

    WelcomeMessage();
    
    do
    {
        PlayGame();
        repeat = PlayAgain();
    } while (repeat);
}

int main()
{
    InitMainMenu();
}