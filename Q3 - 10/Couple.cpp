#include "Couple.h"

Couple::Couple(int index, int boy, int girl)
{
    //!Creates a couple 
    this->index = index;
    this->boy = boy;
    this->girl = girl;
    this->boyHappiness = 0;
    this->girlHappiness = 0;
    this->coupleHappiness = 0;
    this->coupleCompatibility = 0;
    this->totalMoneySpent = 0;
    this->totalValueGift = 0;
    this->totalLuxValue = 0;
}

Couple::Couple(int index, int boy, int girl, double boyHappiness, double girlHappiness, double coupleHappiness, double coupleCompatibility, int totalMoneySpent, int totalValueGift, int totalLuxValue)
{
    //!Restores a couple
    this->index = index;
    this->boy = boy;
    this->girl = girl;
    this->boyHappiness = boyHappiness;
    this->girlHappiness = girlHappiness;
    this->coupleHappiness = coupleHappiness;
    this->coupleCompatibility = coupleCompatibility;
    this->totalMoneySpent = totalMoneySpent;
    this->totalValueGift = totalValueGift;
    this->totalLuxValue = totalLuxValue;
}

int Couple::getIndex()
{
    //!Return couple's index
    return this->index;
}

int Couple::getBoy()
{
    //!Boy's index
    return this->boy;
}

int Couple::getGirl()
{
    //!Girl's index
    return this->girl;
}

double Couple::getBoyHappiness()
{
    return this->boyHappiness;
}

double Couple::getGirlHappiness()
{
    return this->girlHappiness;
}

double Couple::getCoupleHappiness()
{
    return this->coupleHappiness;
}

double Couple::getCoupleCompatibility()
{
    return this->coupleCompatibility;
}

int Couple::getTotalMoneySpent()
{
    return this->totalMoneySpent;
}

int Couple::getTotalValueGift()
{
    return this->totalValueGift;
}

int Couple::getTotalLuxValue()
{
    return this->totalLuxValue;
}

void Couple::setBoy(int boy)
{
    this->boy = boy;
}

void Couple::setGirl(int girl)
{
    this->girl = girl;
}

void Couple::setBoyHappiness(double boyHappiness)
{
    this->boyHappiness = boyHappiness;
}

void Couple::setGirlHappiness(double girlHappiness)
{
    this->girlHappiness = girlHappiness;
}

void Couple::setCoupleHappiness(double coupleHappiness)
{
    this->coupleHappiness = coupleHappiness;
}

void Couple::setCoupleCompatibility(double coupleCompatibility)
{
    this->coupleCompatibility = coupleCompatibility;
}

void Couple::setTotalMoneySpent(int totalMoneySpent)
{
    this->totalMoneySpent = totalMoneySpent;
}

void Couple::setTotalValueGift(int totalValueGift)
{
    this->totalValueGift = totalValueGift;
}

void Couple::setTotalLuxValue(int totalLuxValue)
{
    this->totalLuxValue = totalLuxValue;
}