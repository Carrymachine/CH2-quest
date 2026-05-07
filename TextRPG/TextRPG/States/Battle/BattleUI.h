#pragma once
#include "Actor/Enemy/Enemy.h"
#include "Actor/Enemy/EnemyClass.h"
#include "Actor/Enemy/Normal.h"
#include "States/BaseUI.h"
#include "States/GameState.h"

class BattleUI : public BaseUI
{
    std::unique_ptr<Enemy> enemy;
    int battleFloor = 1;

public:
    BattleUI();
    ~BattleUI();


    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
    void RenderUI(const GameState* gameState) const override;

    void EnterBattle(int currentFloor);
};
