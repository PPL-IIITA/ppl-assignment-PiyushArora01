#ifndef UTILITYGIFT_H_
#define UTILITYGIFT_H_

#include "Gift.h"

class UtilityGift : public Gift
{
public:
    UtilityGift(int index, int price, int value, bool taken, int utilityValue, int utilityClass);
    int getUtilityValue();
    int getUtilityClass();
    void setUtilityValue(int utilityValue);
    void setUtilityClass(int utilityClass);

private:
    int utilityValue;
    int utilityClass;
};

#endif