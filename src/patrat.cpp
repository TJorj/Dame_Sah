#include "patrat.h"
#include <iostream>
using namespace std;
patrat::patrat()
{
    //ctor

}

patrat::~patrat()
{
    //dtor
}
void patrat::initializeaza(int i, int j)
{

    c_s.set_c(j*70,(j+1)*70-1,i*70,(i+1)*70-1);
    x_y.x=i;
    x_y.y=j;
}

void patrat::deseneaza(sf::RenderWindow &window)
{
    sf::RectangleShape patrat(sf::Vector2f(70,70));
    patrat.setPosition(x_y.x*70,x_y.y*70);
    if(x_y.x%2==0&&x_y.y%2==0)
        patrat.setFillColor(sf::Color(255,255,255));
    if(x_y.x%2==1&&x_y.y%2==1)
        patrat.setFillColor(sf::Color(255,255,255));
    if(x_y.x%2==0&&x_y.y%2==1)
        patrat.setFillColor(sf::Color(0,0,0));
    if(x_y.x%2==1&&x_y.y%2==0)
        patrat.setFillColor(sf::Color(0,0,0));
    window.draw(patrat);
}
c_spatiu& patrat::get_c_s()
{
    return c_s;
}
int patrat::get_x_s()
{
    return c_s.x_start;
}
int patrat::get_x_e()
{
    return c_s.x_end;
}
int patrat::get_y_s()
{
    return c_s.y_start;
}
int patrat::get_y_e()
{
    return c_s.y_end;
}

