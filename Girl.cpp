#include "Girl.h"

Girl::Girl(std::string name, int attractiveness, int maintenanceCost, int intelligenceLevel, int type, int boyChoice)
{
    this->name = name;
    this->attractiveness = attractiveness;
    this->maintenanceCost = maintenanceCost;
    this->intelligenceLevel = intelligenceLevel;
    this->type = type;
    this->boyChoice = boyChoice;
}

std::string Girl::getName()
{
    return this->name;
}

int Girl::getAttractiveness()
{
    return this->attractiveness;
}

int Girl::getMaintenanceCost()
{
    return this->maintenanceCost;
}

int Girl::getIntelligenceLevel()
{
    return this->intelligenceLevel;
}

bool Girl::isCommitted()
{
    return this->committed;
}

std::string Girl::getPartner()
{
    return this->partner;
}

int Girl::getType()
{
    return this->type;
}

int Girl::getBoyChoice()
{
    return this->boyChoice;
}

double Girl::getHappiness()
{
    return this->happiness;
}

void Girl::setAttractiveness(int attractiveness)
{
    this->attractiveness = attractiveness;
}

void Girl::setMaintenanceCost(int maintenanceCost)
{
    this->maintenanceCost = maintenanceCost;
}

void Girl::setIntelligenceLevel(int intelligenceLevel)
{
    this->intelligenceLevel = intelligenceLevel;
}

void Girl::setCommitted(bool committed)
{
    this->committed = committed;
}

void Girl::setPartner(std::string partner)
{
    this->committed = 1;
    this->partner = partner;
}

void Girl::setType(int type)
{
    /*
    Type = 0 => Choosy;
    Type = 1 => Normal;
    Type = 2 => Desperate;
    */
    this->type = type;
}

void Girl::setBoyChoice(int boyChoice)
{
    /*
    BoyChoice = 0 => Most attractive;
    BoyChoice = 1 => Most rich;
    BoyChoice = 2 => Most intelligent;
    */
    this->boyChoice = boyChoice;
}

void Girl::setHappiness(double happiness)
{
    this->happiness = happiness;
}