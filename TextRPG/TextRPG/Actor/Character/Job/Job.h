#pragma once
#include <functional>
#include <map>
#include <string>

#include "Actor/Stat.h"

enum class JobState { Warrior, Mage, Archer, Thief };

class Job
{
    std::map<char, std::function<void()>> jobFuncMap;

public:
    virtual Stat SetBaseStat() const = 0;
    virtual std::string GetJobName() const = 0;
};
