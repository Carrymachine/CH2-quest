#include "Enemy.h"

#include <iostream>

Monster::Monster()
{
}

Monster::~Monster()
{
}


void Monster::ShowStatus() const
{
    const Stat& stat = GetStat();
    std::cout << "Name: " << enemy->GetClassName() << std::endl;
    std::cout << "HP: " << stat.stat[Stat::HP] << std::endl;
    std::cout << "MP: " << stat.stat[Stat::MP] << std::endl;
    std::cout << "ATK: " << stat.stat[Stat::ATK] << std::endl;
    std::cout << "DEF: " << stat.stat[Stat::DEF] << std::endl;
}

std::string Monster::GetMonsterName() const
{
    if (!enemy)
    {
        return "Monster";
    }

    return enemy->GetClassName();
}

ItemID Monster::DropItem()
{
    if (!enemy)
    {
        return ItemID::Slimeball;
    }

    return enemy->DropItem();
}

int Monster::GetExpReward() const
{
    if (!enemy)
    {
        return 0;
    }

    return enemy->GetExpReward();
}
