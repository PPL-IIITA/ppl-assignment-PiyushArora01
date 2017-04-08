#ifndef GIRL_H_
#define GIRL_H_
#include <cstring>

class Girl
{
public:
    Girl(std::string name, int attractiveness, int maintenanceCost, int intelligenceLevel, int type, int boyChoice);

    std::string getName();
    int getAttractiveness();
    int getMaintenanceCost();
    int getIntelligenceLevel();
    bool isCommitted();
    std::string getPartner();
    int getType();
    int getBoyChoice();
    double getHappiness();
    void setAttractiveness(int attractiveness);
    void setMaintenanceCost(int maintenanceCost);
    void setCommitted(bool committed);
    void setIntelligenceLevel(int intelligenceLevel);
    void setPartner(std::string partner);
    void setType(int type);
    void setHappiness(double happiness);
    void setBoyChoice(int boyChoice);

private:
    std::string name;
    int attractiveness;
    int maintenanceCost;
    int intelligenceLevel;
    bool committed;
    std::string partner;
    int type;
    int boyChoice;
    double happiness;
};

#endif