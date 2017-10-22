#include<iostream>
#include <SFML/Graphics.hpp>
#include "dama_a.h"
#include "dama_n.h"
#include "globala.h"
#include "string"
#include "myexceptions.h"
#include<coordonate.h>
tabla tb;
este_piesa este;
piesa_inamic inamic;
afara_ecran afara;
dama_a p1[8];
dama_n p2[8];
string n;
int in_mutare=0,ob_cur,jucator_cur=1,v=0,culoare=0;
using namespace std;
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow fereastra_main(sf::VideoMode(965, 560), "Joc de Dame", sf::Style::Titlebar | sf::Style::Close, settings);  // create the window
    fereastra_main.setVerticalSyncEnabled(true);
    tb.initializeaza();
    initiazare_piese();
    while (fereastra_main.isOpen())     // run the program as long as the window is open
    {
        fereastra_main.clear(sf::Color::Black);  // clear the window with black color
        tb.deseneaza(fereastra_main);
        for(int i=0; i<8; i++)
        {
            if(p1[i].stare())
                p1[i].deseneaza(fereastra_main);
            if(p2[i].stare())
                p2[i].deseneaza(fereastra_main);
        }
        sf::Event event;
        while (fereastra_main.pollEvent(event))// check all the window's events that were triggered since the last iteration of the loop
        {
            if (event.type == sf::Event::Closed) // "close requested" event: we close the window
                fereastra_main.close();
            if (event.type==sf::Event::MouseButtonReleased&&event.mouseButton.button == sf::Mouse::Left)
            {
                switch(determina_locatie(sf::Mouse::getPosition(fereastra_main)))
                {
                case 1:
                    joc_nou();
                    break;
                case 2:
                    save_game();
                    break;
                case 3:
                    load_game();
                    break;
                case 4:
                    n="Todosi George Vasile \n\t      Grupa 3124 \n  Anul 2 Calculatoare";
                default:
                    break;
                }
                sf::Vector2i localPosition;
                coordonate mat_poz;
                localPosition=sf::Mouse::getPosition(fereastra_main);
                mat_poz=tb.coord_click(localPosition);
                if(in_mutare==0)
                {
                    for(int i=0; i<8; i++)
                        if(jucator_cur==1)
                        {
                            if(p1[i].is_clicked(localPosition))
                            {
                                p1[i].highlight_on();
                                in_mutare=1;
                                ob_cur=i;
                            }
                        }
                        else
                        {
                            if(p2[i].is_clicked(localPosition))
                            {
                                p2[i].highlight_on();
                                in_mutare=1;
                                ob_cur=i;
                            }
                        }
                }
                else if(jucator_cur==1)
                {
                    if(p1[ob_cur].tip()==1)
                    {
                        if(p1[ob_cur].get_x()<mat_poz.x)
                            if(legalitate <dama_a> (p1[ob_cur],mat_poz))
                                try
                                {
                                    p1[ob_cur]+mat_poz;
                                    schimba_jucator <dama_a> (p1[ob_cur]);
                                }
                                catch(afara_ecran &a)
                                {
                                    n=a.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(este_piesa &e)
                                {
                                    n=e.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(piesa_inamic &i)
                                {
                                    n=i.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                            else
                            {
                                n="Mutare ilegala";
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {
                            if(legalitate <dama_a> (p1[ob_cur],mat_poz))
                                try
                                {
                                    p1[ob_cur]-mat_poz;
                                    schimba_jucator <dama_a> (p1[ob_cur]);
                                }
                                catch(afara_ecran &a)
                                {
                                    n=a.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(este_piesa &e)
                                {
                                    n=e.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(piesa_inamic &i)
                                {
                                    n=i.what();
                                    deselecteaza <dama_a> (p1[ob_cur]);
                                    schimba_culoare();
                                }
                            else
                            {
                                n="Mutare ilegala";
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                        }
                    }
                    else if(ilegalitate_generala(&p1[ob_cur],mat_poz))
                    {
                        n="Mutare Ilegala ";
                        deselecteaza <dama_a> (p1[ob_cur]);
                        schimba_culoare();
                    }
                    if(mutare_1_dreapta(&p1[ob_cur],mat_poz))
                        try
                        {
                            p1[ob_cur]+mat_poz;
                            schimba_jucator <dama_a> (p1[ob_cur]);
                        }
                        catch(este_piesa& e)
                        {
                            n=e.what();
                            deselecteaza <dama_a> (p1[ob_cur]);
                            schimba_culoare();
                        }
                        catch(piesa_inamic& i)
                        {
                            n=i.what();
                            deselecteaza <dama_a> (p1[ob_cur]);
                            schimba_culoare();

                        }
                    if(mutare_1_stanga(&p1[ob_cur],mat_poz))
                        try
                        {
                            ++p1[ob_cur];
                            schimba_jucator <dama_a> (p1[ob_cur]);
                        }
                        catch(este_piesa& e)
                        {
                            n=e.what();
                            deselecteaza <dama_a> (p1[ob_cur]);
                            schimba_culoare();
                        }
                        catch(piesa_inamic& i)
                        {
                            n=i.what();
                            deselecteaza <dama_a> (p1[ob_cur]);
                            schimba_culoare();

                        }
                    if(mutare_2_dreapta(&p1[ob_cur],mat_poz))
                    {
                        int ok=0;
                        for(int i=0; i<8; i++)
                            if(p2[i].get_x()==p1[ob_cur].get_x()+1&&p2[i].get_y()==p1[ob_cur].get_y()+1)
                                ok=1;
                        if(ok)
                            try
                            {
                                p1[ob_cur]+mat_poz;
PA1:
                                if(posibilitati_stanga_jos(p1[ob_cur],p2,p1)||posibilitati_dreapta_jos(p1[ob_cur],p2,p1)||posibilitati_stanga_sus(p1[ob_cur],p2,p1)||posibilitati_dreapta_sus(p1[ob_cur],p2,p1))
                                {
                                    coordonate temp;
                                    switch(continua_miscare())
                                    {
                                    case 0:
                                        schimba_jucator <dama_a> (p1[ob_cur]);
                                        break;
                                    case 1:
                                        temp.x=p1[ob_cur].get_x()-2;
                                        temp.y=p1[ob_cur].get_y()+2;
                                        p1[ob_cur]-temp;
                                        goto PA1;
                                        break;
                                    case 2:
                                        temp.x=p1[ob_cur].get_x()+2;
                                        temp.y=p1[ob_cur].get_y()+2;
                                        p1[ob_cur]+temp;
                                        goto PA1;
                                        break;
                                    case 3:
                                        temp.x=p1[ob_cur].get_x()-2;
                                        temp.y=p1[ob_cur].get_y()-2;
                                        p1[ob_cur]-temp;
                                        goto PA1;
                                        break;
                                    case 4:
                                        temp.x=p1[ob_cur].get_x()+2;
                                        temp.y=p1[ob_cur].get_y()-2;
                                        p1[ob_cur]+temp;
                                        goto PA1;
                                        break;
                                    }
                                }
                                else
                                {
                                    schimba_jucator <dama_a> (p1[ob_cur]);
                                }

                            }
                            catch(afara_ecran &a)
                            {
                                n=a.what();
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                            catch(este_piesa &e)
                            {
                                n=e.what();
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {

                            deselecteaza <dama_a> (p1[ob_cur]);
                        }
                    }
                    if(mutare_2_stanga(&p1[ob_cur],mat_poz))
                    {
                        int ok=0;
                        for(int i=0; i<8; i++)
                            if(p2[i].get_x()==p1[ob_cur].get_x()+1&&p2[i].get_y()==p1[ob_cur].get_y()-1)
                                ok=1;
                        if(ok)
                            try
                            {
                                p1[ob_cur]+mat_poz;
PA2:
                                if(posibilitati_stanga_jos(p1[ob_cur],p2,p1)||posibilitati_dreapta_jos(p1[ob_cur],p2,p1)||posibilitati_stanga_sus(p1[ob_cur],p2,p1)||posibilitati_dreapta_sus(p1[ob_cur],p2,p1))
                                {
                                    coordonate temp;
                                    switch(continua_miscare())
                                    {
                                    case 0:
                                        schimba_jucator <dama_a> (p1[ob_cur]);
                                        break;
                                    case 1:
                                        temp.x=p1[ob_cur].get_x()-2;
                                        temp.y=p1[ob_cur].get_y()+2;
                                        p1[ob_cur]-temp;
                                        goto PA2;
                                        break;
                                    case 2:
                                        temp.x=p1[ob_cur].get_x()+2;
                                        temp.y=p1[ob_cur].get_y()+2;
                                        p1[ob_cur]+temp;
                                        goto PA2;
                                        break;
                                    case 3:
                                        temp.x=p1[ob_cur].get_x()-2;
                                        temp.y=p1[ob_cur].get_y()-2;
                                        p1[ob_cur]-temp;
                                        goto PA2;
                                        break;
                                    case 4:
                                        temp.x=p1[ob_cur].get_x()+2;
                                        temp.y=p1[ob_cur].get_y()-2;
                                        p1[ob_cur]+temp;
                                        goto PA2;
                                        break;
                                    }
                                }
                                else
                                {
                                    schimba_jucator <dama_a> (p1[ob_cur]);
                                }

                            }
                            catch(afara_ecran &a)
                            {
                                n=a.what();
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                            catch(este_piesa &e)
                            {
                                n=e.what();
                                deselecteaza <dama_a> (p1[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {

                            deselecteaza <dama_a> (p1[ob_cur]);
                        }
                    }
                }
                else
                {
                    if(p2[ob_cur].tip()==1)
                    {
                        if(p2[ob_cur].get_x()<mat_poz.x)
                            if(legalitate <dama_n> (p2[ob_cur],mat_poz))
                                try
                                {
                                    p2[ob_cur]+mat_poz;
                                    schimba_jucator <dama_n> (p2[ob_cur]);
                                }
                                catch(afara_ecran &a)
                                {
                                    n=a.what();
                                    schimba_culoare();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                }
                                catch(este_piesa &e)
                                {
                                    n=e.what();
                                    schimba_culoare();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                }
                                catch(piesa_inamic &i)
                                {
                                    n=i.what();
                                    schimba_culoare();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                }
                            else
                            {
                                n="Mutare ilegala";
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {
                            if(legalitate <dama_n> (p2[ob_cur],mat_poz))
                                try
                                {
                                    p2[ob_cur]-mat_poz;
                                    schimba_jucator <dama_n> (p2[ob_cur]);
                                }
                                catch(afara_ecran &a)
                                {
                                    n=a.what();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(este_piesa &e)
                                {
                                    n=e.what();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                    schimba_culoare();
                                }
                                catch(piesa_inamic &i)
                                {
                                    n=i.what();
                                    deselecteaza <dama_n> (p2[ob_cur]);
                                    schimba_culoare();
                                }
                            else
                            {
                                n="Mutare ilegala";
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                        }
                    }
                    else if(ilegalitate_generala(&p2[ob_cur],mat_poz))
                    {
                        n="Mutare Ilegala";
                        deselecteaza <dama_n> (p2[ob_cur]);
                        schimba_culoare();
                    }
                    if(mutare_1_dreapta(&p2[ob_cur],mat_poz))
                        try
                        {
                            p2[ob_cur]++;
                            schimba_jucator <dama_n> (p2[ob_cur]);
                        }
                        catch(este_piesa& e)
                        {
                            n=e.what();
                            deselecteaza <dama_n> (p2[ob_cur]);
                            schimba_culoare();
                        }
                        catch(piesa_inamic& i)
                        {
                            n=i.what();
                            deselecteaza <dama_n> (p2[ob_cur]);
                            schimba_culoare();

                        }
                    if(mutare_1_stanga(&p2[ob_cur],mat_poz))
                        try
                        {
                            ++p2[ob_cur];
                            schimba_jucator <dama_n> (p2[ob_cur]);
                        }
                        catch(este_piesa& e)
                        {
                            n=e.what();
                            deselecteaza <dama_n> (p2[ob_cur]);
                            schimba_culoare();
                        }
                        catch(piesa_inamic& i)
                        {
                            n=i.what();
                            deselecteaza <dama_n> (p2[ob_cur]);
                            schimba_culoare();

                        }
                    if(mutare_2_dreapta(&p2[ob_cur],mat_poz))
                    {
                        int ok=0;
                        for(int i=0; i<8; i++)
                            if(p1[i].get_x()==p2[ob_cur].get_x()-1&&p1[i].get_y()==p2[ob_cur].get_y()+1)
                                ok=1;
                        if(ok)
                            try
                            {
                                p2[ob_cur]-mat_poz;
PN1:
                                if(posibilitati_dreapta_sus(p2[ob_cur],p1,p2)||posibilitati_dreapta_jos(p2[ob_cur],p1,p2)||posibilitati_stanga_sus(p2[ob_cur],p1,p2)||posibilitati_stanga_jos(p2[ob_cur],p1,p2))
                                {
                                    coordonate temp;
                                    switch(continua_miscare())
                                    {
                                    case 0:
                                        schimba_jucator <dama_n> (p2[ob_cur]);
                                        break;
                                    case 1:
                                        temp.x=p2[ob_cur].get_x()-2;
                                        temp.y=p2[ob_cur].get_y()+2;
                                        p2[ob_cur]-temp;
                                        goto PN1;
                                        break;
                                    case 2:
                                        temp.x=p2[ob_cur].get_x()+2;
                                        temp.y=p2[ob_cur].get_y()+2;
                                        p2[ob_cur]+temp;
                                        goto PN1;
                                        break;
                                    case 3:
                                        temp.x=p2[ob_cur].get_x()-2;
                                        temp.y=p2[ob_cur].get_y()-2;
                                        p2[ob_cur]-temp;
                                        goto PN1;
                                        break;
                                    case 4:
                                        temp.x=p2[ob_cur].get_x()+2;
                                        temp.y=p2[ob_cur].get_y()-2;
                                        p2[ob_cur]+temp;
                                        goto PN1;
                                        break;
                                    }
                                }
                                else
                                {
                                    schimba_jucator <dama_n> (p2[ob_cur]);
                                }

                            }
                            catch(afara_ecran &a)
                            {
                                n=a.what();
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                            catch(este_piesa &e)
                            {
                                n=e.what();
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {

                            deselecteaza <dama_n> (p2[ob_cur]);
                        }
                    }
                    if(mutare_2_stanga(&p2[ob_cur],mat_poz))
                    {
                        int ok=0;
                        for(int i=0; i<8; i++)
                            if(p1[i].get_x()==p2[ob_cur].get_x()-1&&p1[i].get_y()==p2[ob_cur].get_y()-1)
                                ok=1;
                        if(ok)
                            try
                            {
                                p2[ob_cur]-mat_poz;
PN2:
                                if(posibilitati_dreapta_sus(p2[ob_cur],p1,p2)||posibilitati_dreapta_jos(p2[ob_cur],p1,p2)||posibilitati_stanga_sus(p2[ob_cur],p1,p2)||posibilitati_stanga_jos(p2[ob_cur],p1,p2))
                                {
                                    coordonate temp;
                                    switch(continua_miscare())
                                    {
                                    case 0:
                                        schimba_jucator <dama_n> (p2[ob_cur]);
                                        break;
                                    case 1:
                                        temp.x=p2[ob_cur].get_x()-2;
                                        temp.y=p2[ob_cur].get_y()+2;
                                        p2[ob_cur]-temp;
                                        goto PN2;
                                        break;
                                    case 2:
                                        temp.x=p2[ob_cur].get_x()+2;
                                        temp.y=p2[ob_cur].get_y()+2;
                                        p2[ob_cur]+temp;
                                        goto PN2;
                                        break;
                                    case 3:
                                        temp.x=p2[ob_cur].get_x()-2;
                                        temp.y=p2[ob_cur].get_y()-2;
                                        p2[ob_cur]-temp;
                                        goto PN2;
                                        break;
                                    case 4:
                                        temp.x=p2[ob_cur].get_x()+2;
                                        temp.y=p2[ob_cur].get_y()-2;
                                        p2[ob_cur]+temp;
                                        goto PN2;
                                        break;
                                    }
                                }
                                else
                                {
                                    schimba_jucator <dama_n> (p2[ob_cur]);
                                }
                            }
                            catch(afara_ecran &a)
                            {
                                n=a.what();
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                            catch(este_piesa &e)
                            {
                                n=e.what();
                                deselecteaza <dama_n> (p2[ob_cur]);
                                schimba_culoare();
                            }
                        else
                        {

                            deselecteaza <dama_n> (p2[ob_cur]);
                        }
                    }
                }
            }
            for(int i=0; i<8; i++)
                if(p1[i].get_x()==7&&p1[i].tip()==0)
                {
                    p1[i].incoroneaza();
                }
            for(int i=0; i<8; i++)
                if(p2[i].get_x()==0&&p2[i].tip()==0)
                {
                    p2[i].incoroneaza();
                }
            if(victorie <dama_a> (p1))
            {
                v=1;
                n="Negru a castigat";
                break;
            }
            if(victorie <dama_n> (p2))
            {
                v=1;
                n="Alb a castigat";
                break;
            }
        }
        sf::Text text,newgame,loadgame,savegame;
        sf::Font font;
        if (!font.loadFromFile("calibri.ttf"))
        {
            // error...
        }
        text.setFont(font);
        text.setCharacterSize(24); // in pixels, not points!
        text.setString(n);
        text.setPosition(675,470);
        if(culoare==0)
            text.setColor(sf::Color::White);
        else
            text.setColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        fereastra_main.draw(text);
        text.setColor(sf::Color::White);
        if(v==0)
            if(jucator_cur==1)
                text.setString("Jucator curent: Alb");
            else
                text.setString("Jucator curent: Negru");
        else
            text.setString("");
        text.setPosition(650,200);
        fereastra_main.draw(text);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setString("Joc Nou");
        text.setPosition(600,0);
        fereastra_main.draw(text);
        text.setString("Salveaza Joc");
        text.setPosition(696,0);
        fereastra_main.draw(text);
        text.setString("Incarca Joc");
        text.setPosition(840,0);
        fereastra_main.draw(text);
        text.setString("Info Autor");
        text.setPosition(725,35);
        fereastra_main.draw(text);

        fereastra_main.display(); // end the current frame
    }
    return 0;
}



