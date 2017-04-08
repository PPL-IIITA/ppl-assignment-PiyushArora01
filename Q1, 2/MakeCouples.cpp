#include "Boy.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool cmp(Boy& a, Boy& b)
{
    if(a.isCommitted())
        return 1;
    if(b.isCommitted())
        return 0;
    int t1 = a.getBudget();
    int t2 = b.getBudget();

    return t1<t2;
}

int main()
{
    vector<Boy> B;
    ifstream input;
    input.open("BoyList.csv");
    string name;
    int attractiveness;
    int budget;
    int intelligenceLevel;
    int type;
    int minAttraction;
    input >> name >> attractiveness >> budget >> intelligenceLevel >> type >> minAttraction;
    cout << name << " " << attractiveness << " " << budget << endl;
    Boy b("Aaron",9,14403,7,12,0);
    Boy b2("Aaron",9,12403,7,12,0);
    cout << b.getBudget();
    B.push_back(b);
    B.push_back(b2);
    vector<Boy>::iterator elem;
    elem = max_element(B.begin(), B.end(), cmp);
    elem->setBudget(32421);
    cout << elem->getBudget();
    return 0;
}