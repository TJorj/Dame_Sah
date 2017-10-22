#include <SFML/Graphics.hpp>
#include <dama_a.h>
#include <dama_n.h>
#include<iostream>
#include<fstream>
#include<string>
#include<globala.h>
#include<chrono>
using namespace std;
int determina_locatie(sf::Vector2i localPosition)
{
    if(localPosition.x>=600&&localPosition.y>=0&&localPosition.x<=685&&localPosition.y<=30)
        return 1;
    if(localPosition.x>=696&&localPosition.y>=0&&localPosition.x<=827&&localPosition.y<=30)
        return 2;
    if(localPosition.x>=840&&localPosition.y>=0&&localPosition.x<=960&&localPosition.y<=30)
        return 3;
    if(localPosition.x>=725&&localPosition.y>=45&&localPosition.x<=835&&localPosition.y<=60)
        return 4;
}
int posibilitati_dreapta_jos(piesa &a1,piesa *t2,piesa *t1)
{

    if(a1.get_x()==6)
        return 0;
    if(a1.get_y()==6)
        return 0;
    for(int i=0; i<8; i++)
        if(t2[i].get_x()==a1.get_x()+1&&t2[i].get_y()==a1.get_y()+1)    ///verifica existenta unei piese inamice

        {
            for(int j=0; j<8; j++)
                if(t2[j].get_x()==a1.get_x()+2&&t2[j].get_y()==a1.get_y()+2) ///verifica prezenta unei piese inamice dupa piesa din dreapta

                    return 0;
            for(int j=0; j<8; j++)
                if(t1[j].get_x()==a1.get_x()+2&&t1[j].get_y()==a1.get_y()+2) ///verifica prezenta unei piese dupa piesa din dreapta

                    return 0;
            return 1;
        }
    return 0;

}
int posibilitati_dreapta_sus(piesa &a1,piesa *t2,piesa *t1)
{
    if(a1.get_x()==1)
        return 0;
    if(a1.get_y()==6)
        return 0;
    for(int i=0; i<8; i++)
        if(t2[i].get_x()==a1.get_x()-1&&t2[i].get_y()==a1.get_y()+1)

        {
            for(int j=0; j<8; j++)
                if(t2[j].get_x()==a1.get_x()-2&&t2[j].get_y()==a1.get_y()+2)

                    return 0;
            for(int j=0; j<8; j++)
                if(t1[j].get_x()==a1.get_x()-2&&t1[j].get_y()==a1.get_y()+2)

                    return 0;
            //cout<<"posibilitate dr invers";
            return 1;
        }
    return 0;

}
int posibilitati_stanga_jos(piesa &a1,piesa *t2,piesa *t1)
{
    if(a1.get_x()==6)
        return 0;
    if(a1.get_y()==1)
        return 0;
    for(int i=0; i<8; i++)
        if(t2[i].get_x()==a1.get_x()+1&&t2[i].get_y()==a1.get_y()-1)

        {
            for(int j=0; j<8; j++)
                if(t2[j].get_x()==a1.get_x()+2&&t2[j].get_y()==a1.get_y()-2)

                    return 0;
            for(int j=0; j<8; j++)
                if(t1[j].get_x()==a1.get_x()+2&&t1[j].get_y()==a1.get_y()-2)

                    return 0;
            return 1;
        }
    return 0;
}
int posibilitati_stanga_sus(piesa &a1,piesa *t2,piesa *t1)
{
    if(a1.get_x()==6)
        return 0;
    if(a1.get_y()==1)
        return 0;
    for(int i=0; i<8; i++)
        if(t2[i].get_x()==a1.get_x()-1&&t2[i].get_y()==a1.get_y()-1)

        {
            for(int j=0; j<8; j++)
                if(t2[j].get_x()==a1.get_x()-2&&t2[j].get_y()==a1.get_y()-2)

                    return 0;
            for(int j=0; j<8; j++)
                if(t1[j].get_x()==a1.get_x()-2&&t1[j].get_y()==a1.get_y()-2)

                    return 0;
            return 1;
        }
    return 0;
}


