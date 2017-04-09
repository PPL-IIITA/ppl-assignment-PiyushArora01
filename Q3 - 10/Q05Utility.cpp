#include <iostream>
#include <fstream>
using namespace std;

bool sortMostAttractiveB(Boy &a, Boy &b)
{
    int t1 = a.getAttractiveness();
    int t2 = b.getAttractiveness();

    return t1>t2;
}

bool sortMostRichB(Boy &a, Boy &b)
{
    int t1 = a.getBudget();
    int t2 = b.getBudget();

    return t1>t2;
}

bool sortMostIntelligentB(Boy &a, Boy &b)
{
    int t1 = a.getIntelligenceLevel();
    int t2 = b.getIntelligenceLevel();

    return t1>t2;
}

bool sortMostAttractiveG(Girl &a, Girl &b)
{
    int t1 = a.getAttractiveness();
    int t2 = b.getAttractiveness();

    return t1>t2;
}

bool sortMaintenanceCost(Girl &a, Girl &b)
{
    return a.getMaintenanceCost() < b.getMaintenanceCost();
}

void makeNewCouples(vector<Boy> &B, vector<Girl> &G, vector<Couple> &C)
{
    for(int j = 1; j < 3; j++) {

        //!Make new couples, one boy then one girl etc.
        sort(B.begin(), B.end(), sortMostAttractiveB);
        sort(G.begin(), G.end(), sortMaintenanceCost);
        vector<Girl>::iterator g = G.begin();
        vector<Boy>::iterator b = B.begin();
        vector<Girl>::iterator g2;
        vector<Boy>::iterator b2;
        vector<Couple>::iterator c;
        int noOfRelations = 0;
        int bI, gI;
        int type;
        int temp1 = 0;
        int temp2 = 0;
        int i = 0;
        while(noOfRelations < 1000) {
            //cout << i << endl;
            i++;
            if(i%2) {
                sort(G.begin(), G.end(), sortMaintenanceCost);
                if(g < G.end()) {
                    while(g < G.end() && g->isCommitted())
                        g++;
                    //cout <<"here";
                    type = g->getBoyChoice();
                    /*
                    BoyChoice = 0 => Most attractive;
                    BoyChoice = 1 => Most rich;
                    BoyChoice = 2 => Most intelligent;
                    */
                    if(type == 0) {
                        sort(B.begin(), B.end(), sortMostAttractiveB);
                        b2 = B.begin();
                    } else if(type == 1) {
                        sort(B.begin(), B.end(), sortMostRichB);
                        b2 = B.begin();
                    } else if(type == 2) {
                        sort(B.begin(), B.end(), sortMostIntelligentB);
                        b2 = B.begin();
                    }
                    while(b2 < B.end()) {
                        if((b2->getBudget() >= g->getMaintenanceCost()) && (b2->getMinAttraction() <= g->getAttractiveness()) && (!(b2->isCommitted())) && (!(g->isCommitted()))) {
                            b2->setCommitted(1);
                            g->setCommitted(1);
                            bI = b2->getIndex();
                            gI = g->getIndex();
                            Couple cp(noOfRelations, bI, gI);
                            //cout << b->getBudget() << " MC " << g->getMaintenanceCost() << endl;
                            C.push_back(cp);
                            noOfRelations++;
                            break;
                        }
                        else
                            b2++;
                    }
                    g++;
                } else {
                    temp1 = 1;
                }
            } else {
                sort(B.begin(), B.end(), sortMostAttractiveB);
                if(b < B.end() && noOfRelations < 1000) {
                    while(b < B.end() && !b->isCommitted())
                        b++;
                    sort(G.begin(), G.end(), sortMostAttractiveG);
                    g2 = G.begin();
                    while(g2->isCommitted() && g2 < G.end())
                        g2++;
                    if(!b->isCommitted() && !g2->isCommitted()) {
                        bI = b->getIndex();
                        gI = g2->getIndex();
                        Couple cp(noOfRelations, bI, gI);
                        b->setCommitted(1);
                        g2->setCommitted(1);
                        //cout << b->getBudget() << " MC " << g->getMaintenanceCost() << endl;
                        C.push_back(cp);
                        noOfRelations++;
                        break;
                    }
                    b++;
                } else {
                    temp2 = 1;
                }
            }
            if(temp1 == 1 && temp2 == 1)
                break;
        }
    }
    writeCouplesToFile(C);
    writeBoysToFile(B);
    writeGirlsToFile(G);  
}

void getKNHappiestCouples(vector<Couple> &C, int k)
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