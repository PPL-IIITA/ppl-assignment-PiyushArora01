#include "Boy.h"

Boy::Boy(int index, std::string name, int attractiveness, int intelligenceLevel, int type, int budget, int minAttraction) : Person(index, name, attractiveness, intelligenceLevel, type)
{
    //!Creates the boy
    this->budget = budget;
    this->minAttraction = minAttraction;
}

int Boy::getBudget()
{
    //!Returns boy's budget
    return this->budget;
}

int Boy::getMinAttraction()
{
    //!Returns boy's min attraction
    return this->minAttraction;
}

void Boy::setBudget(int budget)
{
    //!Sets budget
    this->budget = budget;
}

void Boy::setMinAttraction(int minAttraction)
{
    //!Sets min attraction
    this->minAttraction = minAttraction;
}