int continua_miscare()
{
    int err=0;
    static int c=0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow fereastra_main(sf::VideoMode(700, 350), "Confirma Continuare", sf::Style::Titlebar | sf::Style::Close, settings);  // create the window
    fereastra_main.setVerticalSyncEnabled(true);
    fereastra_main.setPosition(sf::Vector2i(1100,450));
    while (fereastra_main.isOpen())     // run the program as long as the window is open
    {
        fereastra_main.clear(sf::Color::Black);  // clear the window with black color
        sf::Text generic, data;
        sf::Font font;
        if (!font.loadFromFile("calibri.ttf"))
        {
            // error...
        }
        data.setFont(font);
        data.setCharacterSize(24); // in pixels, not points!
        data.setColor(sf::Color::White);
        data.setStyle(sf::Text::Bold);
        generic.setFont(font);
        generic.setCharacterSize(24); // in pixels, not points!
        data.setPosition(350,325);
        data.setString("Nu se poate muta in directia aia");
        generic.setColor(sf::Color::White);
        generic.setStyle(sf::Text::Bold);
        generic.setPosition(225,0);
        generic.setString("Doriti sa continuati mutarea?");
        fereastra_main.draw(generic);
        generic.setPosition(250,100);
        generic.setString("Da, dreapta sus");
        fereastra_main.draw(generic);
        generic.setPosition(250,150);
        generic.setString("Da, dreapta jos");
        fereastra_main.draw(generic);
        generic.setPosition(250,200);
        generic.setString("Da, stanga sus");
        fereastra_main.draw(generic);
        generic.setPosition(250,250);
        generic.setString("Da, stanga jos");
        fereastra_main.draw(generic);
        generic.setPosition(250,300);
        generic.setString("Nu");
        fereastra_main.draw(generic);

        sf::Event event;
        while (fereastra_main.pollEvent(event))// check all the window's events that were triggered since the last iteration of the loop
        {
            if (event.type == sf::Event::Closed) // "close requested" event: we close the window
                fereastra_main.close();
            if (event.type==sf::Event::MouseButtonReleased&&event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i temp=sf::Mouse::getPosition(fereastra_main);
                //cout<<temp.x<<" "<<temp.y<<endl;
                if(jucator_cur==1)
                {

                    if(temp.x>250&&temp.x<420&&temp.y>100&&temp.y<125)
                        if(posibilitati_dreapta_sus(p1[ob_cur],p2,p1))
                        {
                            return 1;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                            if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                    if(temp.x>250&&temp.x<420&&temp.y>150&&temp.y<175)
                        if(posibilitati_dreapta_jos(p1[ob_cur],p2,p1))
                        {
                            return 2;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                     if(temp.x>250&&temp.x<420&&temp.y>200&&temp.y<225)
                        if(posibilitati_stanga_sus(p1[ob_cur],p2,p1))
                        {
                            return 3;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                     if(temp.x>250&&temp.x<420&&temp.y>250&&temp.y<275)
                        if(posibilitati_stanga_jos(p1[ob_cur],p2,p1))
                        {
                            return 4;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                    if(temp.x>250&&temp.x<280&&temp.y>310&&temp.y<330)
                    {
                        return 0;
                        fereastra_main.close();
                    }
                }
                else
                {

                    if(temp.x>250&&temp.x<420&&temp.y>100&&temp.y<125)
                        if(posibilitati_dreapta_sus(p2[ob_cur],p1,p2))
                        {
                            return 1;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                    if(temp.x>250&&temp.x<420&&temp.y>150&&temp.y<175)
                        if(posibilitati_dreapta_jos(p2[ob_cur],p1,p2))
                        {
                            return 2;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                     if(temp.x>250&&temp.x<420&&temp.y>200&&temp.y<225)
                        if(posibilitati_stanga_sus(p2[ob_cur],p1,p2))
                        {
                            return 3;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                     if(temp.x>250&&temp.x<420&&temp.y>250&&temp.y<275)
                        if(posibilitati_stanga_jos(p2[ob_cur],p1,p2))
                        {
                            return 4;
                            fereastra_main.close();
                        }
                        else
                        {

                            err=1;
                              if(c==0)
                                c=1;
                            else
                                c=0;

                        }
                    if(temp.x>250&&temp.x<280&&temp.y>310&&temp.y<330)
                    {
                        return 0;
                        fereastra_main.close();
                    }
                }
            }

        }
        if(err)
            if(c==1)
                {
                    data.setColor(sf::Color::Red);
                    fereastra_main.draw(data);
                }
            else
            {
                    data.setColor(sf::Color::White);
                    fereastra_main.draw(data);
            }
        fereastra_main.display();
    }
}
int victorie_a()
{

    for(int i=0; i<8; i++)
        if(p2[i].stare()==1)
            return 0;
    return 1;
}
int victorie_n()
{

    for(int i=0; i<8; i++)
        if(p1[i].stare()==1)
            return 0;
    return 1;
}
void initiazare_piese()
{
    int nr_a=0,nr_n=0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            if(i==0&&j%2==0)
            {
                p1[nr_a].coord(i,j);
                p1[nr_a].pozitie(tb.get_c_s(i,j));
                p1[nr_a].pune_in();
                nr_a++;
            }
            if(i==1&&j%2==1)
            {
                p1[nr_a].coord(i,j);
                p1[nr_a].pozitie(tb.get_c_s(i,j));
                p1[nr_a].pune_in();
                nr_a++;
            }
            if(i==6&&j%2==0)
            {
                p2[nr_n].coord(i,j);

                p2[nr_n].pozitie(tb.get_c_s(i,j));
                p2[nr_n].pune_in();

                nr_n++;
            }
            if(i==7&&j%2==1)
            {
                p2[nr_n].coord(i,j);

                p2[nr_n].pozitie(tb.get_c_s(i,j));
                p2[nr_n].pune_in();

                nr_n++;
            }
        }
}
void joc_nou()
{
    initiazare_piese();
    for(int i=0; i<8; i++)

    {

        if(p1[i].tip()==1)
            p1[i].decoroneaza();
        p1[i].highlight_off();
    }
    for(int i=0; i<8; i++)
    {
        if(p2[i].tip()==1)
            p2[i].decoroneaza();
        p2[i].highlight_off();
    }
    in_mutare=0;
    jucator_cur=1;
    n="";
    v=0;

}
void save_game()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow fereastra_main(sf::VideoMode(500, 500), "Salveaza Jocul", sf::Style::Titlebar | sf::Style::Close, settings);  // create the window
    fereastra_main.setVerticalSyncEnabled(true);
    while (fereastra_main.isOpen())     // run the program as long as the window is open
    {
        fereastra_main.clear(sf::Color::Black);  // clear the window with black color
        sf::Event event;
        while (fereastra_main.pollEvent(event))// check all the window's events that were triggered since the last iteration of the loop
        {
            if (event.type == sf::Event::Closed) // "close requested" event: we close the window
                fereastra_main.close();
            if (event.type==sf::Event::MouseButtonReleased&&event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i localPosition=sf::Mouse::getPosition(fereastra_main);
//                cout<<localPosition.x<<" "<<localPosition.y;
                string slot;
                char *dt;
                if(localPosition.y>=0&&localPosition.x>=0&&localPosition.y<=100&&localPosition.x<=500)
                {
                    slot="sav1.sav";
                    time_t now = time(0);
                    dt = ctime(&now);
                }

                if(localPosition.y>=101&&localPosition.x>=0&&localPosition.y<=200&&localPosition.x<=500)
                {
                    slot="sav2.sav";
                    time_t now = time(0);
                    dt = ctime(&now);
                }
                if(localPosition.y>=201&&localPosition.x>=0&&localPosition.y<=300&&localPosition.x<=500)
                {
                    slot="sav3.sav";
                    time_t now = time(0);
                    dt = ctime(&now);
                }
                if(localPosition.y>=301&&localPosition.x>=0&&localPosition.y<=400&&localPosition.x<=500)
                {
                    slot="sav4.sav";
                    time_t now = time(0);
                    dt = ctime(&now);
                }
                if(localPosition.y>=401&&localPosition.x>=0&&localPosition.y<=500&&localPosition.x<=500)
                {
                    slot="sav5.sav";
                    time_t now = time(0);
                    dt = ctime(&now);
                }
                ofstream f;
                f.open(slot,ios::out);
                f<<dt;
                for(int i=0; i<8; i++)
                {
                    f<<p1[i].stare()<<" "<<p1[i].tip()<<endl;
                    f<<p1[i].get_coord();
                    f<<p1[i].get_c_spatiu();
                    f<<endl;
                }
                f<<endl;
                for(int i=0; i<8; i++)
                {
                    f<<p2[i].stare()<<" "<<p2[i].tip()<<endl;
                    f<<p2[i].get_coord();
                    f<<p2[i].get_c_spatiu();
                    f<<endl;
                }
                f<<endl;
                f<<jucator_cur<<" "<<in_mutare<<" "<<v;
                f.close();
            }
        }
        sf::RectangleShape slot_sav(sf::Vector2f(500,100));
        for(int i=0; i<5; i++)
        {
            slot_sav.setPosition(0,100*i);
            if(i%2==0)
                slot_sav.setFillColor(sf::Color(255,255,255));
            else
                slot_sav.setFillColor(sf::Color(0,0,0));
            fereastra_main.draw(slot_sav);
        }
        sf::Text data, generic;
        sf::Font font;
        if (!font.loadFromFile("calibri.ttf"))
        {
            // error...
        }
        generic.setFont(font);
        generic.setCharacterSize(24); // in pixels, not points!
        generic.setColor(sf::Color::Red);
        generic.setStyle(sf::Text::Bold);
        generic.setString("Salvat la ");
        data.setFont(font);
        data.setCharacterSize(24); // in pixels, not points!
        data.setColor(sf::Color::Red);
        data.setStyle(sf::Text::Bold | sf::Text::Underlined);
        ifstream s1;
        string line;
        s1.open("sav1.sav");
        if(s1!=NULL)
            getline(s1,line);
        else
            line="";
        s1.close();
        generic.setPosition(60,30);
        data.setPosition(160,30);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s2;
        s2.open("sav2.sav");
        if(s2!=NULL)
            getline(s2,line);
        else
            line="";
        s2.close();
        generic.setPosition(60,130);
        data.setPosition(160,130);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s3;
        s3.open("sav3.sav");
        if(s3!=NULL)
            getline(s3,line);
        else
            line="";
        s3.close();
        generic.setPosition(60,230);
        data.setPosition(160,230);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s4;
        s4.open("sav4.sav");
        if(s4!=NULL)
            getline(s4,line);
        else
            line="";
        s4.close();
        generic.setPosition(60,330);
        data.setPosition(160,330);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s5;
        s5.open("sav5.sav");
        if(s5!=NULL)
            getline(s5,line);
        else
            line="";
        s5.close();
        generic.setPosition(60,430);
        data.setPosition(160,430);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        fereastra_main.display(); // end the current frame
    }
}
void load_game()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow fereastra_main(sf::VideoMode(500, 500), "Incarca Jocul", sf::Style::Titlebar | sf::Style::Close, settings);  // create the window
    fereastra_main.setVerticalSyncEnabled(true);
    while (fereastra_main.isOpen())     // run the program as long as the window is open
    {
        fereastra_main.clear(sf::Color::Black);  // clear the window with black color
        sf::RectangleShape slot_sav(sf::Vector2f(500,100));
        for(int i=0; i<5; i++)
        {
            slot_sav.setPosition(0,100*i);
            if(i%2==0)
                slot_sav.setFillColor(sf::Color(255,255,255));
            else
                slot_sav.setFillColor(sf::Color(0,0,0));
            fereastra_main.draw(slot_sav);
        }
        sf::Text data, generic;
        sf::Font font;
        if (!font.loadFromFile("calibri.ttf"))
        {
            // error...
        }
        generic.setFont(font);
        generic.setCharacterSize(24); // in pixels, not points!
        generic.setColor(sf::Color::Red);
        generic.setStyle(sf::Text::Bold);
        generic.setString("Salvat la ");
        data.setFont(font);
        data.setCharacterSize(24); // in pixels, not points!
        data.setColor(sf::Color::Red);
        data.setStyle(sf::Text::Bold | sf::Text::Underlined);
        ifstream s1;
        string line;
        s1.open("sav1.sav");
        if(s1!=NULL)
            getline(s1,line);
        else
            line="";
        s1.close();
        generic.setPosition(60,30);
        data.setPosition(160,30);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s2;
        s2.open("sav2.sav");
        if(s2!=NULL)
            getline(s2,line);
        else
            line="";
        s2.close();
        generic.setPosition(60,130);
        data.setPosition(160,130);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s3;
        s3.open("sav3.sav");
        if(s3!=NULL)
            getline(s3,line);
        else
            line="";
        s3.close();
        generic.setPosition(60,230);
        data.setPosition(160,230);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s4;
        s4.open("sav4.sav");
        if(s4!=NULL)
            getline(s4,line);
        else
            line="";
        s4.close();
        generic.setPosition(60,330);
        data.setPosition(160,330);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        ifstream s5;
        s5.open("sav5.sav");
        if(s5!=NULL)
            getline(s5,line);
        else
            line="";
        s5.close();
        generic.setPosition(60,430);
        data.setPosition(160,430);
        data.setString(line);
        fereastra_main.draw(generic);
        fereastra_main.draw(data);
        sf::Event event;
        while (fereastra_main.pollEvent(event))// check all the window's events that were triggered since the last iteration of the loop
        {

            string slot="";
            int a;
            if (event.type == sf::Event::Closed) // "close requested" event: we close the window
                fereastra_main.close();
            if (event.type==sf::Event::MouseButtonReleased&&event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i localPosition=sf::Mouse::getPosition(fereastra_main);
//                cout<<localPosition.x<<" "<<localPosition.y;
                if(localPosition.y>=0&&localPosition.x>=0&&localPosition.y<=100&&localPosition.x<=500)
                    slot="sav1.sav";
                if(localPosition.y>=101&&localPosition.x>=0&&localPosition.y<=200&&localPosition.x<=500)
                    slot="sav2.sav";
                if(localPosition.y>=201&&localPosition.x>=0&&localPosition.y<=300&&localPosition.x<=500)
                    slot="sav3.sav";
                if(localPosition.y>=301&&localPosition.x>=0&&localPosition.y<=400&&localPosition.x<=500)
                    slot="sav4.sav";
                if(localPosition.y>=401&&localPosition.x>=0&&localPosition.y<=500&&localPosition.x<=500)
                    slot="sav5.sav";
                ifstream f;
                f.open(slot,ios::in);
                if(!f)
                {

                }
                else
                {

                    getline(f,line);
//                    cout<<line<<endl;
                    int s,t,x,y;
                    c_spatiu c_s;
                    for(int i=0; i<8; i++)

                    {
                        f>>s>>t>>x>>y>>c_s.x_start>>c_s.x_end>>c_s.y_start>>c_s.y_end;
//                        cout<<s<<endl;
//                        cout<<x<<" "<<y<<endl;
                        if(s==1)
                        {
                            p1[i].pune_in();
                            p1[i].coord(x,y);
                            p1[i].pozitie(c_s);
                            if(t==1)
                                p1[i].incoroneaza();
                            else
                                p1[i].decoroneaza();
                        }
                        else
                            p1[i].pune_out();

                    }

                    for(int i=0; i<8; i++)
                    {
                        f>>s>>t>>x>>y>>c_s.x_start>>c_s.x_end>>c_s.y_start>>c_s.y_end;
                        if(s==1)
                        {
                            p2[i].pune_in();
                            p2[i].coord(x,y);
                            p2[i].pozitie(c_s);
                            if(t==1)
                                p2[i].incoroneaza();
                            else
                                p2[i].decoroneaza();
                        }
                        else
                            p2[i].pune_out();

                    }
                    f>>jucator_cur>>in_mutare>>v;
                }
                f.close();
            }
        }
        fereastra_main.display(); // end the current frame
    }
}
int ilegalitate_generala(piesa *p, coordonate& mat_poz)
{
    if(mat_poz.x==-1||p->get_y()==mat_poz.y||p->get_x()==mat_poz.x)
        return 1;
    if(jucator_cur==1)
        if(p->get_x_2()<mat_poz.x||p->get_x()>mat_poz.x)
            return 1;
    if(jucator_cur==2)
        if(p->get_x_2()>mat_poz.x||p->get_x()<mat_poz.x)
            return 1;
    return 0;
}
int mutare_1_dreapta(piesa *p, coordonate& mat_poz)
{

    if(p->get_x_1()==mat_poz.x&&p->get_y()+1==mat_poz.y)
        return 1;
    return 0;
}
int mutare_1_stanga(piesa *p, coordonate& mat_poz)
{

    if(p->get_x_1()==mat_poz.x&&p->get_y()-1==mat_poz.y)
        return 1;
    return 0;
}
int mutare_2_dreapta(piesa *p, coordonate& mat_poz)
{

    if(p->get_x_2()==mat_poz.x&&p->get_y()+2==mat_poz.y)
        return 1;
    return 0;
}
int mutare_2_stanga(piesa *p, coordonate& mat_poz)
{

    if(p->get_x_2()==mat_poz.x&&p->get_y()-2==mat_poz.y)
        return 1;
    return 0;
}
void schimba_culoare()
{
    if(culoare==1)
        culoare=0;
    else
        culoare=1;
}
