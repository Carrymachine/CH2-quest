#pragma once
#include "Actor/Character/Character.h"

class Thief : public Player
{
public:
    Thief();
    std::string GetJobName() const override;
    void attack(Monster* monster) override;
};
