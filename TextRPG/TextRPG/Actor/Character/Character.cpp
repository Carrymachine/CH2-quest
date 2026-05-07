#include "Character.h"

#include <iostream>
#include <ostream>

Player::Player()
{
}

Player::~Player()
{
}

void Player::SetName(std::string newName)
{
    name = newName;
}

void Player::printPlayerStatus() const
{
    const Stat& stat = GetStat();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Player Job: " << GetJobName() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "EXP: " << exp << " / " << maxExp << std::endl;
    std::cout << "HP: " << stat.stat[Stat::HP] << std::endl;
    std::cout << "MP: " << stat.stat[Stat::MP] << std::endl;
    std::cout << "ATK: " << stat.stat[Stat::ATK] << std::endl;
    std::cout << "DEF: " << stat.stat[Stat::DEF] << std::endl;
}

void Player::ShowStatus() const
{
    printPlayerStatus();
}

void Player::GainExp(int amount)
{
    if (amount <= 0)
    {
        return;
    }

    exp += amount;
    std::cout << "Gained EXP: " << amount << std::endl;

    if (exp >= maxExp)
    {
        LevelUp();
    }
}

void Player::LevelUp()
{
    level++;
    stat.stat[Stat::HP] += 10;
    stat.stat[Stat::MP] += 5;
    stat.stat[Stat::ATK] += 2;
    stat.stat[Stat::DEF] += 2;
    exp = 0;
    maxExp += 50;

    std::cout << "Level Up! Current Level: " << level << std::endl;
}

void Player::AddItemToInventory(ItemID item, int count)
{
    if (count <= 0)
    {
        return;
    }

    inventory[item] += count;
}

bool Player::RemoveItemFromInventory(ItemID item)
{
    const auto it = inventory.find(item);

    if (it == inventory.end())
    {
        return false;
    }

    it->second--;

    if (it->second <= 0)
    {
        inventory.erase(it);
    }

    return true;
}

int Player::GetItemCount(ItemID item) const
{
    const auto it = inventory.find(item);

    if (it == inventory.end())
    {
        return 0;
    }

    return it->second;
}

void Player::ShowInventory() const
{
    if (inventory.empty())
    {
        std::cout << "Nothing ...";
    }
    else
    {
        int index = 1;

        for (const auto& [itemId, count] : inventory)
        {
            const auto it = ItemDropTable::ItemNameTable.find(itemId);

            if (it != ItemDropTable::ItemNameTable.end())
            {
                std::cout << index << ". " << it->second << " - " << count << std::endl;
                index++;
            }
        }
    }
}
