#pragma once
#include "EnemyClass.h"

class Boss : public EnemyClass
{
    std::string className = "Boss";

public:
    Stat SetBaseStat() const override
    {
        Stat stat;

        stat.stat[Stat::HP] = 30;
        stat.stat[Stat::MP] = 10;
        stat.stat[Stat::ATK] = 6;
        stat.stat[Stat::DEF] = 8;

        return stat;
    }

    std::string GetClassName() const override
    {
        return className;
    }

    ItemID DropItem() const override
    {
        return ItemID::MisticShard;
    }
};
