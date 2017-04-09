#include "Includes.cpp"
#include "Q06Utility.cpp"

int main()
{
    vector<Boy> B;
    vector<Girl> G;
    vector<Couple> C;
    getBoysList(B);
    getGirlsList(G);
    getCouplesList(C);
    cout << C.size() << endl << B.size() << endl << G.size() << endl;
    int t;
    cout << "\nEnter t to perform breakups where happiness less than t: ";
    cin >> t;
    if(t > 366) {
        cout << "Enter t less than 366 since an year has maximum 366 days.\nEnter t: ";
        cin >> t;
    }
    performBreakupLT(B, G, C, t);
    return 0;
    cout << "\nLog files updated successfully!\n";
}