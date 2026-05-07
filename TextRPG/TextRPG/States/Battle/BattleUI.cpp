#include "BattleUI.h"

#include "Actor/Enemy/Boss.h"
#include "Actor/Enemy/Normal.h"

BattleUI::BattleUI()
{
    EnterBattle(1);
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
        gameState.playerCharacter->attack(enemy.get());

        if (enemy->stat.stat[Stat::HP] <= 0)
        {
            const ItemID dropItem = enemy->DropItem();
            const int expReward = enemy->GetExpReward();
            gameState.playerCharacter->AddItemToInventory(dropItem);
            gameState.playerCharacter->GainExp(expReward);

            const auto itemName = ItemDropTable::ItemNameTable.find(dropItem);

            if (itemName != ItemDropTable::ItemNameTable.end())
            {
                std::cout << "Dropped item: " << itemName->second << std::endl;
            }

            if (battleFloor >= 4)
            {
                std::cout << "\n===== Game Clear =====\n";
                std::cout << "You cleared Floor 4!\n";
                std::cout << "\n===== Final Character Status =====\n";
                gameState.playerCharacter->ShowStatus();
                gameState.EndGame();
                return;
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


void BattleUI::EnterBattle(int currentFloor)
{
    battleFloor = currentFloor;
    enemy = std::make_unique<Enemy>();

    if (currentFloor >= 4)
    {
        enemy->SetEnemyStat(std::make_unique<Boss>());
        return;
    }

    enemy->SetEnemyStat(std::make_unique<Normal>());
}
