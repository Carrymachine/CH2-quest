#pragma once
#include <cctype>
#include <string>

struct RecipeIngredient
{
    std::string name;
    int count = 0;
};

struct PotionRecipe
{
    static constexpr int INGREDIENT_COUNT = 2;

    std::string potionName;
    RecipeIngredient ingredients[INGREDIENT_COUNT];

    static std::string NormalizeKey(const std::string& text)
    {
        std::string normalized;

        for (char ch : text)
        {
            if (!std::isspace(static_cast<unsigned char>(ch)))
            {
                normalized += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
            }
        }

        return normalized;
    }

    bool MatchesName(const std::string& name) const
    {
        return NormalizeKey(potionName) == NormalizeKey(name);
    }

    bool HasIngredient(const std::string& ingredient) const
    {
        for (int i = 0; i < INGREDIENT_COUNT; i++)
        {
            if (NormalizeKey(ingredients[i].name) == NormalizeKey(ingredient))
            {
                return true;
            }
        }

        return false;
    }

    std::string GetIngredientText() const
    {
        return ingredients[0].name + " x" + std::to_string(ingredients[0].count)
            + ", " + ingredients[1].name + " x" + std::to_string(ingredients[1].count);
    }

    std::string ToRecipeLine() const
    {
        return potionName + ": " + GetIngredientText();
    }

    std::string ToIngredientSearchLine() const
    {
        return potionName + " (" + GetIngredientText() + ")";
    }
};
