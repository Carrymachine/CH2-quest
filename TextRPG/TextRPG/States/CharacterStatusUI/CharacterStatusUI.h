#pragma once
#include "States/BaseUI.h"

class CharacterStatusUI : public BaseUI
{
public:
    CharacterStatusUI();
    ~CharacterStatusUI();

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
    void RenderUI(const GameState* gameState) const override;
};
