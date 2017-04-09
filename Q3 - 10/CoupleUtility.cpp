#include <iostream>
#include <fstream>
using namespace std;

bool sortMostAttractive(Boy &a, Boy &b)
{
    int t1 = a.getAttractiveness();
    int t2 = b.getAttractiveness();

    return t1>t2;
}

bool sortMostRich(Boy &a, Boy &b)
{
    int t1 = a.getBudget();
    int t2 = b.getBudget();

    return t1>t2;
}

bool sortMostIntelligent(Boy &a, Boy &b)
{
    int t1 = a.getIntelligenceLevel();
    int t2 = b.getIntelligenceLevel();

    return t1>t2;
}

void makeCouples(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    vector<Girl>::iterator g;
    vector<Boy>::iterator b;
    vector<Couple>::iterator c;
    int noOfRelations = 0;
    int bI, gI;
    int type;
    for(g = G.begin(); g < G.end() && noOfRelations < 1000; g++) {
        type = g->getBoyChoice();
        /*
        BoyChoice = 0 => Most attractive;
        BoyChoice = 1 => Most rich;
        BoyChoice = 2 => Most intelligent;
        */
        if(type == 0) {
            sort(B.begin(), B.end(), sortMostAttractive);
            b = B.begin();
        } else if(type == 1) {
            sort(B.begin(), B.end(), sortMostRich);
            b = B.begin();
        } else if(type == 2) {
            sort(B.begin(), B.end(), sortMostIntelligent);
            b = B.begin();
        }
        while(b < B.end()) {
            if((b->getBudget() >= g->getMaintenanceCost()) && (b->getMinAttraction() <= g->getAttractiveness()) && (!(b->isCommitted()))) {
                b->setCommitted(1);
                g->setCommitted(1);
                bI = b->getIndex();
                gI = g->getIndex();
                Couple cp(noOfRelations, bI, gI);
                //cout << b->getBudget() << " MC " << g->getMaintenanceCost() << endl;
                C.push_back(cp);
                noOfRelations++;
                break;
            }
            else
                b++;
        }
    }
    writeCouplesToFile(C);
    writeBoysToFile(B);
    writeGirlsToFile(G);  
}

bool sortGiftByPrice(Gift &a, Gift &b)
{
    return a.getPrice() < b.getPrice();
}

bool sortPersonByIndex(Person &p1, Person &p2)
{
    return p1.getIndex() < p2.getIndex();
}

bool sortCoupleByIndex(Couple &c1, Couple &c2)
{
    return c1.getIndex() < c2.getIndex();
}

void sortAllByIndex(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    sort(B.begin(), B.end(), sortPersonByIndex);
    sort(G.begin(), G.end(), sortPersonByIndex);
    sort(C.begin(), C.end(), sortCoupleByIndex);
}

