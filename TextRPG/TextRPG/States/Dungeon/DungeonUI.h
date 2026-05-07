#pragma once
#include "States/BaseUI.h"


class DungeonUI : public BaseUI
{
    static constexpr int NORMAL_FLOOR_COUNT = 3;
    static constexpr int BOSS_FLOOR = 4;
    static constexpr int STEPS_PER_FLOOR = 10;

    int currentFloor = 1;
    int currentFloorStep = 0;

public:
    DungeonUI();
    ~DungeonUI();

    void SetRandomizeEventState(GameState& gameState);
    int GetCurrentFloor() const { return currentFloor; }
    int GetCurrentFloorStep() const { return currentFloorStep; }

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
    void RenderUI(const GameState* gameState) const override;

    void RenderUIStateNothing() const;
    void RenderUIStateFineTreasure() const;
};
