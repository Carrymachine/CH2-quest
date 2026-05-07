#include "Archer.h"

#include <iostream>

#include "Actor/Enemy/Enemy.h"

Archer::Archer()
{
}

std::string Archer::GetJobName() const
{
    return "Archer";
}

void Archer::attack(Monster* monster)
{
    if (monster == nullptr)
    {
        return;
    }

    int damage = (stat.stat[Stat::ATK] - monster->stat.stat[Stat::DEF]) / 3;

    if (damage <= 0)
    {
        damage = 1;
    }

    for (int i = 0; i < 3; i++)
    {
        monster->ApplyDamage(damage);
    }

    std::cout << "[Archer] Shoots arrows! -> " << damage
        << " damage to " << monster->GetMonsterName() << "! (x3)" << std::endl;
}
