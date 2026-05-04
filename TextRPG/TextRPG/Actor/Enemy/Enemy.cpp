#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}


void Enemy::ShowStatus() const
{
    const Stat& stat = GetStat();
    std::cout << "Name: " << enemy->GetClassName() << std::endl;
    std::cout << "HP: " << stat.stat[Stat::HP] << std::endl;
    std::cout << "MP: " << stat.stat[Stat::MP] << std::endl;
    std::cout << "ATK: " << stat.stat[Stat::ATK] << std::endl;
    std::cout << "DEF: " << stat.stat[Stat::DEF] << std::endl;
}

ItemID Enemy::DropItem()
{
    if (!enemy)
    {
        return ItemID::Slimeball;
    }

    return enemy->DropItem();
}
