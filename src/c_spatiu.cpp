#include "c_spatiu.h"

c_spatiu::c_spatiu()
{
    //ctor
}
c_spatiu::c_spatiu(int _x_s,int _x_e,int _y_s,int _y_e)
{

     x_start=_x_s;
  x_end=_x_e;
  y_start=_y_s;
  y_end=_y_e;
}
c_spatiu::~c_spatiu()
{
    //dtor
}
void c_spatiu::set_c(int _x_s,int _x_e,int _y_s,int _y_e)
{
  x_start=_x_s;
  x_end=_x_e;
  y_start=_y_s;
  y_end=_y_e;
}

ostream& operator<<(ostream &c, c_spatiu &ob)
{
    c<<ob.x_start<<" "<<ob.x_end<<" "<<ob.y_start<<" "<<ob.y_end<<" ";
    return c;
}
