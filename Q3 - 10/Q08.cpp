#include "Includes.cpp"
#include "Q08Utility.cpp"

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
    getCouplesList(C);
    getEGiftList(EG);
    getLGiftList(LG);
    getUGiftList(UG);
    sort(EG.begin(), EG.end(), sortGiftByPrice);
    sort(LG.begin(), LG.end(), sortGiftByPrice);
    sort(UG.begin(), UG.end(), sortGiftByPrice);
    sortAllByIndex(B, G, C);        
    int t;
    cout << "\nChoose:\n\t1 for greedy gift allocation algorithm\n\t2 for atleast one of each type\n\t3 for default\n";
    cin >> t;
    while(t > 3) {
        cout << "Invalid value.\nEnter t: ";
        cin >> t;
    }
    if(t == 1) {
        computeGifts(B, G, C, EG, LG, UG);
    } else if(t == 2) {
        computeGifts2(B, G, C, EG, LG, UG);
    } else if(t == 3) {
        computeGifts(B, G, C, EG, LG, UG);
    }
    writeEGiftsToFile(EG);
    writeLGiftsToFile(LG);
    writeUGiftsToFile(UG);
    computeCoupleHappiness(B, G, C);
    computeCoupleCompatibility(B, G, C);
    return 0;
}