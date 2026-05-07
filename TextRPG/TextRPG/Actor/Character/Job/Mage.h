#pragma once
#include "Actor/Character/Character.h"

class Mage : public Player
{
public:
    Mage();
    std::string GetJobName() const override;
    void attack(Monster* monster) override;
};
