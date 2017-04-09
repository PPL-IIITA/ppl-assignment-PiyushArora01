#include "UtilityGift.h"

UtilityGift::UtilityGift(int index, int price, int value, bool taken, int utilityValue, int utilityClass) : Gift(index, price, value, taken)
{
    //!Utility Gift constructor
    this->utilityValue = utilityValue;
    this->utilityClass = utilityClass;
}

int UtilityGift::getUtilityValue()
{
    //!Return Utility Value
    return this->utilityValue;
}

int UtilityGift::getUtilityClass()
{
    //!Return Utility Class
    return this->utilityClass;
}

void UtilityGift::setUtilityValue(int utilityValue)
{
    //!Set utility value
    this->utilityValue = utilityValue;
}

void UtilityGift::setUtilityClass(int utilityClass)
{
    //!Set utility class
    this->utilityClass = utilityClass;
}