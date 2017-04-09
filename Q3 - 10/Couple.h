#ifndef COUPLE_H_
#define COUPLE_H_

class Couple
{
public:
    Couple(int index, int boy, int girl);
    Couple(int index, int boy, int girl, double boyHappiness, double girlHappiness, double coupleHappiness, double coupleCompatibility, int totalMoneySpent, int totalValueGift, int totalLuxValue);
    int getBoy();
    int getGirl();
    int getIndex();
    double getBoyHappiness();
    double getGirlHappiness();
    double getCoupleHappiness();
    double getCoupleCompatibility();
    int getTotalMoneySpent();
    int getTotalValueGift();
    int getTotalLuxValue();
    void setBoy(int boy);
    void setGirl(int girl);
    void setBoyHappiness(double boyHappiness);
    void setGirlHappiness(double girlHappiness);
    void setCoupleHappiness(double coupleHappiness);
    void setCoupleCompatibility(double coupleCompatibility);
    void setTotalMoneySpent(int totalMoneySpent);
    void setTotalValueGift(int totalValueGift);
    void setTotalLuxValue(int totalLuxValue);

private:
    int index;
    int boy;
    int girl;
    double boyHappiness;
    double girlHappiness;
    double coupleHappiness;
    double coupleCompatibility;
    int totalMoneySpent;
    int totalValueGift;
    int totalLuxValue;
};

#endif