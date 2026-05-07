#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <string>

#include "Actor/Actor.h"
#include "_dic/ItemDropTable.h"

class Monster;

class Player : public Actor
{
    std::string name;
    std::map<ItemID, int> inventory;
    int exp = 0;
    int maxExp = 100;
    int level = 1;

public:
    Player();
    virtual ~Player();
    ActorType actorType = ActorType::Player;


    void SetName(std::string newName);
    std::string GetName() const { return name; }
    virtual std::string GetJobName() const = 0;
    virtual void attack(Monster* monster) = 0;

    void printPlayerStatus() const;
    void ShowStatus() const;
    void GainExp(int amount);
    void LevelUp();

    void AddItemToInventory(ItemID item, int count = 1);
    bool RemoveItemFromInventory(ItemID item);
    int GetItemCount(ItemID item) const;
    void ShowInventory() const;
};

using Character = Player;
