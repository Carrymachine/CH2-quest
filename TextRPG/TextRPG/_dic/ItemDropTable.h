#pragma once
#include <map>
#include <string>

enum class ItemID
{
    Slimeball = 1, Bone = 2, MisticShard = 3, HPPotion = 4, MPPotion = 5
};

class ItemDropTable
{
public:
    inline static const std::map<ItemID, std::string> ItemNameTable = {
        {ItemID::Slimeball, "Slime Ball"}, {ItemID::Bone, "Bone"}, {ItemID::MisticShard, "Mistic Shard"}
        , {ItemID::HPPotion, "HP Potion"}, {ItemID::MPPotion, "MP Potion"}
    };
};
