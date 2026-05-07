#pragma once
#include "Actor/Character/Character.h"

class Warrior : public Player
{
public:
    Warrior();
    std::string GetJobName() const override;
    void attack(Monster* monster) override;
};
