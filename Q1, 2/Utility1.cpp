#include "Utility2.cpp"

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

void ComputeCouples()
{
    vector<Boy> B;
    vector<Girl> G;
    vector<Couple> C;
    ifstream input;
    input.open("BoyList.csv");
    string name;
    int attractiveness;
    int budget;
    int intelligenceLevel;
    int type;
    int minAttraction;
    int i;
    int boyChoice;
    for(i = 0; i < 1000; i++) {
        input >> name >> attractiveness >> budget >> intelligenceLevel >> type >> minAttraction;
        Boy b(name, attractiveness, budget, intelligenceLevel, type, minAttraction);
        B.push_back(b);
    }
    input.close();
    input.open("GirlList.csv");
    for(i = 0; i < 1000; i++) {
        input >> name >> attractiveness >> budget >> intelligenceLevel >> type >> minAttraction;
        Girl g(name, attractiveness, budget, intelligenceLevel, type, minAttraction);
        G.push_back(g);
    }
    int noOfRelations = 0;
    vector<Girl>::iterator g;
    vector<Boy>::iterator b;
    vector<Couple>::iterator c;
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
                Couple cp(&*b, &*g);
                //cout << b->getBudget() << " MC " << g->getMaintenanceCost() << endl;
                C.push_back(cp);
                noOfRelations++;
                break;
            }
            else
                b++;
        }
        
    }
    ofstream output;
    output.open("Q1.csv");
    for(c = C.begin(); c < C.end(); c++) {
        cout << c->getBoyName() << " " << c->getGirlName() << endl;
        output << c->getBoyName() << " " << c->getGirlName() << endl;
    }
    output.close();
    ComputeGifts(C);
}