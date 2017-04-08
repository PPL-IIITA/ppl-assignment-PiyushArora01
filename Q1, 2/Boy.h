#ifndef BOY_H_
#define BOY_H_
#include <string>

class Boy
{
public:
    Boy(std::string name, int attractiveness, int budget, int intelligenceLevel, int type, int minAttraction);
    std::string getName();
    int getAttractiveness();
    int getBudget();
    int getIntelligenceLevel();
    bool isCommitted();
    std::string getPartner();
    int getType();
    double getHappiness();
    int getMinAttraction();
    void setAttractiveness(int attractiveness);
    void setBudget(int budget);
    void setCommitted(bool committed);
    void setIntelligenceLevel(int intelligenceLevel);
    void setPartner(std::string partner);
    void setType(int type);
    void setHappiness(double happiness);
    void setMinAttraction(int minAttraction);

private:
    std::string name;
    int attractiveness;
    int budget;
    int intelligenceLevel;
    bool committed;
    std::string partner;
    double happiness;
    int type;
    int minAttraction;
};

#endif