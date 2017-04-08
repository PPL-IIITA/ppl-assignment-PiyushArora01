#include "Includes.cpp"

int main()
{
    vector<Boy> b;
    vector<Girl> g;
    vector<Couple> c;
    getBoysList(b);
    getGirlsList(g);
    makeCouples(b, g, c);
    writeCouplesToFile(c);
}