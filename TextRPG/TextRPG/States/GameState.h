#pragma once
#include <map>
#include <functional>
#include <cstdlib>

#include "Actor/Character/Character.h"


class BaseUI;

enum class UIState { CreateCharacterUI, CharacterStatus, Town, Dungeon, Battle, PotionShop };

enum class DungeonEvent { Nothing, EncounterEnemy, FindTreasure };

class GameState
{
    UIState prevUIState;
    UIState currentState = UIState::CreateCharacterUI;
    std::map<UIState, std::unique_ptr<BaseUI>> uiMap;

public:
    GameState();
    ~GameState();

    std::unique_ptr<Character> playerCharacter;

    DungeonEvent dungeonEventState = DungeonEvent::Nothing;
    bool visibleInventory = false;

    void ClearCLI() { system("cls"); }
    void SetPrevState(UIState previousState);
    UIState GetPrevState();

    void SetState(UIState newState);
    void SetPlayerCharacter(std::unique_ptr<Character> newCharacter);

    Character* GetPlayerCharacter() { return playerCharacter.get(); }
    const Character* GetPlayerCharacter() const { return playerCharacter.get(); }

    void InitUI();
    void UIRenderer();
    void handleInput();
};
