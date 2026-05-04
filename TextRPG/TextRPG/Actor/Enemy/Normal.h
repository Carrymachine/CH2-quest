#pragma once
#include <random>

#include "Enemy.h"
#include "EnemyClass.h"

class Normal : public EnemyClass
{
    std::string className = "Normal";

public:
    Stat SetBaseStat() const override
    {
        Stat stat;

        stat.stat[Stat::HP] = 10;
        stat.stat[Stat::MP] = 0;
        stat.stat[Stat::ATK] = 1;
        stat.stat[Stat::DEF] = 5;

        return stat;
    }

    std::string GetClassName() const override
    {
        return className;
    }

    ItemID DropItem() const override
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dist(0, 1);

        return dist(gen) == 0 ? ItemID::Slimeball : ItemID::Bone;
    }
};
