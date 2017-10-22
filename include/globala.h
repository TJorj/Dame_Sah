#ifndef GLOBALA_H_INCLUDED
#define GLOBALA_H_INCLUDED
#include "tabla.h"
#include "myexceptions.h"
/*! \file structcmd.h
    \brief A Documented file.

    \fn int determina_locatie(sf::Vector2i localPosition);
    \brief determina daca s-a dat click pe meniu
    \param localPosition coordonatele spatiale unde s-a dat click
    \return 1 joc nou
    \return 2 salveaza joc
    \return 3 incarca joc
    \return 4 info autor

    \fn void initiazare_piese();
    \brief initializeaza piesele pe tabla

    \fn void joc_nou();
    \brief creeaza un joc nou

    \fn void save_game();
    \brief salveaza jocul curent

    \fn void load_game();
    \brief incarca un joc precedent

    \fn int posibilitati_dreapta_jos(piesa &a1 ,piesa *t2 ,piesa *t1 );
    \brief verifica posibilitati de mutare in dreapta jos
    \param  a1 piesa pentru care se cauta posibilitati
    \param  t2 vectorul de piese oponente piesei careia i se cauta posibilitati
    \param  t1 vectorul de piese de acelasi tip ca si cea pentru care se cauta posibilitati
    \return 1 daca exista posibilitati
    \return 0 daca nu exista posibilitati

    \fn int posibilitati_dreapta_sus(piesa &a1 ,piesa *t2 ,piesa *t1 );
    \brief verifica posibilitati de mutare in dreapta sus
    \param a1 piesa pentru care se cauta posibilitati
    \param t2 vectorul de piese oponente piesei careia i se cauta posibilitati
    \param t1 vectorul de piese de acelasi tip ca si cea pentru care se cauta posibilitati
    \return 1 daca exista posibilitati
    \return 0 daca nu exista posibilitati

    \fn int posibilitati_stanga_jos(piesa &a1 ,piesa *t2 ,piesa *t1 );
    \brief verifica posibilitati de mutare in stanga jos
    \param a1 piesa pentru care se cauta posibilitati
    \param t2 vectorul de piese oponente piesei careia i se cauta posibilitati
    \param t1 vectorul de piese de acelasi tip ca si cea pentru care se cauta posibilitati
    \return 1 daca exista posibilitati
    \return 0 daca nu exista posibilitati

    \fn int posibilitati_stanga_sus(piesa &a1 ,piesa *t2 ,piesa *t1 );
    \brief verifica posibilitati de mutare in stanga sus
    \param a1 piesa pentru care se cauta posibilitati
    \param t2 vectorul de piese oponente piesei careia i se cauta posibilitati
    \param t1 vectorul de piese de acelasi tip ca si cea pentru care se cauta posibilitati
    \return 1 daca exista posibilitati
    \return 0 daca nu exista posibilitati

    \fn int continua_miscare();
    \brief deschide fereastra pentru confirmarea continuarii sau intreruperii mutarii in cazul salturilor multiple
    \return 1 daca miscarea se continua in dreapta sus
    \return 2 daca miscarea se continua in dreapta jos
    \return 3 daca miscarea se continua in stanga sus
    \return 4 daca miscarea se continua in stanga jos
    \return 0 daca miscarea nu se continua

    \fn int ilegalitate_generala(piesa *p , coordonate& mat_poz );
    \brief p verifica legalitatea generala a unei mutari
    \param mat_poz piesa selectata
    \param coordonatele matriceale la care s-a dat click
    \return 1 daca miscarea e ilegala
    \return 0 daca miscarea e legala


    \fn int mutare_1_dreapta(piesa *p , coordonate& mat_poz );
    \brief p verifica daca s-a incercat mutarea unei piese cu un patrat la dreapta
    \param mat_poz piesa selectata
    \param coordonatele matriceale la care s-a dat click
    \return 1 daca s-a mutat incercat mutarea pe aceasta directie
    \return 0 daca nu s-a incercat mutarea pe aceasta directie

    \fn int mutare_2_dreapta(piesa *p , coordonate& mat_poz );
    \brief p verifica daca s-a incercat mutarea unei piese cu doua patrate la dreapta
    \param mat_poz piesa selectata
    \param coordonatele matriceale la care s-a dat click
    \return 1 daca s-a mutat incercat mutarea pe aceasta directie
    \return 0 daca nu s-a incercat mutarea pe aceasta directie

    \fn int mutare_1_stanga(piesa *p , coordonate& mat_poz );
    \brief p verifica daca s-a incercat mutarea unei piese cu un patrat la stanga
    \param mat_poz piesa selectata
    \param coordonatele matriceale la care s-a dat click
    \return 1 daca s-a mutat incercat mutarea pe aceasta directie
    \return 0 daca nu s-a incercat mutarea pe aceasta directie

    \fn int mutare_2_stanga(piesa *p , coordonate& mat_poz );
    \brief p verifica daca s-a incercat mutarea unei piese cu doua patrate la stanga
    \param mat_poz piesa selectata
    \param coordonatele matriceale la care s-a dat click
    \return 1 daca s-a mutat incercat mutarea pe aceasta directie
    \return 0 daca nu s-a incercat mutarea pe aceasta directie

    \fn template <class T> int victorie(T *t )
    \brief verifica daca jucatorul de tipul piesei parametru a castigat
    \param t vectorul de piese oponent celui pentru care se cauta victoria
    \return 1 daca jucatorul de tipul piesei nu mai are nici o piesa in joc
    \return 0 daca jucatorul de tipul piesei inca mai are piese in joc

    \fn template <class T> int legalitate(T &p , coordonate& mat_poz )
    \brief verifica legalitatea pentru mutarea pieselor incoronate (obligatoriu pe aceeasi coloana)
    \param p piesa selectata
    \param mat_poz coordonatele matriceale la care s-a dat click
    \return 1 daca mutarea este legala
    \return 0 daca mutarea este ilegala

    \fn template <class T> void deselecteaza(T &p )
    \brief deselecteaza o piesa
    \param p piesa selectata

    \fn template <class T> void schimba_jucator(T &p )
    \brief schimba jucatorul
    \param p piesa selectata

    \fn void schimba_culoare();
    \brief schimba culoarea mesajului de eroare pentru usoara identificare a unui mesaj nou

    */
