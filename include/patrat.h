#ifndef PATRAT_H
#define PATRAT_H
#include <SFML/Graphics.hpp>
#include<c_spatiu.h>
#include<coordonate.h>
/*! clasa patrat din care este formata tabla */
class patrat
{
    public:
        //! constructor
        patrat();

        //! destructor
       ~patrat();

        //!returneaza coordonatele spatiale
        c_spatiu& get_c_s();

        //!returneaza coordonata spatiala de pe axa X de unde incepe patratul
        int get_x_s();

        //!returneaza coordonata spatiala de pe axa X unde se sfarseste patratul
        int get_x_e();

        //!returneaza coorodnata spatiala de pe axa Y de unde incepe patratul
        int get_y_s();

        //!returneaza coordonata spatiala de pe axa Y de unde se sfarseste patratul
        int get_y_e();

        //!deseneaza patratul in fereastra din parametru
        void deseneaza(sf::RenderWindow &window /**< fereastra in care se deseneaza*/);

        //!intializeaza patratul cu coordonatele matriceale i j
        /*!
        \param i linia
        \param j coloana
        */
        void initializeaza(int i ,int j);
    protected:

    private:
        c_spatiu c_s; ///< coordonatele spatiale
        coordonate x_y; ///< coordonatele matriceale

};

#endif // PATRAT_H

