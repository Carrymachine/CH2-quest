#include "Thief.h"

#include <iostream>

#include "Actor/Enemy/Enemy.h"

Thief::Thief()
{
}

std::string Thief::GetJobName() const
{
    return "Thief";
}

void Thief::attack(Monster* monster)
{
    if (monster == nullptr)
    {
        return;
    }

    int damage = (stat.stat[Stat::ATK] - monster->stat.stat[Stat::DEF]) / 5;

    if (damage <= 0)
    {
        damage = 1;
    }

    for (int i = 0; i < 5; i++)
    {
        monster->ApplyDamage(damage);
    }

    std::cout << "[Thief] Throws daggers! -> " << damage
        << " damage to " << monster->GetMonsterName() << "! (x5)" << std::endl;
}
