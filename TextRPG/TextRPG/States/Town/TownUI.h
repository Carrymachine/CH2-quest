#pragma once
#include "States/BaseUI.h"

class TownUI : public BaseUI
{
public:
    TownUI();
    ~TownUI();

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
    void RenderUI(const GameState* gameState) const override;
};
