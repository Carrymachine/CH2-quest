#include "Character.h"

#include <iostream>
#include <ostream>

Character::Character()
{
}

Character::~Character()
{
}

void Character::SetName(std::string newName)
{
    name = newName;
}

void Character::ShowStatus() const
{
    const Stat& stat = GetStat();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Player Job: " << characterJob->GetJobName() << std::endl;
    std::cout << "HP: " << stat.stat[Stat::HP] << std::endl;
    std::cout << "MP: " << stat.stat[Stat::MP] << std::endl;
    std::cout << "ATK: " << stat.stat[Stat::ATK] << std::endl;
    std::cout << "DEF: " << stat.stat[Stat::DEF] << std::endl;
}

void Character::AddItemToInventory(ItemID item, int count)
{
    if (count <= 0)
    {
        return;
    }

    inventory[item] += count;
}

bool Character::RemoveItemFromInventory(ItemID item)
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

int Character::GetItemCount(ItemID item) const
{
    const auto it = inventory.find(item);

    if (it == inventory.end())
    {
        return 0;
    }

    return it->second;
}

void Character::ShowInventory() const
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
