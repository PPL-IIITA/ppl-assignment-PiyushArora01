#include "Gift.h"

Gift::Gift(int price, int value, bool taken)
{
    //!Create Gift
    this->price = price;
    this->value = value;
    this->taken = taken;
}

int Gift::getPrice()
{
    //!Return gift price
    return this->price;
}

int Gift::getValue()
{
    //!Return gift value
    return this->value;
}

bool Gift::isTaken()
{
    //!Return if gift is taken or not
    return this->taken;
}

void Gift::setPrice(int price)
{
    //!Set Gift price
    this->price = price;
}

void Gift::setValue(int value)
{
    //!Set Gift value
    this->value = value;
}


void Gift::setTaken(bool taken)
{
    //!Set if the gift is taken or not
    this->taken = taken;
}