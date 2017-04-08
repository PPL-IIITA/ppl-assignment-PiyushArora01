#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
public:
    Person(int index, std::string name, int attractiveness, int intelligenceLevel, int type);
    std::string getName();
    int getIndex();
    int getAttractiveness();
    int getIntelligenceLevel();
    bool isCommitted();
    int getType();
    void setAttractiveness(int attractiveness);
    void setCommitted(bool committed);
    void setIntelligenceLevel(int intelligenceLevel);
    void setType(int type);

private:
    int index;
    std::string name;
    int attractiveness;
    int intelligenceLevel;
    bool committed;
    int type;
};

#endif