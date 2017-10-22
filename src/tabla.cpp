#include "tabla.h"

tabla::tabla()
{
    //ctor
}

tabla::~tabla()
{
    //dtor
}

void tabla::deseneaza(sf::RenderWindow &window)
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            t[i][j].deseneaza(window);
}

void tabla::initializeaza()
{
      for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            t[i][j].initializeaza(i,j);}

c_spatiu& tabla::get_c_s(int i, int j)
{
    return t[i][j].get_c_s();
}
coordonate tabla::coord_click(sf::Vector2i localPosition)
{

    coordonate  temp;
    if(localPosition.x>560)
        {
                temp.x=-1;
                temp.y=-1;
                return temp;
        }
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(t[i][j].get_x_s()<=localPosition.x&&t[i][j].get_x_e()>=localPosition.x&&t[i][j].get_y_s()<=localPosition.y&&t[i][j].get_y_e()>=localPosition.y)
                {
                    temp.x=i;
                    temp.y=j;
                }
    return temp;
}

