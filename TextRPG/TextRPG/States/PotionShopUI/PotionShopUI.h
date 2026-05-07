#pragma once
#include "Alchemy/AlchemyWorkshop.h"
#include "States/BaseUI.h"

class PotionShopUI : public BaseUI
{
    PotionWorkshop potionWorkshop;

public:
    PotionShopUI();
    ~PotionShopUI();

    void HandleInput(GameState& gameState) override;
    void RenderUI() const override;
};
