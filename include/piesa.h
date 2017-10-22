#ifndef PIESA_H
#define PIESA_H
#include<string>
#include<SFML/Graphics.hpp>
#include<coordonate.h>
#include<c_spatiu.h>
/*! clasa abstracta piesa */
using namespace std;

class piesa
{
    public:
        //!constructor
        piesa();

        //!destructor
        virtual ~piesa();

        //!desneaza piesa in fereastra parametru
        /*!
        \param window fereastra in care se deseneaza
        */
        virtual void deseneaza(sf::RenderWindow &window );

        //!seteaza coordonatele spatiale
        /*!
        \param coordonate spatiale
        */
        virtual void pozitie(c_spatiu& c);

        //!seteaza coordonatele matriceale
        /*!
        \param _x linia
        \param _y coloana
        */
        virtual void coord(int _x ,int _y);

        //!pune piesa in joc
        virtual void pune_in();

        //!scoate piesa din joc
        virtual void pune_out();

        //!returneaza starea piesei
        /*!
        \return 1 in joc
        \return 0 scoasa din joc
        */
        virtual int stare();

        //! returneaza linia pe care se afla piesa
        virtual int get_x();

        //!returneaza coloana pe care se afla piesa
        virtual int get_y();

        //!lumineaza piesa
        virtual void highlight_on();

        //! opreste luminarea piesei
        virtual void highlight_off();

        //! incoroneaza piesa
        virtual void incoroneaza();

        //!returneaza tipul piesei
        /*!
        \return 1 piesa incoronata
        \return 0 piesa normala
        */
        virtual int tip();

        //! returneaza coordonatele matriceale
        virtual coordonate& get_coord();

        //!returneaza coordonatele spatiale
        virtual c_spatiu& get_c_spatiu();

        //!decoroneaza o piesa
        virtual void decoroneaza();

        //!returneaza daca s-a dat click pe acea piesa
        /*!
        \param localPosition coordonate spatiale la care s-a dat click
        \return 1 daca pe piesa s-a dat click
        \return 0 daca pe piesa nu s-a dat click
        */
        virtual int is_clicked(sf::Vector2i localPosition );

        //!returneaza linia in cazul unui avans de 1 patrat pe directia de baza a piesei
        virtual int get_x_1() = 0;

        //!returneaza linia in cazul unui avans de 2 patrate pe directia de baza a piesei
        virtual int get_x_2() = 0;

    protected:

        string nume_textura; ///< numele texturii
        string nume_textura_baza; ///< numele texturii de baza (utilizata pentru revenire la textura initiala)
        string nume_highlight; ///< numele texturii pentru luminare
        string nume_textura_incoronat; ///< numele texturii piesa incoronata
        string nume_highlight_incoronat; ///< numele texturii pentru luminarea unei piese incoronate
        string nume_highlight_baza; ///< numele texturii pentru luminare de baza (utilizata pentru revenire la textura de luminare initiala)
        coordonate xy; ///< coordonate matriceale
        c_spatiu c_s; ///< coordonate spatiale
        int is_highlight=0; ///< variabila pentru luminare
        int in_joc; ///< variablia de stare
        int incoronat; ///< variabila pentru tipul piese

    private:
};

#endif // PIESA_H
