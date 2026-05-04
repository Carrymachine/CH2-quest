#pragma once
#include "Stat.h"

enum class ActorType { Player, Enemy };

class Actor
{
public:
    ActorType actorType;
    Stat stat;
    void Move();
    void Attack();
    void Skill();
    void UseItem();

    // stat
    void SetStat(const Stat& newStat)
    {
        stat = newStat;
    }

    const Stat& GetStat() const
    {
        return stat;
    }


    void Attack(Actor& provider, Actor& receiver)
    {
        receiver.ApplyDamage(provider.stat.stat[Stat::ATK]);
        if (receiver.stat.stat[Stat::HP] <= 0)
        {
            Death(receiver, provider);
        }
    }

    void ApplyDamage(int damage)
    {
        stat.stat[Stat::HP] -= damage;
    }

    void Death(Actor& deathActor, Actor& deathBy)
    {
        if (deathActor.actorType == ActorType::Player)
        {
        }

        if (deathActor.actorType == ActorType::Enemy)
        {
            //인벤토리 아이템 추가
        }
    }
};