extern tabla tb; ///< obiectul tabla
extern este_piesa este; ///< obiect exceptie existenta piesa
extern piesa_inamic inamic; ///< obiect exceptie existenta piesa inamica
extern afara_ecran afara; ///< obiect exceptie mutare inafara tablei
extern dama_a p1[8]; ///< vector dame albe
extern dama_n p2[8]; ///< vector dame negre
extern int in_mutare; ///< variablia ce retine daca starea jocului este in timpul unei mutari
extern int ob_cur; ///< indicele vectorial al piesei care este selectata
extern int jucator_cur; ///< variabila ce retine jucatorul curent
extern int v; ///< variabila cu valoarea 1 daca un jucator a castigat
extern string n; ///< variabila utilizata pentru redarea textului meniului
extern int culoare; ///< variabila utilizata pentru schimbarea culorii mesajului de eroare
int determina_locatie(sf::Vector2i localPosition);
void initiazare_piese();
void joc_nou();
void save_game();
void load_game();
int posibilitati_dreapta_jos(piesa &a1 ,piesa *t2 ,piesa *t1 );
int posibilitati_dreapta_sus(piesa &a1 ,piesa *t2 ,piesa *t1 );
int posibilitati_stanga_jos(piesa &a1 ,piesa *t2 ,piesa *t1 );
int posibilitati_stanga_sus(piesa &a1 ,piesa *t2 ,piesa *t1 );
int continua_miscare();
int ilegalitate_generala(piesa *p , coordonate& mat_poz );
int mutare_1_dreapta(piesa *p , coordonate& mat_poz );
int mutare_1_stanga(piesa *p , coordonate& mat_poz );
int mutare_2_dreapta(piesa *p , coordonate& mat_poz );
int mutare_2_stanga(piesa *p , coordonate& mat_poz );
void schimba_culoare();
template <class T>
int victorie(T *t )
{

    for(int i=0; i<8; i++)
        if(t[i].stare()==1)
            return 0;
    return 1;
}
template <class T>
int legalitate(T &p , coordonate& mat_poz )
{

    if((p.get_coord().x-p.get_coord().y==mat_poz.x-mat_poz.y)||(p.get_coord().x+p.get_coord().y==mat_poz.x+mat_poz.y))
        return 1;
    return 0;
}
template <class T>
void deselecteaza(T &p )
{
    in_mutare=0;
    p.highlight_off();
}
template <class T>
void schimba_jucator(T &p )
{
    in_mutare=0;
    if(jucator_cur==1)
        jucator_cur=2;
    else
        jucator_cur=1;
    p.highlight_off();
}
#endif // GLOBALA_H_INCLUDED