void computeGifts(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, vector<EssentialGift> &EG, vector<LuxuryGift> LG, vector<UtilityGift> UG)
{
    ofstream output;
    output.open("CSV/GiftExchangeLog.csv");
    output << "Couple Index , Gift Index" << endl;
    sort(EG.begin(), EG.end(), sortGiftByPrice);
    sort(LG.begin(), LG.end(), sortGiftByPrice);
    sort(UG.begin(), UG.end(), sortGiftByPrice);
    sortAllByIndex(B, G, C);
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
        //cout << b->getIndex() << " " << g->getIndex() << " " << type << " " << budget << " " << maintenanceCost << " " << it->getBoy() << " " << it->getGirl() << endl;
        /*
        GEEKS
        */
        if(type == 2) {
            while(lg->isTaken() == 1 && lg < LG.end()) {
                lg++;       //!Since lux gifts are unique
            }
            while(lg->getPrice() > maintenanceCost && lg < LG.end())
                lg++;
            if(lg->getPrice() < budget && lg < LG.end()) {
                cost += lg->getPrice();
                maintenanceCost -= lg->getPrice();
                totalMoneySpent += lg->getPrice();
                totalValueGift += lg->getValue();
                totalLuxValue += lg->getValue();
                lg->setTaken(1);
                output << it->getIndex() << " , " << lg->getIndex() << endl;
            }
            while((eg->getPrice() < maintenanceCost && eg < EG.end()) || (ug->getPrice() < maintenanceCost && ug < UG.end())) {
                if(eg->getPrice() < maintenanceCost && eg < EG.end()) {
                    cost += eg->getPrice();
                    output << it->getIndex() << " , " << eg->getIndex() << endl;
                    maintenanceCost -= eg->getPrice();
                    totalMoneySpent += eg->getPrice();
                    totalValueGift += eg->getValue();                    
                    eg++;
                }
                if(ug->getPrice() < maintenanceCost && ug < UG.end()) {
                    cost += ug->getPrice();
                    output << it->getIndex() << " , " << ug->getIndex() << endl;
                    maintenanceCost -= ug->getPrice();
                    totalMoneySpent += ug->getPrice();
                    totalValueGift += ug->getValue();                    
                    ug++;
                }
            }
        } else if(type == 1) {
        /*
        GENEROUS
        */
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
        } else if(type == 0) {
            while((eg->getPrice() < maintenanceCost && eg < EG.end()) || (ug->getPrice() < maintenanceCost && ug < UG.end()) || (lg->getPrice() < maintenanceCost && lg < LG.end())) {
                while(lg->isTaken() && lg < LG.end()) {
                    lg++;
                }
                if(lg->getPrice() < maintenanceCost && lg < LG.end()) {
                    cost += lg->getPrice();
                    output << it->getIndex() << " , " << lg->getIndex() << endl;
                    lg->setTaken(1);
                    maintenanceCost -= lg->getPrice();
                    totalMoneySpent += lg->getPrice();
                    totalValueGift += lg->getValue();
                    totalLuxValue += lg->getValue();
                    lg++;
                }
                if(eg->getPrice() < maintenanceCost && eg < EG.end()) {
                    cost += eg->getPrice();
                    output << it->getIndex() << " , " << eg->getIndex() << endl;
                    maintenanceCost -= eg->getPrice();
                    totalMoneySpent += eg->getPrice();
                    totalValueGift += eg->getValue();
                    eg++;
                }
                if(ug->getPrice() < maintenanceCost && ug < UG.end()) {
                    cost += ug->getPrice();
                    output << it->getIndex() << " , " << ug->getIndex() << endl;
                    maintenanceCost -= ug->getPrice();
                    totalMoneySpent += ug->getPrice();
                    totalValueGift += ug->getValue();
                    ug++;
                }
            }
            if(eg->getPrice() < (budget - cost) && eg < EG.end()) {
                cost += eg->getPrice();
                output << it->getIndex() << " , " << eg->getIndex() << endl;
                totalMoneySpent += eg->getPrice();
                totalValueGift += eg->getValue();
                maintenanceCost -= eg->getPrice();
            } else if(ug->getPrice() < (budget - cost) && ug < UG.end()) {
                cost += ug->getPrice();
                output << it->getIndex() << " , " << ug->getIndex() << endl;
                totalMoneySpent += ug->getPrice();
                totalValueGift += ug->getValue();
                maintenanceCost -= ug->getPrice();
            }
        }
        it->setTotalMoneySpent(totalMoneySpent);
        it->setTotalValueGift(totalValueGift);
        it->setTotalLuxValue(totalLuxValue);
     }
     writeCouplesToFile(C);
}


void computeBoyHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    //! Compute boy's happiness
    sortAllByIndex(B, G, C);
    vector<Boy>::iterator b =  B.begin();
    vector<Girl>::iterator g = G.begin();
    vector<Couple>::iterator c = C.begin();
    double temp = 0;
    int type;
    for(c = C.begin(); c != C.end(); c++) {
        b = B.begin() + c->getBoy();
        g= G.begin() + c->getGirl();
        type = b->getType();
        if(type == 0) {
            temp = b->getBudget() - c->getTotalMoneySpent();
        } else if(type == 1) {
            temp = c->getGirlHappiness();
        } else if(type == 2) {
            temp = g->getIntelligenceLevel();
        }
        if(isnan(temp))
            temp = 0;
        if(isinf(temp))
            temp = 1.79769e+308;
        c->setBoyHappiness(temp);
    }
    writeCouplesToFile(C);
}

void computeGirlHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    //! Compute girl's happiness
    sortAllByIndex(B, G, C);
    vector<Boy>::iterator b =  B.begin();
    vector<Girl>::iterator g = G.begin();
    vector<Couple>::iterator c = C.begin();
    double temp = 0;
    int type;
    for(c = C.begin(); c != C.end(); c++) {
        b = B.begin() + c->getBoy();
        g= G.begin() + c->getGirl();
        type = g->getType();
        if(type == 0) {
            temp = log(c->getTotalMoneySpent() - g->getMaintenanceCost()) + c->getTotalLuxValue();
        } else if(type == 1) {
            temp = c->getTotalMoneySpent() + c->getTotalValueGift() - g->getMaintenanceCost();
        } else if(type == 2) {
            temp = exp(c->getTotalMoneySpent() - g->getMaintenanceCost());
        }
        if(isnan(temp))
            temp = 0;
        if(isinf(temp))
            temp = 1.79769e+308;
        c->setGirlHappiness(temp);
    }
    writeCouplesToFile(C);
}

void computeCoupleHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    //!Compute couple happiness
    computeGirlHappiness(B, G, C);
    computeBoyHappiness(B, G, C);
    vector<Couple>::iterator c = C.begin();
    double temp;
    for(c = C.begin(); c != C.end(); c++) {
        temp = c->getBoyHappiness() + c->getGirlHappiness();
        if(isinf(temp))
            temp = 1.79769e+308;
        c->setCoupleHappiness(temp);
    }
    writeCouplesToFile(C);
}

void computeCoupleCompatibility(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    //!Compute couple compatibility
    double diff1;
    double diff2;
    double diff3;
    double temp;
    sortAllByIndex(B, G, C);    
    vector<Boy>::iterator b =  B.begin();
    vector<Girl>::iterator g = G.begin();
    vector<Couple>::iterator c = C.begin();
    for(c = C.begin(); c != C.end(); c++) {
        b = B.begin() + c->getBoy();
        g= G.begin() + c->getGirl();
        diff1 = std::abs(b->getBudget() - g->getMaintenanceCost());
        diff2 = std::abs(b->getAttractiveness() - g->getAttractiveness());
        diff3 = std::abs(b->getIntelligenceLevel() - g->getIntelligenceLevel());
        temp = diff1 + diff2 + diff3;
        c->setCoupleCompatibility(temp);
    }
    writeCouplesToFile(C);
}

bool sortByCompatibility(Couple &c1, Couple &c2)
{
    return c1.getCoupleCompatibility() > c2.getCoupleCompatibility();
}

bool sortByHappiness(Couple &c1, Couple &c2)
{
    return c1.getCoupleHappiness() > c2.getCoupleHappiness();
}

bool sortByLHappiness(Couple &c1, Couple &c2)
{
    return c1.getCoupleHappiness() < c2.getCoupleHappiness();
}

void getKHappiestCouples(vector<Couple> &C, int k)
{
    //!Get K Happiest Couples
    ofstream output;
    vector<Couple>::iterator it;
    int i = 0;
    output.open("CSV/Q03_KHappiest.csv");
    output << "Couple Index , Couple Happiness" << endl;
    sort(C.begin(), C.end(), sortByHappiness);
    cout << endl << k << " Happiest: " << endl;
    cout << "\tIndex | Happiness" << endl;
    for(it = C.begin(); it != C.end(), i < k; it++, i++) {
        cout << "\t" << it->getIndex() << "\t" << it->getCoupleHappiness() << endl;
        output << it->getIndex() << " , " << it->getCoupleHappiness() << endl;
    }
    output.close();
}

