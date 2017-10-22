#include "piesa.h"
#include<iostream>
using namespace std;
piesa::piesa()
{
    //ctor
}

piesa::~piesa()
{
    //dtor
}
void piesa::deseneaza(sf::RenderWindow &window)
{
    sf::Texture texture;
    if(is_highlight==0)
    {
        if (!texture.loadFromFile(nume_textura))
        {
            std::cout<<"FAILED TO LOAD TEXTURE IMAGE";
        }
        sf::Sprite dama;
        dama.setTexture(texture);
        dama.setPosition(xy.y*70,xy.x*70);
        window.draw(dama);
    }
    else
    {
        if (!texture.loadFromFile(nume_highlight))
        {
            std::cout<<"FAILED TO LOAD TEXTURE IMAGE";
        }
        sf::Sprite dama;
        dama.setTexture(texture);
        dama.setPosition(xy.y*70,xy.x*70);
        window.draw(dama);
    }
}
void piesa::pozitie(c_spatiu& c)
{

    c_s=c;
}
void piesa::coord(int _x,int _y)
{


    xy.x=_x;
    xy.y=_y;
}
void piesa::pune_in()
{
    in_joc=1;
}
void piesa::pune_out()
{
    in_joc=0;
    xy.x=-10;
    xy.y=-10;
    c_spatiu dummy(-10,-10,-10,-10);
    pozitie(dummy);
}
int piesa::stare()
{
    return in_joc;
}
int piesa::get_x()
{
    return xy.x;
}
int piesa::get_y()
{
    return xy.y;
}
void piesa::highlight_on()
{
    is_highlight=1;
}
void piesa::highlight_off()
{
    is_highlight=0;
}
void piesa::incoroneaza()
{
    incoronat=1;
    nume_textura=nume_textura_incoronat;
    nume_highlight=nume_highlight_incoronat;

}
int piesa::tip()
{
    return incoronat;
}
coordonate& piesa::get_coord()
{
    return xy;
}
c_spatiu& piesa::get_c_spatiu()
{
    return c_s;
}
void piesa::decoroneaza()
{
    incoronat=0;
    nume_textura=nume_textura_baza;
    nume_highlight=nume_highlight_baza;

}

int piesa::is_clicked(sf::Vector2i localPosition)
{

     if(c_s.x_start<=localPosition.x&&c_s.x_end>=localPosition.x&&c_s.y_start<=localPosition.y&&c_s.y_end>=localPosition.y/*&&p1[i].stare()==1/*/)
            return 1;
     return 0;
}

