class Couple2
{
public:
    Couple2(std::string boyName, std::string girlName, double happiness, double compatibility);
    ~Couple2();
    std::string boyName;
    std::string girlName;
    double happiness;
    double compatibility;
private:
    
};

Couple2::Couple2(std::string boyName, std::string girlName, double happiness, double compatibility)
{
    this->boyName = boyName;
    this->girlName = girlName;
    this->happiness = happiness;
    this->compatibility = compatibility;
}

Couple2::~Couple2()
{
}