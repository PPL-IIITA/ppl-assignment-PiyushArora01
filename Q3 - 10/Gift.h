#ifndef GIFT_H_
#define GIFT_H_

class Gift
{
public:
    Gift(int price, int value, bool taken);
    int getPrice();
    int getValue();
    bool isTaken();
    void setPrice(int price);
    void setValue(int value);
    void setTaken(bool taken);

private:
    int price;
    int value;
    bool taken;
};

#endif