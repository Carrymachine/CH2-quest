#include "CharacterStatusUI.h"

#include <iostream>

CharacterStatusUI::CharacterStatusUI()
{
}

CharacterStatusUI::~CharacterStatusUI()
{
}

void CharacterStatusUI::RenderUI() const
{
}


void CharacterStatusUI::RenderUI(const GameState* gameState) const
{
    std::cout << "\n=====  Player Status  =====\n";

    gameState->GetPlayerCharacter()->ShowStatus();
    std::cout << "\n=== Character Status UI ===\n";
    std::cout << "1. Back\n";
    std::cout << "Input: ";
}

void CharacterStatusUI::HandleInput(GameState& gameState)
{
    char input;

    std::cin >> input;

    switch (input)
    {
    case '1':
        gameState.SetState(gameState.GetPrevState());
    }
}
