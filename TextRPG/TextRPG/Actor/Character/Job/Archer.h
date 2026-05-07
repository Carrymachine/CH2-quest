#pragma once
#include "Actor/Character/Character.h"

class Archer : public Player
{
public:
    Archer();
    std::string GetJobName() const override;
    void attack(Monster* monster) override;
};
