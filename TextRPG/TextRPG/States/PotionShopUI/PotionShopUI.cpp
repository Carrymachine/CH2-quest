#include "PotionShopUI.h"

#include <iostream>
#include <string>

PotionShopUI::PotionShopUI()
{
}

PotionShopUI::~PotionShopUI()
{
}

void PotionShopUI::HandleInput(GameState& gameState)
{
    bool isPotionShopOpen = true;

    while (isPotionShopOpen)
    {
        char input;
        std::cin >> input;

        switch (input)
        {
        case '1':
            workshop.ShowAllRecipes();
            break;
        case '2':
        {
            std::string potionName;
            std::cout << "Search potion name: ";
            std::getline(std::cin >> std::ws, potionName);
            workshop.SearchByName(potionName);
            break;
        }
        case '3':
        {
            std::string ingredientName;
            std::cout << "Search ingredient: ";
            std::getline(std::cin >> std::ws, ingredientName);
            workshop.SearchByIngredient(ingredientName);
            break;
        }
        case '0':
            gameState.SetState(gameState.GetPrevState());
            isPotionShopOpen = false;
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
        }

        if (isPotionShopOpen)
        {
            std::cout << "Input: ";
        }
    }
}

void PotionShopUI::RenderUI() const
{
    std::cout << "\n=== Potion Shop ===\n";
    std::cout << "1. Show all recipes\n";
    std::cout << "2. Search by potion name\n";
    std::cout << "3. Search by ingredient\n";
    std::cout << "0. Go back\n\n";
    std::cout << "Input: ";
}
