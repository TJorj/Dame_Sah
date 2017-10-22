#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>
using namespace std;
/*! clasa exceptie pentru existenta unei piese de acelasi tip la o locatie*/
class este_piesa : public exception
{
    public:
        virtual const char* what() const throw() /// returneaza un mesaj despre existenta unei piese
        {
            return "Acolo este o piesa";
        }

    protected:

    private:
};

/*! clasa exceptie pentru existenta unei piese inamic la o locatie*/
class piesa_inamic : public exception
{
    public:
        virtual const char* what() const throw() /// returneaza un mesaj despre existenta unei piese inamic
        {
            return "Acolo este o piesa inamica";
        }

    protected:

    private:
};

/*! clasa exceptie pentru mutari inafara tablei*/
class afara_ecran : public exception
{
    public:
        virtual const char* what() const throw() /// returneaza un mesaj despre mutare infara tablei
        {
            return "Mutarea ajunge inafara ecranului";
        }

    protected:

    private:
};

#endif // MYEXCEPTIONS_H
