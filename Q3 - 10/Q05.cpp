#include "Includes.cpp"
#include "Q05Utility.cpp"

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
    makeNewCouples(B, G, C);
    computeGifts(B, G, C, EG, LG, UG);
    writeEGiftsToFile(EG);
    writeLGiftsToFile(LG);
    writeUGiftsToFile(UG);
    computeCoupleHappiness(B, G, C);
    computeCoupleCompatibility(B, G, C);
    int k;
    cout << "\nEnter k to get k happiest couples: ";
    cin >> k;
    while(k > C.size()) {
        cout << "k too large. Max Number of Couples is: " << C.size() << endl << "Enter k: ";
        cin >> k;
    }
    getKNHappiestCouples(C, k);
    cout << "\nSuccessfully written to file!\n\nFile Location CSV/Q05_Happiest.csv\n" << endl;
    return 0;
}