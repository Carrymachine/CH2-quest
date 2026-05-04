#pragma once
#include "States/BaseUI.h"


class DungeonUI : public BaseUI
{
    int dungeonStepCount = 0;

public:
    DungeonUI();
    ~DungeonUI();

    void SetRandomizeEventState(GameState& gameState);
    int GetDungeonStepCount() const { return dungeonStepCount; }

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
    void RenderUI(const GameState* gameState) const override;

    void RenderUIStateNothing() const;
    void RenderUIStateFineTreasure() const;
};
