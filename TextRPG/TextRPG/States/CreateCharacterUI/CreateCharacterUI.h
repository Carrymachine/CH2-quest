#pragma once
#include "States/BaseUI.h"
#include <string>
#include <vector>

class CreateCharacterUI : public BaseUI
{
    const std::vector<std::string> steps = {
        "What is your name? \n Input: ", "What is your job(class)? \n 1. Warrior \n 2. Mage \n Input: "
        , "Enter HP and MP: ", "Enter ATK and DEF: "

    };
    int currentStep = 0;

    std::string tempName;
    JobState tempJobName;

public:
    CreateCharacterUI();
    ~CreateCharacterUI();

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
};
