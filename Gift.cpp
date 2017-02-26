#include "Gift.h"

/*
Type = 0 => Essential Gift;
Type = 1 => Luxury Gift;
Type = 2 => Utility Gift;
*/

Gift::Gift(int price, int value)
{
    int type = 0;
    this->price = price;
    this->value = value;
}

Gift::Gift(int price, int value, int luxuryRating, int luxuryDifficultyToObtain)
{
    int type = 1;
    this->price = price;
    this->value = value;
    this->luxuryRating = luxuryRating;
    this->luxuryDifficultyToObtain = this->luxuryDifficultyToObtain;    
}

Gift::Gift(int price, int value, int utilityValue, long utilityClass)
{
    int type = 2;
    this->price = price;
    this->value = value;
    this->utilityValue = utilityValue;
    this->utilityClass = utilityClass;
}

int Gift::getType()
{
    return this->type;
}

int Gift::getPrice()
{
    return this->price;
}

int Gift::getValue()
{
    return this->value;
}

int Gift::getLuxuryRating()
{
    return this->luxuryRating;
}

int Gift::getLuxuryDifficultyToObtain()
{
    return this->luxuryDifficultyToObtain;
}

int Gift::getUtilityValue()
{
    return this->utilityValue;
}

int Gift::getUtilityClass()
{
    return this->utilityClass;
}

void Gift::setPrice(int price)
{
    this->price = price;
}

void Gift::setValue(int value)
{
    this->value = value;
}

void Gift::setLuxuryRating(int luxuryRating)
{
    this->luxuryRating = luxuryRating;
}

void Gift::setLuxuryDifficultyToObtain(int luxuryDifficultyToObtain)
{
    this->luxuryDifficultyToObtain = luxuryDifficultyToObtain;
}

void Gift::setUtilityValue(int utilityValue)
{
    this->utilityValue = utilityValue;
}

void Gift::setUtilityClass(int utilityClass)
{
    this->utilityClass = utilityClass;
}