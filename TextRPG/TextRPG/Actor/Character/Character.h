#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <string>

#include "Actor/Actor.h"
#include "Job/Job.h"
#include "_dic/ItemDropTable.h"

class Character : public Actor
{
    std::unique_ptr<Job> characterJob;
    std::string name;
    std::map<ItemID, int> inventory;

public:
    Character();
    ~Character();
    ActorType actorType = ActorType::Player;


    void SetName(std::string newName);

    void SetJob(std::unique_ptr<Job> newJob)
    {
        characterJob = std::move(newJob);

        if (characterJob)
        {
            SetStat(characterJob->SetBaseStat());
        }
    }

    void ShowStatus() const;

    void AddItemToInventory(ItemID item, int count = 1);
    bool RemoveItemFromInventory(ItemID item);
    int GetItemCount(ItemID item) const;
    void ShowInventory() const;
};
