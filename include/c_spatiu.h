#ifndef C_SPATIU_H
#define C_SPATIU_H
#include<iostream>
using namespace std;
/*! clasa coordonata spatiale*/
class c_spatiu
{
    public:

        int x_start;///< coordonata spatiala de inceput pe axa X
        int x_end; ///< coordonata spatiala de sfarsit pe axa X
        int y_start; ///< coordonata spatiala de inceput pe axa Y
        int y_end; ///< coordonata spatiala de sfarsit pe axa Y

        //!constructor
        c_spatiu();

        //!destructor
        virtual ~c_spatiu();

        //!constructor implicit
        /*!
        \param _x_s coordonata spatiala de inceput pe axa X
        \param _x_e coordonata spatiala de sfarsit pe axa X
        \param _y_s coordonata spatiala de inceput pe axa Y
        \param _y_e coordonata spatiala de sfarsit pe axa Y
        */
        c_spatiu(int _x_s ,int _x_e ,int _y_s ,int _y_e );

        //!seteaza coordonatele
        /*!
        \param _x_s coordonata spatiala de inceput pe axa X
        \param _x_e coordonata spatiala de sfarsit pe axa X
        \param _y_s coordonata spatiala de inceput pe axa Y
        \param _y_e coordonata spatiala de sfarsit pe axa Y
        */
        void set_c(int _x_s,int _x_e,int _y_s,int _y_e);

        //! operator redefinit pentru scrierea in fisier
        friend ostream& operator<<(ostream &c, c_spatiu &ob);
    protected:

    private:

};

#endif // C_SPATIU_H
