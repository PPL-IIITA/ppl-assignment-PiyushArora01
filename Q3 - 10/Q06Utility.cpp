#include <iostream>
#include <fstream>
using namespace std;

void performBreakupLT(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C, int t)
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
    for(c = C.begin(); c != C.end(); c++, i++) {
        int temp = 0;
        if(c->getCoupleHappiness() < t) {
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
                    if(b2 < B.end())
                        temp = 1;
                    break;
                }
                else
                    b2++;
            }
            if(temp)
                cout << "Breakup between boy: " << b->getIndex() << " and girl: " << gI << ", new relation with boy: " << bI << endl;
            else {
                C.erase(c);
            }
            b->setCommitted(0);
        } else {
            break;
        }
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