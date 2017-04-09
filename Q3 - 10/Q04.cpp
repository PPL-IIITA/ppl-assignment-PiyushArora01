#include "Includes.cpp"

int main()
{
    vector<Boy> B;
    vector<Girl> G;
    vector<Couple> C;
    getBoysList(B);
    getGirlsList(G);
    getCouplesList(C);
    int k;
    cout << "\nEnter k to perform breakups between k least happy couples: ";
    cin >> k;
    while(k > C.size()) {
        cout << "k too large. Max Number of Couples is: " << C.size() << endl << "Enter k: ";
        cin >> k;
    }
    performBreakup(B, G, C, k);
    return 0;
}