#include <iostream>
#include "GameStart.h"
#include "States/GameState.h"

void GameStart(int HPPotion, int MPPotion)
{
    GameState gameManager(HPPotion, MPPotion);
    while (gameManager.IsRunning())
    {
        gameManager.UIRenderer();
        gameManager.handleInput();
    }
}
