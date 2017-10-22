#ifndef COORDONATE_H
#define COORDONATE_H
#include<iostream>
using namespace std;
/*! clasa coordonate matriceala*/
class coordonate
{
    public:

        int x; ///<  coordonata liniei
        int y; ///<  coordonata coloanei

        //!constructor
        coordonate();


        //!destructor
        virtual ~coordonate();

        //!returneaza daca ambele coordonate sunt mai mici decat cele din parametru
        /*!
        \param ob obiectul cu care se compara
        \return 1 adevarat
        \return 2 fals
        */
        int operator<(coordonate &ob);

        //!incremeanteaza ambele coordonate
        void operator++(int);

        //!verifica egalitatea
        /*!
        \return 1 adevarat
        \return 0 fals
        */
        int operator==(coordonate &ob2);

        //! operator redefinit pentru scrierea in fisier
        friend ostream& operator<<(ostream &c, coordonate &ob);
    protected:

    private:
};

#endif // COORDONATE_H
