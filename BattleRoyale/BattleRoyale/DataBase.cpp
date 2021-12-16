#include "DataBase.h"

DataBase::DataBase()
{
    srand(time(NULL));
}

std::string DataBase::adjectives[] =
{
    "Incredible",
    "Awesome",
    "Fluffy",
    "Scary",
    "Pretty",
    "Fearless",
    "Coward",
    "Flipped",
    "Colorfull",
    "Cheerfull"
};

std::string DataBase::names[] =
{
    "Monster",
    "Citizen",
    "Cookie",
    "Hunter",
    "Cowboy",
    "Mercenary",
    "Vehicle",
    "Clown",
    "Firefighter",
    "Doctor"
};

Animal DataBase::animals[] =
{
    Animal("Chicken", 1, 1, 1),
    Animal("Rabbit", 1, 1, 5),
    Animal("Hound", 4, 1, 3),
    Animal("Boar", 5, 2, 1),
    Animal("Snake", 4, 2, 5),
    Animal("Wolf", 4, 3, 5),
    Animal("Tiger", 5, 3, 5),
    Animal("Bear", 7, 5, 4)
};
Weapon DataBase::weapons[] =
{
    Weapon("Hammer", 1),
    Weapon("Knife", 2),
    Weapon("Katana", 3),
    Weapon("Crossbow", 4),
    Weapon("Pistol", 5)
};

std::string DataBase::GetRandomName()
{
    int randomAdjective = rand() % 10;
    int randomName = rand() % 10;

    std::string generated = adjectives[randomAdjective]
        + names[randomName];

    return generated;
}

Weapon DataBase::GetRandomWeapon()
{
    int size = sizeof(weapons) / sizeof(weapons[0]);
    int random = rand() % size;

    return weapons[random];
}

Weapon* DataBase::GetWeapons()
{
    return weapons;
}

Animal* DataBase::GetAnimals()
{
    return animals;
}