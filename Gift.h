#ifndef GIFT_H_
#define GIFT_H_

class Gift
{
public:
    Gift(int price, int value);
    Gift(int price, int value, int luxuryRating, int luxuryDifficultyToObtain);
    Gift(int price, int value, int utilityValue, long utilityClass);
    int getType();
    int getPrice();
    int getValue();
    int getLuxuryRating();
    int getLuxuryDifficultyToObtain();
    int getUtilityValue();
    int getUtilityClass();
    void setPrice(int price);
    void setValue(int value);
    void setLuxuryRating(int luxuryRating);
    void setLuxuryDifficultyToObtain(int luxuryDifficultyToObtain);
    void setUtilityValue(int utilityValue);
    void setUtilityClass(int utilityClass);

private:
    int type;
    int price;
    int value;
    int luxuryRating;
    int luxuryDifficultyToObtain;
    int utilityValue;
    long utilityClass;
};

#endif