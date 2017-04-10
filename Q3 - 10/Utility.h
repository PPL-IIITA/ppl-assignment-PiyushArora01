#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <fstream>
using namespace std;

void getBoysList(vector<Boy> &boys);

void getGirlsList(vector<Girl> &girls);

void getCouplesList(vector<Couple> &couples);

void getEGiftList(vector<EssentialGift> &eGifts);

void getLGiftList(vector<LuxuryGift> &lGifts);

void getUGiftList(vector<UtilityGift> &uGifts);

void writeEGiftsToFile(vector<EssentialGift> &eGifts);

void writeLGiftsToFile(vector<LuxuryGift> &lGifts);

void writeUGiftsToFile(vector<UtilityGift> &uGifts);

void writeCouplesToFile(vector<Couple> &couples);

void writeBoysToFile(vector<Boy> &boy);

void writeGirlsToFile(vector<Girl> &girl);

#endif