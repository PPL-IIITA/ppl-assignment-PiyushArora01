/*!
This files generates the details of boys, girls and gifts and stores them in a file.
!*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    srand(time(NULL));
    ifstream input;
    ofstream output;
    int i, n = 1000;
    /*!
    Generate Boy details
    !*/
    {
        string name;
        int attractiveness;
        int budget;
        int intelligenceLevel;
        int type;
        int minAttraction;
        bool committed;
        input.open("Names/BoyNames.txt");
        output.open("CSV/BoyList.csv");
        for(i = 0; i < n; i++) {
            input >> name;
            attractiveness = rand()%100 + 1;
            intelligenceLevel = rand()%10 + 1;
            minAttraction = rand()%100 + 1;
            type = rand()%3;
            budget = rand()%5000 + 10000;
            output << i << " , " << name << " , " << attractiveness << " , " << intelligenceLevel << " , " << type << " , " << budget << " , " << minAttraction << " , " << committed << endl;
        }
        input.close();
        output.close();
    }

    /*!
    Generate Girl details
    !*/
    {
        string name;
        int attractiveness;
        int maintenanceCost;
        int intelligenceLevel;
        int type;
        int boyChoice;
        bool committed;
        input.open("Names/GirlNames.txt");
        output.open("CSV/GirlList.csv");
        for(i = 0; i < n; i++) {
            input >> name;
            attractiveness = rand()%100 + 1;
            intelligenceLevel = rand()%10 + 1;
            type = rand()%3;
            boyChoice = rand()%3;
            maintenanceCost = rand()%5000 + 10000;
            output << i << " , " << name << " , " << attractiveness << " , " << intelligenceLevel << " , " << type << " , " << maintenanceCost << " , " << boyChoice << " , " << committed << endl;
        }
        input.close();
        output.close();
    }

    /*!
    Generate Gift details
    !*/
    {
        output.open("CSV/EssentialGift.csv");
        int type;
        int price;
        int value;
        int luxuryRating;
        int luxuryDifficultyToObtain;
        int utilityValue;
        int utilityClass;
        int taken = 0;        
        for(i = 0; i < 5000; i++) {
            price = rand()%1000 + 500;
            value = rand()%8 + 1;
            output << i << " , " << price << " , " << value << " , " << taken << endl;
        }
        output.close();
        output.open("CSV/LuxuryGift.csv");
        for(i = 0; i < 2000; i++) {
            price = rand()%3000 + 4000;
            value = rand()%2 + 8;
            luxuryRating = rand()%5 + 1;
            luxuryDifficultyToObtain = rand()%5 + 1;
            output << i+5000 << " , " << price << " , " << value << " , " << luxuryRating << " , " << luxuryDifficultyToObtain << " , " << taken << endl;
        }
        output.close();
        output.open("CSV/UtilityGift.csv");
        for(i = 0; i < 2000; i++) {
            price = rand()%1000 + 200;
            value = rand()%8 + 1;
            utilityValue = rand()%5 + 1;
            utilityClass = rand()%5 + 1;
            output << i+7000 << " , " << price << " , " << value << " , " << utilityValue << " , " << utilityClass << " , " << taken << endl;
        }
        output.close();
    }
    //cout << "Done" << endl;
    return 0;
}