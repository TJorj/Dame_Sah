#include "dama_n.h"
#include "dama_a.h"
#include "globala.h"
#include<iostream>
#include"myexceptions.h"
using namespace std;
dama_n::dama_n()
{
    //ctor
    is_highlight=0;
    nume_textura="damaneagra.png";
    nume_highlight="damaneagrahighlight.png";
    nume_textura_baza="damaneagra.png";
    nume_textura_incoronat="damaneagraincoronata.png";
    nume_highlight_incoronat="damaneagraincoronatahighlight.png";
    nume_highlight_baza="damaneagrahighlight.png";
    in_joc=0;
    incoronat=0;
}

dama_n::~dama_n()
{
    //dtor
}

void dama_n::operator++(int )
{
    for(int i=0;i<8;i++)
        if(p2[i].get_x()==this->get_x()-1&&p2[i].get_y()==this->get_y()+1)
            throw este;
    for(int i=0;i<8;i++)
        if(p1[i].get_x()==this->get_x()-1&&p1[i].get_y()==this->get_y()+1)
            throw inamic;
    coord(xy.x-1,xy.y+1);
    pozitie(tb.get_c_s(xy.x,xy.y));
}
void dama_n::operator++()
{
    for(int i=0;i<8;i++)
        if(p2[i].get_x()==this->get_x()-1&&p2[i].get_y()==this->get_y()-1)
            throw este;
    for(int i=0;i<8;i++)
        if(p1[i].get_x()==this->get_x()-1&&p1[i].get_y()==this->get_y()-1)
            throw inamic;
    coord(xy.x-1,xy.y-1);

    pozitie(tb.get_c_s(xy.x,xy.y));
}
void dama_n::operator+(coordonate& mat_poz)
{

  if(mat_poz.x==-1&&mat_poz.y==-1)
    throw afara;
  for(int i=0;i<8;i++)
        if(p2[i].get_x()==mat_poz.x&&p2[i].get_y()==mat_poz.y)
            throw este;
    for(int i=0;i<8;i++)
        if( p1[i].get_x()==mat_poz.x&&p1[i].get_y()==mat_poz.y)
            throw inamic;
        coordonate temp;
      temp.x=mat_poz.x;
      temp.y=mat_poz.y;
        for(int i=0; i<8; i++)
      if(mat_poz.x>get_coord().x&&mat_poz.y>get_coord().y)
       for( coordonate coord=get_coord();coord.x<temp.x;coord++)
           {
            if(p1[i].get_coord()==coord)
               {
                p1[i].pune_out();
               }
           }
        else
             for( coordonate coord=get_coord();coord.x<temp.x;coord.x++,coord.y--)
           {
            if(p1[i].get_coord()==coord)
                {

                p1[i].pune_out();
               }

           }

      coord(mat_poz.x,mat_poz.y);

      pozitie(tb.get_c_s(mat_poz.x,mat_poz.y));
}
void dama_n::operator-(coordonate& mat_poz)
{

  if(mat_poz.x==-1&&mat_poz.y==-1)
    throw afara;
  for(int i=0;i<8;i++)
        if(p2[i].get_x()==mat_poz.x&&p2[i].get_y()==mat_poz.y)
            throw este;
    for(int i=0;i<8;i++)
        if( p1[i].get_x()==mat_poz.x&&p1[i].get_y()==mat_poz.y)
            throw inamic;
    coordonate temp;
      temp.x=mat_poz.x;
      temp.y=mat_poz.y;
    for(int i=0; i<8; i++)
      if(mat_poz.y>get_coord().y)
       for( coordonate coord=get_coord();coord.x>temp.x;coord.x--,coord.y++)
           {
            if(p1[i].get_coord()==coord)
               {
                p1[i].pune_out();
               }
           }
        else
             for( coordonate coord=get_coord();coord.x>temp.x;coord.x--,coord.y--)
           {
            if(p1[i].get_coord()==coord)
                {

                p1[i].pune_out();
               }

           }


      coord(mat_poz.x,mat_poz.y);

     pozitie(tb.get_c_s(mat_poz.x,mat_poz.y));
}
int dama_n::get_x_1()
{
    return xy.x-1;
}
int dama_n::get_x_2()
{
    return xy.x-2;
}
