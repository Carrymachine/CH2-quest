#pragma once
#include <string>
#include <vector>

#include "PotionRecipe.h"

class PotionWorkshop
{
    std::vector<PotionRecipe> recipes;

public:
    PotionWorkshop();

    void ShowAllRecipes() const;
    void SearchByName(const std::string& name) const;
    void SearchByIngredient(const std::string& ingredient) const;
};
