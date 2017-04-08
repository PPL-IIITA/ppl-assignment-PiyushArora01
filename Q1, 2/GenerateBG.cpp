/*
This files generates the details of boys, girls and gifts and stores them in a file.
*/

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
    /*
    Generate Boy details
    */
    {
        string name;
        int attractiveness;
        int budget;
        int intelligenceLevel;
        int type;
        int minAttraction;
        input.open("BoyNames.txt");
        output.open("BoyList.csv");
        for(i = 0; i < n; i++) {
            input >> name;
            attractiveness = rand()%100 + 1;
            intelligenceLevel = rand()%10 + 1;
            minAttraction = rand()%100 + 1;
            type = rand()%3;
            budget = rand()%5000 + 10000;
            output << name << " " << attractiveness << " " << budget << " " << intelligenceLevel << " " << minAttraction << " " << type << endl;
        }
        input.close();
        output.close();
    }

    /*
    Generate Girl details
    */
    {
        string name;
        int attractiveness;
        int maintenanceCost;
        int intelligenceLevel;
        int type;
        int boyChoice;
        input.open("GirlNames.txt");
        output.open("GirlList.csv");
        for(i = 0; i < n; i++) {
            input >> name;
            attractiveness = rand()%100 + 1;
            intelligenceLevel = rand()%10 + 1;
            type = rand()%3;
            boyChoice = rand()%3;
            maintenanceCost = rand()%5000 + 10000;
            output << name << " " << attractiveness << " " << maintenanceCost << " " << intelligenceLevel << " " << type << " " << boyChoice << endl;
        }
        input.close();
        output.close();
    }

    /*
    Generate Gift details
    */
    {
        output.open("EssentialGift.csv");
        int type;
        int price;
        int value;
        int luxuryRating;
        int luxuryDifficultyToObtain;
        int utilityValue;
        int utilityClass;        
        for(i = 0; i < 5000; i++) {
            price = rand()%1000 + 500;
            value = rand()%8 + 1;
            output << price << "," << value << endl;
        }
        output.close();
        output.open("LuxuryGift.csv");
        for(i = 0; i < 1000; i++) {
            price = rand()%3000 + 4000;
            value = rand()%2 + 8;
            luxuryRating = rand()%5 + 1;
            luxuryDifficultyToObtain = rand()%5 + 1;
            output << price << " " << value << " " << luxuryRating << " " << luxuryDifficultyToObtain << endl;
        }
        output.close();
        output.open("UtilityGift.csv");
        for(i = 0; i < 2000; i++) {
            price = rand()%1000 + 200;
            value = rand()%8 + 1;
            utilityValue = rand()%5 + 1;
            utilityClass = rand()%5 + 1;
            output << price << " " << value << " " << utilityValue << " " << utilityClass << endl;
        }
        output.close();
        
    }
    return 0;
}