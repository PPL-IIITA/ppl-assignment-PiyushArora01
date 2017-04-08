#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Couple2.cpp"
using namespace std;

bool cmp1(Couple2 &c1, Couple2 &c2)
{
    return c1.compatibility < c2.compatibility;
}

bool cmp2(Couple2 &c1, Couple2 &c2)
{
    return c1.happiness < c2.happiness;
}

int main()
{
    int k;
    cout << "Enter k " << endl;
    cin >> k;
    ifstream op;
    op.open("Q2.csv");
    vector<Couple2> C;
    int i;
    string boyName; string girlName; double compatibility; double happiness;
    for(i = 0; i < 10; i++) {
        op >> boyName >> girlName >> compatibility >> happiness;
        Couple2 cc(boyName, girlName, compatibility, happiness);
        //cout << boyName << girlName << compatibility << happiness << endl;
        C.push_back(cc);
    }
    op.close();
    sort(C.begin(), C.end(), cmp1);
    vector<Couple2>::iterator it;
    it = C.begin();
    cout << "Most Compatible\n";
    for(i = 0; i < k; i++) {
        cout << it->boyName << " " << it->girlName << " " << it->compatibility << " " << it->happiness << endl;
        it++;
    }
    sort(C.begin(), C.end(), cmp2);
    it = C.begin();
    cout << "Most Happy\n";
    for(i = 0; i < k; i++) {
        cout << it->boyName << " " << it->girlName << " " << it->compatibility << " " << it->happiness << endl;
        it++;
    }
    return 0;
}