void getKMostCompatibleCouples(vector<Couple> &C, int k)
{
    //!Get K Most Compatible Couples
    ofstream output;
    vector<Couple>::iterator it;
    int i = 0;
    output.open("CSV/Q03_KCompatible.csv");
    output << "Couple Index , Couple Compatibility" << endl;
    sort(C.begin(), C.end(), sortByCompatibility);
    cout << endl << k << " Compatible: " << endl;
    cout << "\tIndex | Compatibility" << endl;
    for(it = C.begin(); it != C.end(), i < k; it++, i++) {
        cout << "\t" << it->getIndex() << "\t" << it->getCoupleCompatibility() << endl;
        output << it->getIndex() << " , " << it->getCoupleCompatibility() << endl;
    }
}


void performBreakup(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, int k)
{
    sortAllByIndex(B, G, C);
    //cout << C.size() << endl;
    int i = 0;
    vector<Boy>::iterator b;
    vector<Boy>::iterator b2;
    vector<Girl>::iterator g;
    vector<Couple>::iterator c;
    int bI, gI;
    int type;
    int cIndex = 0;
    //cout << C.size() << endl;
    //cout << "Start\n";
    sort(C.begin(), C.end(), sortByLHappiness);
    for(c = C.begin(); c != C.end(), i < k; c++, i++) {
        b = B.begin() + c->getBoy();
        g = G.begin() + c->getGirl();
        //cout << c->getIndex() << " bInd: " << c->getBoy() << " gInd: " << c->getGirl() << endl; 
        //cout << c->getIndex() << " boy: " << b->getIndex() << " girl " << g->getIndex() << endl;
        cIndex = c->getIndex();
        type = g->getBoyChoice();
        g->setCommitted(0);
        if(type == 0) {
            sort(B.begin(), B.end(), sortMostAttractive);
            b2 = B.begin();
        } else if(type == 1) {
            sort(B.begin(), B.end(), sortMostRich);
            b2 = B.begin();
        } else if(type == 2) {
            sort(B.begin(), B.end(), sortMostIntelligent);
            b2 = B.begin();
        }
        while(b2 < B.end()) {
            if((b2->getBudget() >= g->getMaintenanceCost()) && (b2->getMinAttraction() <= g->getAttractiveness()) && (!(b2->isCommitted())) && b2 != b) {
                b2->setCommitted(1);
                g->setCommitted(1);
                bI = b2->getIndex();
                gI = g->getIndex();
                c->setBoy(bI);
                c->setBoyHappiness(0);
                c->setGirlHappiness(0);
                c->setCoupleHappiness(0);
                c->setCoupleCompatibility(0);
                c->setTotalMoneySpent(0);
                c->setTotalValueGift(0);
                c->setTotalLuxValue(0);
                break;
            }
            else
                b2++;
        }
        cout << "Breakup between boy: " << b->getIndex() << " and girl: " << g->getIndex() << ", new relation with boy: " << b2->getIndex() << endl;
        b->setCommitted(0);
    }
    writeCouplesToFile(C);
    writeBoysToFile(B);
    writeGirlsToFile(G);
    vector<EssentialGift> EG;
    vector<LuxuryGift> LG;
    vector<UtilityGift> UG;
    getEGiftList(EG);
    getLGiftList(LG);
    getUGiftList(UG);
    computeGifts(B, G, C, EG, LG, UG);
    writeEGiftsToFile(EG);
    writeLGiftsToFile(LG);
    writeUGiftsToFile(UG);
    computeCoupleHappiness(B, G, C);
    computeCoupleCompatibility(B, G, C);
}