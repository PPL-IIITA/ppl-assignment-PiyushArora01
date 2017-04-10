#ifndef Q05UTILITY_H_
#define Q05UTILITY_H_

#include <iostream>
#include <fstream>
using namespace std;

bool sortMostAttractiveB(Boy &a, Boy &b);

bool sortMostRichB(Boy &a, Boy &b);

bool sortMostIntelligentB(Boy &a, Boy &b);

bool sortMostAttractiveG(Girl &a, Girl &b);

bool sortMaintenanceCost(Girl &a, Girl &b);

void makeNewCouples(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C);

void getKNHappiestCouples(vector<Couple> &C, int k);

#endif