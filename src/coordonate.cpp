#include "coordonate.h"
#include <iostream>
using namespace std;
coordonate::coordonate()
{
    //ctor
}

coordonate::~coordonate()
{
    //dtor
}
int coordonate::operator<(coordonate &ob)
{
    if(x<ob.x&&y<ob.y)
        return 1;
    return 0;
}
void coordonate::operator++(int)
{
    x++;
    y++;
}
int coordonate::operator==(coordonate &ob2)
{
    if(this->x==ob2.x&&this->y==ob2.y)
        return 1;
    return 0;
}
ostream& operator<<(ostream &c, coordonate &ob)
{
    c<<ob.x<<" "<<ob.y<<" ";
    return c;
}
