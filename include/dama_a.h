#ifndef DAMA_A_H
#define DAMA_A_H

#include <piesa.h>

/*! clasa derivata dame albe*/

class dama_a : public piesa
{
    public:
        //!constructor
        dama_a();

        //! destructor
        virtual ~dama_a();

        //! returneaza linia in cazul unui avans de 1 patrat inainte
        int get_x_1();

         //! returneaza linia in cazul unui avans de 2 patrate inainte
        int get_x_2();

        //!muta piesa un patrat la dreapta
        void operator++(int);

        //!muta piesa un patrat la stanga
        void operator++();

        //!muta piesa la coordonatele matriceale din parametru, manancand toate piesele peste care sare, in directia jos
        /*!
        \param mat_poz coordonate matriceale
        */
        void operator+(coordonate& mat_poz );

        //!muta piesa la coordonatele matriceala din parametru, manancand toate piesele peste care sare, in directia sus
        /*!
        \param mat_poz coordonate matriceale
        */
        void operator-(coordonate& mat_poz);
    protected:

    private:
};

#endif // DAMA_A_H
