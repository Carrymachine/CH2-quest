#include "CreateCharacterUI.h"

#include <iostream>

#include "Actor/Character/Job/Archer.h"
#include "Actor/Character/Job/Mage.h"
#include "Actor/Character/Job/Thief.h"
#include "Actor/Character/Job/Warrior.h"

namespace
{
    void PrintCharacterUpgradeMenu()
    {
        std::cout << "============================================\n";
        std::cout << "< Character Upgrade >\n";
        std::cout << "1. HP UP    2. MP UP    3. Attack x2\n";
        std::cout << "4. Defense x2  5. Show Stats  0. Start Game\n";
        std::cout << "============================================\n";
    }

    void RunCharacterUpgradeMenu(Character* character, int HPPotionCount, int MPPotionCount)
    {
        if (character == nullptr)
        {
            return;
        }

        character->AddItemToInventory(ItemID::HPPotion, HPPotionCount);
        character->AddItemToInventory(ItemID::MPPotion, MPPotionCount);

        std::cout << "* You received " << HPPotionCount << " HP Potions and "
            << MPPotionCount << " MP Potions.\n";
        PrintCharacterUpgradeMenu();

        bool isGameStart = false;

        while (!isGameStart)
        {
            int choice;
            std::cout << "Input: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                if (!character->RemoveItemFromInventory(ItemID::HPPotion))
                {
                    std::cout << "포션 부족\n";
                    break;
                }

                character->stat.stat[Stat::HP] += 20;
                std::cout << "* HP increased by 20. (HP Potion used: "
                    << character->GetItemCount(ItemID::HPPotion) << " left)\n";
                break;
            case 2:
                if (!character->RemoveItemFromInventory(ItemID::MPPotion))
                {
                    std::cout << "포션 부족\n";
                    break;
                }

                character->stat.stat[Stat::MP] += 20;
                std::cout << "* MP increased by 20. (MP Potion used: "
                    << character->GetItemCount(ItemID::MPPotion) << " left)\n";
                break;
            case 3:
                character->stat.stat[Stat::ATK] *= 2;
                std::cout << "* Attack doubled.\n";
                break;
            case 4:
                character->stat.stat[Stat::DEF] *= 2;
                std::cout << "* Defense doubled.\n";
                break;
            case 5:
                character->ShowStatus();
                break;
            case 0:
                std::cout << "Starting the game!\n";
                isGameStart = true;
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        }
    }
}

CreateCharacterUI::CreateCharacterUI()
{
}

CreateCharacterUI::~CreateCharacterUI()
{
}

void CreateCharacterUI::HandleInput(GameState& gameState)
{
    if (currentStep == 0)
    {
        std::string name;
        std::cin >> name;
        tempName = name;

        currentStep++;
        return;
    }

    if (currentStep == 1)
    {
        char input;
        std::cin >> input;

        std::unique_ptr<Character> character;

        switch (input)
        {
        case '1':
            character = std::make_unique<Warrior>();
            break;
        case '2':
            character = std::make_unique<Mage>();
            break;
        case '3':
            character = std::make_unique<Archer>();
            break;
        case '4':
            character = std::make_unique<Thief>();
            break;
        default:
            return;
        }

        character->SetName(tempName);
        gameState.SetPlayerCharacter(std::move(character));
        currentStep++;
        return;
    }

    if (currentStep == 2)
    {
        int hp, mp;
        std::cin >> hp >> mp;

        gameState.GetPlayerCharacter()->stat.stat[Stat::HP] = hp;
        gameState.GetPlayerCharacter()->stat.stat[Stat::MP] = mp;
        currentStep++;
        return;
    }

    if (currentStep == 3)
    {
        int atk, def;
        std::cin >> atk >> def;

        if (atk < 5)
        {
            atk = 5;
        }

        if (def < 5)
        {
            def = 5;
        }

        gameState.GetPlayerCharacter()->stat.stat[Stat::ATK] = atk;
        gameState.GetPlayerCharacter()->stat.stat[Stat::DEF] = def;

        RunCharacterUpgradeMenu(
            gameState.GetPlayerCharacter(),
            gameState.GetInitialHPPotionCount(),
            gameState.GetInitialMPPotionCount()
        );
        currentStep = 0;
        gameState.SetState(UIState::Town);
    }
}

void CreateCharacterUI::RenderUI() const
{
    std::cout << "\n=== Create Your Character ===\n";
    if (currentStep < steps.size())
    {
        std::cout << steps[currentStep];
    }
}
