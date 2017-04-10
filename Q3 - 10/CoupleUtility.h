#ifndef COUPLEUTILITY_H_
#define COUPLEUTILITY_H_

#include <iostream>
#include <fstream>
using namespace std;

bool sortMostAttractive(Boy &a, Boy &b);

bool sortMostRich(Boy &a, Boy &b);

bool sortMostIntelligent(Boy &a, Boy &b);

void makeCouples(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

bool sortGiftByPrice(Gift &a, Gift &b);

bool sortPersonByIndex(Person &p1, Person &p2);

bool sortCoupleByIndex(Couple &c1, Couple &c2);

void sortAllByIndex(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

void computeGifts(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, vector<EssentialGift> &EG, vector<LuxuryGift> LG, vector<UtilityGift> UG);

void computeBoyHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

void computeGirlHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

void computeCoupleHappiness(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

void computeCoupleCompatibility(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

bool sortByCompatibility(Couple &c1, Couple &c2);

bool sortByHappiness(Couple &c1, Couple &c2);

bool sortByLHappiness(Couple &c1, Couple &c2);

void getKHappiestCouples(vector<Couple> &C, int k);

void getKMostCompatibleCouples(vector<Couple> &C, int k);

void performBreakup(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, int k);

#endif