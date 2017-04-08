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
}
/*
void Couple::computeBoyHappiness()
{
    //! Compute boy's happiness
    double temp = 0;
    int type = this->boy->getType();
    if(type == 0) {
        temp = this->boy->getBudget() - this->totalMoneySpent;
    } else if(type == 1) {
        temp = this->girl->getHappiness();
    } else if(type == 2) {
        temp = this->girl->getIntelligenceLevel();
    }
    this->boy->setHappiness(temp);
}

void Couple::computeGirlHappiness()
{
    //! Compute girl's happiness
    double temp = 0;
    int type = this->girl->getType();
    if(type == 0) {
        temp = log(this->totalMoneySpent - this->girl->getMaintenanceCost()) + this->essentialGiftsVal + this->utilityGiftsVal + 2*this->luxuryGiftsVal;
    } else if(type == 1) {
        temp = this->totalMoneySpent + this->totalGiftsValue - this->girl->getMaintenanceCost();
    } else if(type == 2) {
        temp = exp(this->totalMoneySpent - this->girl->getMaintenanceCost());
    }  
    this->girl->setHappiness(temp);
}

double Couple::getCoupleHappiness()
{
    //!Compute girl's happiness
    computeCoupleHappiness();
    return std::abs(this->happiness);
}

double Couple::getCoupleCompatibility()
{
    //! Compute couple compatibility
    computeCoupleCompatibility();
    return std::abs(this->compatibility);
}

void Couple::computeCoupleHappiness()
{
    //!Compute couple happiness
    computeGirlHappiness();
    computeBoyHappiness();
    this->happiness = this->boy->getHappiness() + this->girl->getHappiness();
}

void Couple::computeCoupleCompatibility()
{
    //!Compute couple compatibility
    double diff1, diff2, diff3;
    diff1 = std::abs(this->boy->getBudget() - this->girl->getMaintenanceCost());
    diff2 = std::abs(this->boy->getAttractiveness() - this->girl->getAttractiveness());
    diff3 = std::abs(this->boy->getIntelligenceLevel() - this->girl->getIntelligenceLevel());
    this->compatibility = diff1 + diff2 + diff3;
}

void Couple::addGift(Gift g)
{
    //!Add a gift to the couple
    this->G.push_back(g);
    this->totalMoneySpent += g.getPrice();
    this->totalGifts =  G.size();
    this->totalGiftsValue += g.getPrice();
    int type = g.getType();
    if(type == 0) {
        this->essentialGifts++;
        this->essentialGiftsCost += g.getPrice();
        this->essentialGiftsVal += g.getPrice();
    } else if(type == 1) {
        this->luxuryGifts++;
        this->luxuryGiftsCost += g.getPrice();
        this->luxuryGiftsVal += g.getPrice();
    } else if(type == 2) {
        this->utilityGifts++;
        this->utilityGiftsCost += g.getPrice();
        this->utilityGiftsVal += g.getPrice();    
    }
}*/