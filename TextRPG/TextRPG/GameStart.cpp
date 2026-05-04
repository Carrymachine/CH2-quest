#include <iostream>
#include "GameStart.h"
#include "States/GameState.h"

void GameStart()
{
    GameState gameManager;
    while (true)
    {
        gameManager.UIRenderer();
        gameManager.handleInput();
    }
}
