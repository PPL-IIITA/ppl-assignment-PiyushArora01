#include "Girl.h"

Girl::Girl(int index, std::string name, int attractiveness, int intelligenceLevel, int type, int maintenanceCost, int boyChoice) : Person(index, name, attractiveness, intelligenceLevel, type)
{
    //!Girl constructor
    this->maintenanceCost = maintenanceCost;
    this->boyChoice = boyChoice;
}

int Girl::getMaintenanceCost()
{
    //!Return girl's maintenance cost
    return this->maintenanceCost;
}

int Girl::getBoyChoice()
{
    //!Return her boy's choice
    return this->boyChoice;
}

void Girl::setMaintenanceCost(int maintenanceCost)
{
    //!Set maintenance cost
    this->maintenanceCost = maintenanceCost;
}

void Girl::setBoyChoice(int boyChoice)
{
    //!Set her boy preference
    /*!
    BoyChoice = 0 => Most attractive;
    BoyChoice = 1 => Most rich;
    BoyChoice = 2 => Most intelligent;
    !*/
    this->boyChoice = boyChoice;
}