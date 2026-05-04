#include "TownUI.h"
#include <iostream>

TownUI::TownUI()
{
}

TownUI::~TownUI()
{
}

void TownUI::HandleInput(GameState& gameState)
{
    char input;
    std::cin >> input;

    switch (input)
    {
    case '1':
        gameState.SetState(UIState::Dungeon);
        gameState.SetPrevState(UIState::Town);
        break;
    case '2':
        gameState.SetState(UIState::CharacterStatus);
        gameState.SetPrevState(UIState::Town);
        break;
    case '3':
        gameState.SetState(UIState::PotionShop);
        gameState.SetPrevState(UIState::Town);
        break;
    case '4':
        gameState.visibleInventory = !gameState.visibleInventory;
        break;
    }
}

void TownUI::RenderUI() const
{
}

void TownUI::RenderUI(const GameState* gameState) const
{
    if (gameState->visibleInventory)
    {
        std::cout << "\n===== Inventory =====\n";
        gameState->GetPlayerCharacter()->ShowInventory();
    }
    std::cout << "\n=== Town ===\n";
    std::cout << "1. Dungeon\n";
    std::cout << "2. Player Status\n";
    std::cout << "3. Potion Shop\n";
    std::cout << "4. Inventory\n";
    std::cout << "Input: ";
}
