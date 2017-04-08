#include "Boy.h"
#include <string>

Boy::Boy(std::string name, int attractiveness, int budget, int intelligenceLevel, int minAttraction, int type)
{
    this->name = name;
    this->attractiveness = attractiveness;
    this->budget = budget;
    this->intelligenceLevel = intelligenceLevel;
    this->minAttraction = minAttraction;
    this->type = type;
    this->committed = 0;
}

std::string Boy::getName()
{
    return this->name;
}

int Boy::getAttractiveness()
{
    return this->attractiveness;
}

int Boy::getBudget()
{
    return this->budget;
}

int Boy::getIntelligenceLevel()
{
    return this->intelligenceLevel;
}

int Boy::getMinAttraction()
{
    return this->minAttraction;
}

bool Boy::isCommitted()
{
    return this->committed;
}

std::string Boy::getPartner()
{
    return this->partner;
}

int Boy::getType()
{
    return this->type;
}

double Boy::getHappiness()
{
    return this->happiness;
}

void Boy::setAttractiveness(int attractiveness)
{
    this->attractiveness = attractiveness;
}

void Boy::setBudget(int budget)
{
    this->budget = budget;
}

void Boy::setIntelligenceLevel(int intelligenceLevel)
{
    this->intelligenceLevel = intelligenceLevel;
}

void Boy::setCommitted(bool committed)
{
    this->committed = committed;
}

void Boy::setPartner(std::string partner)
{
    this->committed = 1;
    this->partner = partner;
}

void Boy::setType(int type)
{
    /*
    Type = 0 => Miser;
    Type = 1 => Generous;
    Type = 2 => Geeks;
    */
    this->type = type;
}

void Boy::setHappiness(double happiness)
{
    this->happiness = happiness;
}

void Boy::setMinAttraction(int minAttraction)
{
    this->minAttraction = minAttraction;
}