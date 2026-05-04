#include "DungeonUI.h"
#include <iostream>
#include <random>

DungeonUI::DungeonUI()
{
}

DungeonUI::~DungeonUI()
{
}


void DungeonUI::SetRandomizeEventState(GameState& gameState)
{
    dungeonStepCount++;
    // 하드웨어 기반 난수 시드 생성
    static std::random_device rd;
    // mt19937 = 난수엔진
    // 메르센 트위스터 알고리즘
    // gen() > 생성
    static std::mt19937 gen(rd());
    // 균등 분포 정수 생성기
    // dist() > 범위 지정 > 0 ~ 2 사이 정수
    static std::uniform_real_distribution<> dist(0, 2);


    gameState.dungeonEventState = static_cast<DungeonEvent>(dist(gen));
    if (gameState.dungeonEventState == DungeonEvent::EncounterEnemy) gameState.SetState(UIState::Battle);
}


void DungeonUI::HandleInput(GameState& gameState)
{
    char input;
    std::cin >> input;

    switch (gameState.dungeonEventState)
    {
    case DungeonEvent::Nothing:
        switch (input)
        {
        case '0':
            gameState.SetState(UIState::Town);
            break;
        case '1':
            SetRandomizeEventState(gameState);
            break;

        case '2':
            // inventory ui
            gameState.visibleInventory = !gameState.visibleInventory;
            break;
        }
        break;
    case DungeonEvent::EncounterEnemy:
        // battle ui
        break;
    case DungeonEvent::FindTreasure:
        switch (input)
        {
        case '1':
            // open treasure
            break;
        case '2':
            // skip
            break;
        }
    }
}

void DungeonUI::RenderUI() const
{
}

void DungeonUI::RenderUI(const GameState* gameState) const
{
    std::cout << "\n=====  Event  =====\n";
    std::cout << dungeonStepCount;

    switch (gameState->dungeonEventState)
    {
    case DungeonEvent::Nothing:
        RenderUIStateNothing();
        break;
    case DungeonEvent::EncounterEnemy:
        std::cout << "encounter enemy";

        break;
    case DungeonEvent::FindTreasure:
        RenderUIStateFineTreasure();
        break;
    }
    if (gameState->visibleInventory)
    {
        std::cout << "\n===== Inventory =====\n";
        gameState->GetPlayerCharacter()->ShowInventory();
    }

    std::cout << "\n===== Dungeon =====\n";
    std::cout << "1. Move\n";
    std::cout << "2. Inventory\n";
    std::cout << "0. Back to Town\n";
    std::cout << "Input: ";
}


void DungeonUI::RenderUIStateNothing() const
{
    std::cout << "Nothing happened..";
}

void DungeonUI::RenderUIStateFineTreasure() const
{
    std::cout << "You find treasure!!";
}
