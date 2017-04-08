#include <iostream>
#include <fstream>
#include <algorithm>
#include "Couple.cpp"
using namespace std;

bool sortHelp(Gift &a, Gift &b)
{
    return a.getPrice() < b.getPrice();
}

void ComputeGifts(vector<Couple> C)
{
    ifstream input;
    input.open("EssentialGift.csv");
    vector<Gift> EG;
    vector<Gift> LG;
    vector<Gift> UG;
    int i;
    int price, value, luxuryRating, luxuryDifficultyToObtain, utilityValue;
    long utilityClass;
    for(i = 0; i < 5000; i++) {
        input >> price >> value;
        Gift g(price, value);
        EG.push_back(g);
    }
    input.close();
    input.open("LuxuryGift.csv");
        for(i = 0; i < 1000; i++) {
        input >> price >> value >> luxuryRating >> luxuryDifficultyToObtain;
        Gift g(price, value, luxuryRating, luxuryDifficultyToObtain);
        LG.push_back(g);
    }
    input.close();
    input.open("UtilityGift.csv");
        for(i = 0; i < 2000; i++) {
        input >> price >> value >> utilityValue >> utilityClass;
        Gift g(price, value, utilityValue, utilityClass);
        UG.push_back(g);
    }
    input.close();    
    sort(EG.begin(), EG.end(), sortHelp);
    sort(LG.begin(), LG.end(), sortHelp);
    sort(UG.begin(), UG.end(), sortHelp);
    vector<Couple>::iterator it = C.begin();
    vector<Boy>::iterator it2;
    vector<Gift>::iterator eg = EG.begin();
    vector<Gift>::iterator lg = LG.begin();
    vector<Gift>::iterator ug = UG.begin();
    Boy *b;
    Girl *g;
    int type, budget, maintenanceCost, cost = 0;
    ofstream output;
    output.open("Q2.csv");
    for(it = C.begin(); it < C.end(); it++) {
        cost = 0;
        eg = EG.begin();
        lg = LG.begin();
        ug = UG.begin();
        b = it->boy;
        g = it->girl;
        type = b->getType();
        budget = b->getBudget();
        maintenanceCost = g->getMaintenanceCost();
        /*
        GEEKS
        */
        if(type == 2) {
            while(lg->getPrice() > maintenanceCost)
                lg++;
            //cout << lg->getPrice() << " ";
            cost += lg->getPrice();
            maintenanceCost -= lg->getPrice();
            it->addGift(*lg);
            while(eg->getPrice() < maintenanceCost || ug->getPrice() < maintenanceCost) {
                if(eg->getPrice() < maintenanceCost) {
                    //cout << eg->getPrice() << " ";
                    cost += eg->getPrice();
                    it->addGift(*eg);
                    maintenanceCost -= ug->getPrice();
                    eg++;
                    //cout << "N" << eg->getPrice() << " ";
                }
                if(ug->getPrice() < maintenanceCost) {
                    //cout << ug->getPrice() << " ";
                    cost += ug->getPrice();
                    it->addGift(*ug);
                    maintenanceCost -= eg->getPrice();
                    ug++;
                    //cout << "N" << ug->getPrice() << " ";
                }
                //cout << "MC " << maintenanceCost << " ";
            }
            
        } else if(type == 1) {
        /*
        GENEROUS
        */
            while(eg->getPrice() < budget || ug->getPrice() < budget || lg->getPrice() < budget) {
                if(eg->getPrice() < budget) {
                    //cout << eg->getPrice() << " ";
                    cost += eg->getPrice();
                    it->addGift(*eg);
                    budget -= ug->getPrice();
                    eg++;
                    //cout << "N" << eg->getPrice() << " ";
                }
                if(ug->getPrice() < budget) {
                    //cout << ug->getPrice() << " ";
                    cost += ug->getPrice();
                    it->addGift(*ug);
                    budget -= eg->getPrice();
                    ug++;
                    //cout << "N" << ug->getPrice() << " ";
                }
                if(lg->getPrice() < budget) {
                    //cout << ug->getPrice() << " ";
                    cost += lg->getPrice();
                    it->addGift(*lg);
                    budget -= lg->getPrice();
                    lg++;
                    //cout << "N" << ug->getPrice() << " ";
                }
                //cout << "MC " << budget << " ";
            }
            if(eg->getPrice() < budget) {
                //cout << eg->getPrice() << " ";
                cost += eg->getPrice();
                it->addGift(*eg);
                budget -= ug->getPrice();
            } else if(ug->getPrice() < budget) {
                //cout << ug->getPrice() << " ";
                cost += ug->getPrice();
                it->addGift(*ug);
                budget -= eg->getPrice();
            }
        } else if(type == 0) {
            //cout << lg->getPrice() << " ";
            while(eg->getPrice() < maintenanceCost || ug->getPrice() < maintenanceCost || lg->getPrice() < maintenanceCost) {
                if(eg->getPrice() < maintenanceCost) {
                    //cout << eg->getPrice() << " ";
                    cost += eg->getPrice();
                    it->addGift(*eg);
                    maintenanceCost -= ug->getPrice();
                    eg++;
                    //cout << "N" << eg->getPrice() << " ";
                }
                if(ug->getPrice() < maintenanceCost) {
                    //cout << ug->getPrice() << " ";
                    cost += ug->getPrice();
                    it->addGift(*ug);
                    maintenanceCost -= eg->getPrice();
                    ug++;
                    //cout << "N" << ug->getPrice() << " ";
                }
                if(lg->getPrice() < maintenanceCost) {
                    //cout << ug->getPrice() << " ";
                    cost += lg->getPrice();
                    it->addGift(*lg);
                    maintenanceCost -= lg->getPrice();
                    lg++;
                    //cout << "N" << ug->getPrice() << " ";
                }
                //cout << "MC " << maintenanceCost << " ";
            }
            if(eg->getPrice() < (budget - cost)) {
                //cout << eg->getPrice() << " ";
                cost += eg->getPrice();
                it->addGift(*eg);
                maintenanceCost -= ug->getPrice();
            } else if(ug->getPrice() < (budget - cost)) {
                //cout << ug->getPrice() << " ";
                cost += ug->getPrice();
                it->addGift(*ug);
                maintenanceCost -= eg->getPrice();
            }
        }
        output << it->getBoyName() << " " << it->getGirlName() << " " << it->getCoupleCompatibility() << " " << it->getCoupleHappiness() <<" " << endl;
    }
}