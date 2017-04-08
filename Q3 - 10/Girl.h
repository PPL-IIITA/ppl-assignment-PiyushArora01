#ifndef GIRL_H_
#define GIRL_H_

#include "Person.h"

class Girl : public Person
{
public:
    Girl(int index, std::string name, int attractiveness, int intelligenceLevel, int type, int maintenanceCost, int boyChoice);
    int getMaintenanceCost();
    int getBoyChoice();
    void setMaintenanceCost(int maintenanceCost);
    void setBoyChoice(int boyChoice);

private:
    int maintenanceCost;
    int boyChoice;
};

#endif