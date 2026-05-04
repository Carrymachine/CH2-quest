#pragma once
#include "GameState.h"

class BaseUI
{
public:
    ~BaseUI() = default;
    virtual void HandleInput(GameState& gameState) = 0;
    virtual void RenderUI() const = 0;

    virtual void RenderUI(const GameState* gameState) const
    {
        RenderUI();
    }
};
