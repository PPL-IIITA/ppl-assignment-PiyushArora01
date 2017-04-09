#include "Includes.cpp"

int main()
{
    vector<Boy> B;
    vector<Girl> G;
    vector<Couple> C;
    vector<EssentialGift> EG;
    vector<LuxuryGift> LG;
    vector<UtilityGift> UG;
    getBoysList(B);
    getGirlsList(G);
    getEGiftList(EG);
    getLGiftList(LG);
    getUGiftList(UG);
    makeCouples(B, G, C);
    computeGifts(B, G, C, EG, LG, UG);
    writeEGiftsToFile(EG);
    writeLGiftsToFile(LG);
    writeUGiftsToFile(UG);
    computeCoupleHappiness(B, G, C);
    computeCoupleCompatibility(B, G, C);
    int k;
    cout << "\nEnter k to get k happiest and k most compatible couples: ";
    cin >> k;
    while(k > C.size()) {
        cout << "k too large. Max Number of Couples is: " << C.size() << endl << "Enter k: ";
        cin >> k;
    }
    getKHappiestCouples(C, k);
    getKMostCompatibleCouples(C, k);
    cout << "\nSuccessfully written to file!\n\nFile Location CSV/Q03_*.csv\n" << endl;
    return 0;
}