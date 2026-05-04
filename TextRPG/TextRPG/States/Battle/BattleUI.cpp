#include "BattleUI.h"

#include "Actor/Enemy/Boss.h"
#include "Actor/Enemy/Normal.h"

BattleUI::BattleUI()
{
    EnterBattle(0);
}

BattleUI::~BattleUI()
{
}

void BattleUI::HandleInput(GameState& gameState)
{
    char input;
    std::cin >> input;

    switch (input)
    {
    case '1':
        gameState.playerCharacter->Attack(*gameState.playerCharacter, *enemy);

        if (enemy->stat.stat[Stat::HP] <= 0)
        {
            const ItemID dropItem = enemy->DropItem();
            gameState.playerCharacter->AddItemToInventory(dropItem);

            const auto itemName = ItemDropTable::ItemNameTable.find(dropItem);

            if (itemName != ItemDropTable::ItemNameTable.end())
            {
                std::cout << "Dropped item: " << itemName->second << std::endl;
            }

            enemy.reset();
            gameState.SetState(UIState::Dungeon);
            gameState.dungeonEventState = DungeonEvent::Nothing;
        }
        else
        {
            enemy->Attack(*enemy, *gameState.playerCharacter);
        }

        if (gameState.playerCharacter->stat.stat[Stat::HP] <= 0)
        {
            gameState.SetState(UIState::Town);
        }
        break;
    case '3':
        gameState.SetState(UIState::Dungeon);
        gameState.dungeonEventState = DungeonEvent::Nothing;
        break;
    }
}

void BattleUI::RenderUI() const
{
}

void BattleUI::RenderUI(const GameState* gameState) const
{
    std::cout << "\n=====  Event  =====\n";
    std::cout << "\n=====  Player  =====\n";
    gameState->GetPlayerCharacter()->ShowStatus();
    std::cout << "\n=====  Enemy  =====\n";
    enemy->ShowStatus();

    std::cout << "\n===== Battle =====\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Skill\n";
    std::cout << "3. Run\n";
    std::cout << "Input: ";
}


void BattleUI::EnterBattle(int dungeonStepCount)
{
    enemy = std::make_unique<Enemy>();

    if (dungeonStepCount >= 6)
    {
        enemy->SetEnemyStat(std::make_unique<Boss>());
        return;
    }

    enemy->SetEnemyStat(std::make_unique<Normal>());
}
