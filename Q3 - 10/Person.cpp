#include "Person.h"

Person::Person(int index, std::string name, int attractiveness, int intelligenceLevel, int type)
{
    this->index = index;
    this->name = name;
    this->attractiveness = attractiveness;
    this->intelligenceLevel = intelligenceLevel;
    this->type = type;
    this->committed = 0;    
}

int Person::getIndex()
{
    //!Return person's index
    return this->index;    
}

std::string Person::getName()
{
    //!Return person name
    return this->name;
}

int Person::getAttractiveness()
{
    //!Return person attractiveness
    return this->attractiveness;
}

int Person::getIntelligenceLevel()
{
    //!Return gir's intelligence level
    return this->intelligenceLevel;
}

bool Person::isCommitted()
{
    //!Return committed status
    return this->committed;
}

int Person::getType()
{
    //!Return type
    /*!
        BOY:
            Type = 0 => Miser;
            Type = 1 => Generous;
            Type = 2 => Geeks;
        GIRL:
            Type = 0 => Choosy;
            Type = 1 => Normal;
            Type = 2 => Desperate;
    !*/
    return this->type;
}

void Person::setAttractiveness(int attractiveness)
{
    //!Set attractiveness
    this->attractiveness = attractiveness;
}

void Person::setIntelligenceLevel(int intelligenceLevel)
{
    //!Set intelligence level
    this->intelligenceLevel = intelligenceLevel;
}

void Person::setCommitted(bool committed)
{
    //!Set commited status
    this->committed = committed;
}

void Person::setType(int type)
{
    //!Set person type
    this->type = type;
}