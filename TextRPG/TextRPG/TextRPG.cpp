#include "GameStart.h"

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main(int argc, char* argv[])
{
    int HPPotion = 0;
    int MPPotion = 0;

    setPotion(5, &HPPotion, &MPPotion);
    GameStart(HPPotion, MPPotion);

    return 0;
}
