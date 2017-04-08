#ifndef LUXURYGIFT_H_
#define LUXURYGIFT_H_

#include "Gift.h"

class LuxuryGift : public Gift
{
public:
    LuxuryGift(int price, int value, bool taken, int luxuryRating, int luxuryDifficultyToObtain);
    int getLuxuryRating();
    int getLuxuryDifficultyToObtain();
    void setLuxuryRating(int luxuryRating);
    void setLuxuryDifficultyToObtain(int luxuryDifficultyToObtain);

private:
    int luxuryRating;
    int luxuryDifficultyToObtain;
};

#endif