#ifndef COUPLE_H_
#define COUPLE_H_
#include <cmath>
#include <vector>
#include "Gift.cpp"
#include "Boy.cpp"
#include "Girl.cpp"

class Couple
{
public:
    Couple(Boy *boy, Girl *girl);
    double getCoupleHappiness();
    double getCoupleCompatibility();
    void addGift(Gift g);
    std::string getBoyName();
    std::string getGirlName();
    Boy *boy;
    Girl *girl;    

private:
    double happiness;
    double compatibility;
    int totalMoneySpent;
    int totalGifts;
    int totalGiftsValue;
    int essentialGifts;
    int luxuryGifts;
    int utilityGifts;
    int essentialGiftsCost;
    int luxuryGiftsCost;
    int utilityGiftsCost;
    int essentialGiftsVal;
    int luxuryGiftsVal;
    int utilityGiftsVal;
    std::vector<Gift> G;
    void computeGirlHappiness();    
    void computeBoyHappiness();
    void computeCoupleHappiness();
    void computeCoupleCompatibility();
};

#endif