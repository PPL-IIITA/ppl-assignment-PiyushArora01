#ifndef BOY_H_
#define BOY_H_

#include "Person.h"

class Boy : public Person
{
public:
    Boy(int index, std::string name, int attractiveness, int intelligenceLevel, int type, int budget, int minAttraction);
    int getBudget();
    int getMinAttraction();
    void setBudget(int budget);
    void setMinAttraction(int minAttraction);

private:
    int budget;
    int minAttraction;
};

#endif