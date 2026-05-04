#pragma once

struct Stat
{
    enum Index
    {
        HP = 0,
        MP,
        ATK,
        DEF
    };

    static constexpr int SIZE = 4;

    int stat[SIZE] = { 0 };
    int increaseStat[SIZE] = { 0 };
};
