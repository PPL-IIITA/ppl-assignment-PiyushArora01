#include "Q08Utility.h"

void computeGifts2(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, vector<EssentialGift> &EG, vector<LuxuryGift> LG, vector<UtilityGift> UG)
{
    //!Compute Gifts such that there is atleast 1 of each type
    ofstream output;
    output.open("CSV/GiftExchangeLog.csv");
    output << "Couple Index , Gift Index" << endl;
    vector<Boy>::iterator b = B.begin();
    vector<Girl>::iterator g = G.begin();
    vector<Couple>::iterator it = C.begin();
    vector<EssentialGift>::iterator eg = EG.begin();
    vector<LuxuryGift>::iterator lg = LG.begin();
    vector<UtilityGift>::iterator ug = UG.begin();
    int type, budget, maintenanceCost, cost = 0;
    int totalMoneySpent, totalValueGift, totalLuxValue;
    //cout << G.size() << " " << B.size() << " " << C.size() << " " << EG.size() << " " << LG.size() << " " << UG.size() << endl;;
    for(it = C.begin(); it < C.end(); it++) {
        totalMoneySpent = 0;
        totalValueGift = 0;
        totalLuxValue = 0;
        cost = 0;
        eg = EG.begin();
        lg = LG.begin();
        ug = UG.begin();
        b = B.begin() + (it->getBoy());
        g = G.begin() + (it->getGirl());
        type = b->getType();
        budget = b->getBudget();
        maintenanceCost = g->getMaintenanceCost();
        while(lg->isTaken() == 1 && lg < LG.end())
            lg++;       //!Since lux gifts are unique

        cost += lg->getPrice();
        budget -= lg->getPrice();
        totalMoneySpent += lg->getPrice();
        totalValueGift += lg->getValue();
        totalLuxValue += lg->getValue();
        lg->setTaken(1);
        output << it->getIndex() << " , " << lg->getIndex() << endl;
        lg++;

        cost += eg->getPrice();
        budget -= eg->getPrice();
        totalMoneySpent += eg->getPrice();
        totalValueGift += eg->getValue();
        totalLuxValue += eg->getValue();
        output << it->getIndex() << " , " << eg->getIndex() << endl;
        eg++;

        cost += ug->getPrice();
        budget -= ug->getPrice();
        totalMoneySpent += ug->getPrice();
        totalValueGift += ug->getValue();
        totalLuxValue += ug->getValue();
        output << it->getIndex() << " , " << ug->getIndex() << endl;
        ug++;

        while((eg->getPrice() < budget && eg < EG.end()) || (ug->getPrice() < budget && ug < UG.end()) || (lg->getPrice() < budget && lg < LG.end())) {
            while(lg->isTaken() && lg < LG.end()) {
                lg++;
            }
            if(lg->getPrice() < budget && lg < LG.end()) {
                    cost += lg->getPrice();
                    output << it->getIndex() << " , " << lg->getIndex() << endl;
                    lg->setTaken(1);
                    budget -= lg->getPrice();
                    totalMoneySpent += lg->getPrice();
                    totalValueGift += lg->getValue();
                    totalLuxValue += lg->getValue();
                    lg++;
            }
            
            if(eg->getPrice() < budget && eg < EG.end()) {
                cost += eg->getPrice();
                output << it->getIndex() << " , " << eg->getIndex() << endl;
                budget -= eg->getPrice();
                totalMoneySpent += eg->getPrice();
                totalValueGift += eg->getValue();
                eg++;
            }
            if(ug->getPrice() < budget && ug < UG.end()) {
                cost += ug->getPrice();
                output << it->getIndex() << " , " << ug->getIndex() << endl;
                budget -= ug->getPrice();
                totalMoneySpent += ug->getPrice();
                totalValueGift += ug->getValue();
                ug++;
            }
        }
        if(eg->getPrice() < budget && eg < EG.end()) {
            cost += eg->getPrice();
            output << it->getIndex() << " , " << eg->getIndex() << endl;
            totalMoneySpent += eg->getPrice();
            totalValueGift += eg->getValue();
            budget -= eg->getPrice();
        } else if(ug->getPrice() < budget && ug < UG.end()) {
            cost += ug->getPrice();
            output << it->getIndex() << " , " << ug->getIndex() << endl;
            totalMoneySpent += ug->getPrice();
            totalValueGift += ug->getValue();
            budget -= ug->getPrice();
        }
        it->setTotalMoneySpent(totalMoneySpent);
        it->setTotalValueGift(totalValueGift);
        it->setTotalLuxValue(totalLuxValue);
     }
     writeCouplesToFile(C);
}