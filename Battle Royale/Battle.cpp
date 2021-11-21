#include "Battle.h"

Player Battle::Fight(Player* p1, Player* p2)
{
    cout << "COMIENZA EL COMBATE\n";

    while (true)
    {
        int index = rand() % 2 + 1;

        switch (index)
        {
        case 1:
            p1->Damage(*p2);
            break;
        case 2:
            p2->Damage(*p1);
            break;
        }

        p1->~Player();
        return *p2;

       /* if (p1->IsDead()){ return *p2; }
        if (p2->IsDead()){ return *p1; }*/

        system("pause");
    }
}

