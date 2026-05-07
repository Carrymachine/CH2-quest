#include "AlchemyWorkshop.h"

#include <iostream>

PotionWorkshop::PotionWorkshop()
{
    recipes.push_back({
        "HP Potion",
        {
            {"Slime Ball", 1},
            {"Bone", 2}
        }
        });

    recipes.push_back({
        "MP Potion",
        {
            {"Slime Ball", 2},
            {"Bone", 1}
        }
        });

    recipes.push_back({
        "Stamina Potion",
        {
            {"Mistic Shard", 1},
            {"HP Potion", 1}
        }
        });
}

void PotionWorkshop::ShowAllRecipes() const
{
    for (const PotionRecipe& recipe : recipes)
    {
        std::cout << "-> " << recipe.ToRecipeLine() << std::endl;
    }
}

void PotionWorkshop::SearchByName(const std::string& name) const
{
    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.MatchesName(name))
        {
            std::cout << "-> " << recipe.ToRecipeLine() << std::endl;
            return;
        }
    }

    std::cout << "찾을 수 없습니다" << std::endl;
}

void PotionWorkshop::SearchByIngredient(const std::string& ingredient) const
{
    int foundCount = 0;

    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.HasIngredient(ingredient))
        {
            std::cout << "-> " << recipe.ToIngredientSearchLine() << std::endl;
            foundCount++;
        }
    }

    if (foundCount == 0)
    {
        std::cout << "찾을 수 없습니다" << std::endl;
    }

    std::cout << "Found " << foundCount << " recipes." << std::endl;
}
