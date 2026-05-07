#pragma once
#include <memory>
#include <string>

#include "EnemyClass.h"
#include "Actor/Actor.h"
#include "_dic/ItemDropTable.h"

class Monster : public Actor
{
    std::unique_ptr<EnemyClass> enemy;

public:
    Monster();
    ~Monster();

    ActorType actorType = ActorType::Enemy;

    void SetEnemyStat(std::unique_ptr<EnemyClass> enemy_class)
    {
        enemy = std::move(enemy_class);

        if (enemy)
        {
            SetStat(enemy->SetBaseStat());
        }
    }

    void ShowStatus() const;
    std::string GetMonsterName() const;
    ItemID DropItem();
    int GetExpReward() const;
};

using Enemy = Monster;
