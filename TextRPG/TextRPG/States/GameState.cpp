#include "GameState.h"
#include <iostream>

#include "Battle/BattleUI.h"
#include "CharacterStatusUI/CharacterStatusUI.h"
#include "CreateCharacterUI/CreateCharacterUI.h"
#include "Dungeon/DungeonUI.h"
#include "PotionShopUI/PotionShopUI.h"
#include "Town/TownUI.h"

GameState::GameState(int HPPotionCount, int MPPotionCount)
{
    initialHPPotionCount = HPPotionCount;
    initialMPPotionCount = MPPotionCount;
    InitUI();
}

GameState::~GameState()
{
}

void GameState::SetPrevState(UIState previousState)
{
    prevUIState = previousState;
}

UIState GameState::GetPrevState()
{
    return prevUIState;
}
 
void GameState::SetState(UIState newState)
{
    currentState = newState;

    if (newState == UIState::Battle)
    {
        auto* battleUI = dynamic_cast<BattleUI*>(uiMap[UIState::Battle].get());
        auto* dungeonUI = dynamic_cast<DungeonUI*>(uiMap[UIState::Dungeon].get());

        if (battleUI && dungeonUI)
        {
            battleUI->EnterBattle(dungeonUI->GetCurrentFloor());
        }
    }
}

void GameState::SetPlayerCharacter(std::unique_ptr<Character> newCharacter)
{
    playerCharacter = std::move(newCharacter);
}

void GameState::InitUI()
{
    uiMap[UIState::Town] = std::make_unique<TownUI>();
    uiMap[UIState::Dungeon] = std::make_unique<DungeonUI>();
    uiMap[UIState::CharacterStatus] = std::make_unique<CharacterStatusUI>();
    uiMap[UIState::CreateCharacterUI] = std::make_unique<CreateCharacterUI>();
    uiMap[UIState::Battle] = std::make_unique<BattleUI>();
    uiMap[UIState::PotionShop] = std::make_unique<PotionShopUI>();
}


void GameState::UIRenderer()
{
    ClearCLI();
    auto iterator = uiMap.find(currentState);

    if (iterator != uiMap.end())
    {
        iterator->second->RenderUI(this);
    }
}

void GameState::handleInput()
{
    auto iterator = uiMap.find(currentState);

    if (iterator != uiMap.end())
    {
        iterator->second->HandleInput(*this);
    }
}
