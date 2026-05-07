#include "Warrior.h"

#include <iostream>

#include "Actor/Enemy/Enemy.h"

Warrior::Warrior()
{
}

std::string Warrior::GetJobName() const
{
    return "Warrior";
}

void Warrior::attack(Monster* monster)
{
    if (monster == nullptr)
    {
        return;
    }

    int damage = stat.stat[Stat::ATK] - monster->stat.stat[Stat::DEF];

    if (damage <= 0)
    {
        damage = 1;
    }

    monster->ApplyDamage(damage);
    std::cout << "[Warrior] Swings sword! -> " << damage
        << " damage to " << monster->GetMonsterName() << "!" << std::endl;
}
