#pragma once
#include "Job.h"


class Warrior : public Job
{
    std::string jobName = "Warrior";

    Stat SetBaseStat() const override
    {
        Stat stat;
        stat.stat[Stat::HP] = 0;
        stat.stat[Stat::MP] = 0;
        stat.stat[Stat::ATK] = 0;
        stat.stat[Stat::DEF] = 0;

        return stat;
    }

    std::string GetJobName() const override
    {
        return jobName;
    };
};
