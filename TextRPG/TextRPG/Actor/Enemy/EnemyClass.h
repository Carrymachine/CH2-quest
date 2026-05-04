#pragma once
#include <string>

#include "Actor/Stat.h"
#include "_dic/ItemDropTable.h"

enum class EnemyClassState { Normal, Boss };

class EnemyClass
{
public:
    virtual Stat SetBaseStat() const = 0;
    virtual std::string GetClassName() const = 0;
    virtual ItemID DropItem() const = 0;
};
