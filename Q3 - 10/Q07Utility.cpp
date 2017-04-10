#include "Q07Utility.h"

void arrayImp(vector<Couple> &C, vector<Boy> &B, vector<Girl> &G)
{
    int arr[MAX][2];
    vector<Couple>::iterator cc;
    vector<Boy>::iterator b;
    vector<Girl>::iterator g;
    int boy;
    int girl;
    int i = 0;
    int c;
    int choice;
    int n;
    int ansF;
    for(cc = C.begin(); cc != C.end(); cc++) {
        boy = cc->getBoy();
        girl = cc->getGirl();
        arr[i][0] = boy;
        arr[i++][1] = girl;
    }
    n = i;
    cout << "Choose:\n\t1 for search by index\n\t2 for search by name \n";
    cin >> choice;
    if(choice == 1) {
        cout << "Enter the boy's index to get his girlfriend (Enter 9999 to exit): ";
        cin >> c;
        while(c != 9999) {
            if(c > 1000) {
                cout << "Invalid value. Exiting.\n";
                return;
            } else {
                ansF = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i][0] == c) {
                        ansF = 1;
                        b = B.begin() + arr[i][0];
                        g = G.begin() + arr[i][1];
                        cout << "\tBoy Name: " << b->getName() << "Girl Name: " << g->getName() << endl;
                        break;
                    }
                }
                if(ansF == 0)
                    cout << "\tNo girlfriend!" << endl;
            }
            cout << "Enter Next: ";
            cin >> c;
        }
    } else if(choice == 2) {
        string s;
        cout << "Enter the boy's name to get his girlfriend (Enter 9999 to exit): ";
        cin >> s;
        while(s.compare("9999") != 0) {
            ansF = 0;
            for(i = 0; i < n; i++) {
                b = B.begin() + arr[i][0];
                if(s.compare(b->getName()) == 0) {
                    ansF = 1;
                    g = G.begin() + arr[i][1];
                    cout << "\tBoy Name: " << b->getName() << " Girl Name: " << g->getName() << endl;
                    break;
                }
            }
            if(ansF == 0)
                cout << "\tNo girlfriend or does not exist!" << endl;
            cout << "Enter Next: ";
            cin >> s;
        }
    } else {
        cout << "Invalid value. Exiting.\n";
        return;
    }
}

void bs(vector<Couple> &C, vector<Boy> &B, vector<Girl> &G)
{
    int arr[MAX][2];
    vector<Couple>::iterator cc;
    vector<Boy>::iterator b;
    vector<Girl>::iterator g;
    int boy;
    int girl;
    int i = 0;
    int c;
    int choice;
    int n;
    int ansF;
    int first;
    int last;
    int middle;
    for(cc = C.begin(); cc != C.end(); cc++) {
        boy = cc->getBoy();
        girl = cc->getGirl();
        arr[i][0] = boy;
        arr[i++][1] = girl;
    }
    n = i;
    qsort(arr, 10, sizeof(*arr),
        [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[0] < rhs[0]) ? -1
                :  ((rhs[0] < lhs[0]) ? 1
                :  (lhs[1] < rhs[1] ? -1
                :  ((rhs[1] < lhs[1] ? 1 : 0))));
        });
    cout << "Enter the boy's index to get his girlfriend (Enter 9999 to exit): ";
    cin >> c;
    while(c != 9999) {
        if(c > 1000) {
            cout << "Invalid value. Exiting.\n";
            return;
        } else {
            ansF = 0;
            first = 0;
            last = n-1;
            middle = (first+last)/2;
            while (first <= last) {
                if(arr[middle][0] < c) {
                    first = middle + 1;
                }
                else if(arr[middle][0] == c) {
                    ansF = 1;
                    b = B.begin() + arr[middle][0];
                    g = G.begin() + arr[middle][1];
                    cout << "\tBoy Name: " << b->getName() << " Girl Name: " << g->getName() << endl;
                    break;
                }
                else {
                    last = middle - 1;
                }
                middle = (first + last)/2;
            }
            if(first > last) {
                cout << "\tNo girlfriend!\n";
            }
            cout << "Enter Next: ";     
            cin >> c;
        }
    }
}

void hashf(vector<Couple> &C, vector<Boy> &B, vector<Girl> &G)
{
    int arr[MAX];
    vector<Couple>::iterator cc;
    vector<Boy>::iterator b;
    vector<Girl>::iterator g;
    int boy;
    int girl;
    int i = 0;
    int c;
    int choice;
    int n;
    int ansF;
    for(i = 0; i < MAX; i++) {
        arr[i] = 9999;
    }
    for(cc = C.begin(); cc != C.end(); cc++) {
        boy = cc->getBoy();
        girl = cc->getGirl();
        arr[boy] = girl;
        i++;
    }
    n = i;
    cout << "Enter the boy's index to get his girlfriend (Enter 9999 to exit): ";
    cin >> c;
    while(c != 9999) {
        if(c > 1000) {
            cout << "Invalid value. Exiting.\n";
            return;
        } else {
            if(arr[c] == 9999)
                cout << "\tNo girlfriend!" << endl;
            
            else {
                    b = B.begin() + c;
                    g = G.begin() + arr[c];
                    cout << "\tBoy Name: " << b->getName() << " Girl Name: " << g->getName() << endl;
            }
        }
        cout << "Enter Next: ";
        cin >> c;   
    }
    return;   
}