#include "LuxuryGift.h"

LuxuryGift::LuxuryGift(int price, int value, bool taken, int luxuryRating, int luxuryDifficultyToObtain) : Gift(price, value, taken)
{
    //!Luxury Gift constructor
    this->luxuryRating = luxuryRating;
    this->luxuryDifficultyToObtain = luxuryDifficultyToObtain;
}

int LuxuryGift::getLuxuryRating()
{
    //!Return luxury rating
    return this->luxuryRating;
}

int LuxuryGift::getLuxuryDifficultyToObtain()
{
    //!Return Luxury Difficulty
    return this->luxuryDifficultyToObtain;
}

void LuxuryGift::setLuxuryRating(int luxuryRating)
{
    //!Set luxury rating
    this->luxuryRating = luxuryRating;
}

void LuxuryGift::setLuxuryDifficultyToObtain(int luxuryDifficultyToObtain)
{
    //!Set Difficulty to obtain
    this->luxuryDifficultyToObtain = luxuryDifficultyToObtain;
}