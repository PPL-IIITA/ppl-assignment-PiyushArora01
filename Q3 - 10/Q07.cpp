#include "Includes.cpp"
#include "Q07Utility.cpp"
#define MAX 1000

int main()
{
    vector<Boy> B;
    vector<Girl> G;
    vector<Couple> C;
    getBoysList(B);
    getGirlsList(G);
    getCouplesList(C);
    sortAllByIndex(B, G, C);
    writeBoysToFile(B);
    writeGirlsToFile(G);
    writeCouplesToFile(C);
    int t;
    cout << "\nChoose:\n\t1 for array\n\t2 for binary search\n\t3 for hash table\n\t4 for default\n";
    cin >> t;
    while(t > 4) {
        cout << "Invalid value.\nEnter t: ";
        cin >> t;
    }
    if(t == 1) {
        arrayImp(C, B, G);
    } else if(t == 2) {
        bs(C, B, G);
    } else if(t == 3) {
        hashf(C, B, G);
    } else if(t == 4) {
        arrayImp(C, B, G);
    }
    return 0;
}