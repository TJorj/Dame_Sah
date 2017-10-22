#ifndef TABLA_H
#define TABLA_H
#include<SFML/Graphics.hpp>
#include"patrat.h"
/*! clasa tabla */

class tabla
{
    public:
        //! constructor
        tabla();

        //! destructor
        virtual ~tabla();

        //! deseneaza tabla
        /*!
        \param window fereastra in care se deseneaza
        */
        void deseneaza(sf::RenderWindow &window );

        //! initializeaza fiecare patrat din matricea de patrate
        void initializeaza();

        //!returneaza coordonatele spatiale pentru pozitia i j in matricea de patrate
        /*!
        \param i linia
        \param j coloana
        */
        c_spatiu& get_c_s(int i , int j );

        //! returneaza coordonatele matriceale unde s-a dat click
        /*!
        \param localPosition coordonatele spatiale la care s-a dat click
        */
        coordonate coord_click(sf::Vector2i localPositon );
    protected:

    private:
         patrat t[8][8];///<matricea de patrate ce formeaza tabla
};

#endif // TABLA_H
