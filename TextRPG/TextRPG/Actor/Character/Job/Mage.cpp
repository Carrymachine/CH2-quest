#include "Mage.h"

#include <iostream>

#include "Actor/Enemy/Enemy.h"

Mage::Mage()
{
}

std::string Mage::GetJobName() const
{
    return "Mage";
}

void Mage::attack(Monster* monster)
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
    std::cout << "[Mage] Fires fireball! -> " << damage
        << " damage to " << monster->GetMonsterName() << "!" << std::endl;
}
