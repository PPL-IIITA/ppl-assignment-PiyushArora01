#include <iostream>
#include <fstream>
using namespace std;

void getBoysList(vector<Boy> &boys)
{
    ifstream input;
    input.open("CSV/BoyList.csv");
    int index;
    string name;
    int attractiveness;
    int intelligenceLevel;
    int type;
    int budget;
    int minAttraction;
    int i;
    string temp;
    for(i = 0; i < 1000; i++) {
        input >> index >> temp >> name >> temp >> attractiveness >> temp >> intelligenceLevel >> temp >> type >> temp >> budget >> temp >> minAttraction;
        Boy b(index, name, attractiveness, intelligenceLevel, type, budget, minAttraction);
        boys.push_back(b);
    }
    input.close();
}

void getGirlsList(vector<Girl> &girls)
{
    ifstream input;
    input.open("CSV/GirlList.csv");
    int index;
    string name;
    int attractiveness;
    int intelligenceLevel;
    int type;
    int maintenanceCost;
    int boyChoice;
    int i;
    string temp;
    for(i = 0; i < 1000; i++) {
        input >> index >> temp >> name >> temp >> attractiveness >> temp >> intelligenceLevel >> temp >> type >> temp >> maintenanceCost >> temp >> boyChoice;
        Girl b(index, name, attractiveness, intelligenceLevel, type, maintenanceCost, boyChoice);
        girls.push_back(b);
    }
    input.close();
}

void getCouplesList(vector<Couple> &couples)
{
    ifstream input;
    input.open("CSV/CoupleList.csv");
    int index;
    int bIndex;
    int gIndex;
    double bHappiness;
    double gHappiness;
    double cHappiness;
    double cCompatibility;
    int totalMoneySpent;
    int totalValueGift;
    int totalLuxValue;
    int i;
    string temp;
    for(i = 0; i < 1000; i++) {
        input >> index >> temp >> bIndex >> temp >> gIndex >> temp >> bHappiness >> temp >> gHappiness >> temp >> cHappiness >> temp >> cCompatibility >> temp >> totalMoneySpent >> temp >> totalValueGift >> temp >> totalLuxValue;
        Couple b(index, bIndex, gIndex, bHappiness, gHappiness, cHappiness, cCompatibility, totalMoneySpent, totalValueGift, totalLuxValue);
        couples.push_back(b);
    }
    input.close();
}

void getEGiftList(vector<EssentialGift> &eGifts)
{
    ifstream input;
    input.open("CSV/EssentialGift.csv");
    int index;
    int price;
    int value;
    bool taken;
    string temp;
    int i;
    for(i = 0; i < 5000; i++) {
        input >> index  >> temp >> price  >> temp >> value >> temp >> taken;
        EssentialGift g(index, price, value, taken);
        eGifts.push_back(g);
    }
    input.close();
}

void getLGiftList(vector<LuxuryGift> &lGifts)
{
    ifstream input;    
    input.open("CSV/LuxuryGift.csv");
    int index;
    int price;
    int value;
    bool taken;
    int luxuryRating;
    int luxuryDifficultyToObtain;
    string temp;
    int i;
    for(i = 0; i < 1000; i++) {
        input >> index >> temp >> price >> temp >> value >> temp >> luxuryRating >> temp >> luxuryDifficultyToObtain >> temp >> taken;
        LuxuryGift g(index, price, value, taken, luxuryRating, luxuryDifficultyToObtain);
        lGifts.push_back(g);
    }
    input.close();
}

void getUGiftList(vector<UtilityGift> &uGifts)
{
    ifstream input;    
    input.open("CSV/UtilityGift.csv");
    int index;
    int price;
    int value;
    bool taken;
    int utilityValue;
    int utilityClass;
    string temp;
    int i;
    for(i = 0; i < 2000; i++) {
        input >> index >> temp >> price >> temp >> value >> temp >> utilityValue >> temp >> utilityClass >> temp >> taken;
        UtilityGift g(index, price, value, taken, utilityValue, utilityClass);
        uGifts.push_back(g);
    }
    input.close();
}

void writeEGiftsToFile(vector<EssentialGift> &eGifts)
{
    ofstream output;
    output.open("CSV/EssentialGift.csv");
    vector<EssentialGift>::iterator it;
    int i = 0;
    for(it = eGifts.begin(); it != eGifts.end(); it++, i++) {
        output << it->getIndex() << " , " << it->getPrice() << " , " << it->getValue() << " , " << it->isTaken() << endl;
    }
    output.close();
}

void writeLGiftsToFile(vector<LuxuryGift> &lGifts)
{
    ofstream output;
    output.open("CSV/LuxuryGift.csv");
    vector<LuxuryGift>::iterator it;
    int i = 0;
    for(it = lGifts.begin(); it != lGifts.end(); it++, i++) {
        output << it->getIndex() << " , " << it->getPrice() << " , " << it->getValue() << " , " << it->getLuxuryRating() << " , " << it->getLuxuryDifficultyToObtain() << " , " << it->isTaken() << endl;
    }
    output.close();
}

void writeUGiftsToFile(vector<UtilityGift> &uGifts)
{
    ofstream output;
    output.open("CSV/UtilityGift.csv");
    vector<UtilityGift>::iterator it;
    int i = 0;
    for(it = uGifts.begin(); it != uGifts.end(); it++, i++) {
        output << it->getIndex() << " , " << it->getPrice() << " , " << it->getValue() << " , " << it->getUtilityValue() << " , " << it->getUtilityClass() << " , " << it->isTaken() << endl;
    }
    output.close();
}

void writeCouplesToFile(vector<Couple> &couples)
{
    ofstream output;
    output.open("CSV/CoupleList.csv");
    vector<Couple>::iterator it;
    int i = 0;
    for(it = couples.begin(); it != couples.end(); it++, i++) {
        output << it->getIndex() << " , " << it->getBoy() << " , " << it->getGirl() << " , " << it->getBoyHappiness() << " , " << it->getGirlHappiness() << " , " << it->getCoupleHappiness() << " , " << it->getCoupleCompatibility() << " , " << it->getTotalMoneySpent() << " , " << it->getTotalValueGift() << " , " << it->getTotalLuxValue() << endl;
    }
    output.close();    
}