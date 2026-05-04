#pragma once
#include "EnemyClass.h"
#include "Actor/Actor.h"
#include "Actor/Character/Character.h"
#include "_dic/ItemDropTable.h"

class Enemy : public Actor
{
    std::unique_ptr<EnemyClass> enemy;

public:
    Enemy();
    ~Enemy();

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
    ItemID DropItem();
};
