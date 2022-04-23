//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#ifndef _NOEUD_HPP_
#define _NOEUD_HPP_

/**
 * @brief Cette classe permet de définir un noeud dans une liste chaînée.
 * 
 * 
*/

template <class T> class liste;

template <class T> 
class noeud{

    friend class liste<T>;

    private :
        ///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////

        /** 
         * @brief Constructeur noeud 
         * 
         * @param[in] donnée que l'on veut stocker à l'adresse du noeud
        */
        noeud(const T & donnee);

        /** 
         * @brief Constructeur noeud 
         * 
         * @param[in] donnee que l'on veut stocker à l'adresse du noeud
         * @param[in] pointeur vers le noeud suivant
        */
        noeud(const T & donnee, noeud<T> *nouveau);

        /** Element du noeud **/
        T element;

        /** Noeud suivant **/
        noeud<T> *suivant;

};

///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////

template <class T>
noeud<T>::noeud(const T & donnee){
    element = donnee;
    suivant = nullptr;
}

template <class T>
noeud<T>::noeud(const T & donnee, noeud<T> *nouveau){
    element = donnee;
    suivant = nouveau;
}

#endif