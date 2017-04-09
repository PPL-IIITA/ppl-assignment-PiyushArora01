#ifndef ESSENTIALGIFT_H_
#define ESSENTIALGIFT_H_

#include "Gift.h"

class EssentialGift : public Gift
{
public:
    EssentialGift(int index, int price, int value, bool taken);
};

#endif