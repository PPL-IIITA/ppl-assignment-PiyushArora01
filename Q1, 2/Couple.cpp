#include "Couple.h"

Couple::Couple(Boy *boy, Girl *girl)
{ 
    this->boy = boy;
    this->girl = girl;
    this->happiness = 0;
    this->compatibility = 0;
    this->totalMoneySpent = 0;
    this->totalGifts =  0;
    this->totalGiftsValue = 0;
    this->essentialGifts = 0;
    this->luxuryGifts = 0;
    this->utilityGifts = 0;
    this->essentialGiftsCost = 0;
    this->luxuryGiftsCost = 0;
    this->utilityGiftsCost = 0;
    this->essentialGiftsVal = 0;
    this->luxuryGiftsVal = 0;
    this->utilityGiftsVal = 0;  
    computeCoupleHappiness();
    computeCoupleCompatibility();
}

std::string Couple::getBoyName()
{
    return this->boy->getName();
}

std::string Couple::getGirlName()
{
    return this->girl->getName();
}

void Couple::computeBoyHappiness()
{
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
    computeCoupleHappiness();
    return std::abs(this->happiness);
}

double Couple::getCoupleCompatibility()
{
    computeCoupleCompatibility();
    return std::abs(this->compatibility);
}

void Couple::computeCoupleHappiness()
{
    computeGirlHappiness();
    computeBoyHappiness();
    this->happiness = this->boy->getHappiness() + this->girl->getHappiness();
}

void Couple::computeCoupleCompatibility()
{
    double diff1, diff2, diff3;
    diff1 = std::abs(this->boy->getBudget() - this->girl->getMaintenanceCost());
    diff2 = std::abs(this->boy->getAttractiveness() - this->girl->getAttractiveness());
    diff3 = std::abs(this->boy->getIntelligenceLevel() - this->girl->getIntelligenceLevel());
    this->compatibility = diff1 + diff2 + diff3;
}

void Couple::addGift(Gift g)
{
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
}