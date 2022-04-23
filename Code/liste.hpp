//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#ifndef _LISTE_HPP_
#define _LISTE_HPP_

#include <string>
#include "noeud.hpp"

/**
 * @brief Cette classe permet de définir une liste chaînée.
 * 
 * 
*/

template <class T> class noeud;

template <class T> 
class liste{

    public:
        ///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////
        /**
         * @brief Constructeur par défaut 
         * 
         */
        liste();

        /**
         * @brief Constructeur de copie
         * 
         */
        liste(const liste &);

        /**
         * @brief Destructeur par défaut
         */
        ~liste() = default;

        ///////////////////////          METHODES         ///////////////////////
        /**
         * @brief Ajout d'un élément
         * 
         * 
         * @param[in] valeur à ajouter
         */
        int ajout(const T & valeur);

        /**
         * @brief Ajout d'un élément à la fin
         * 
         * 
         * @param[in] valeur à ajouter
         */
        int ajout_fin(const T & valeur);

        /**
         * @brief Permet d'accéder à un élément stocké à partir d'une position
         * 
         * @param[in] position ou se trouve la donnée recherchée
         * @param[in] donnee_recherchee (emplacement pour stocker la donnée que l'on recherche)
         */
        T get_element(int position) const;

        /**
         * @brief Permet d'accéder à un élément stocké à partir d'une position
         * 
         * @param[in] position ou se trouve la donnée à remplacer
         * @param[in] nouvelle_donnee (emplacement pour stocker la donnée que l'on recherche)
         */
        void modif_element(int position, T & nouvelle_donnee);

        /**
         * @brief Obtenir le nombre de noeuds dans la liste
         * 
         * @return nb_noeuds
         */
        int get_nb_noeuds();

        /**
         * @brief Obtenir l'élément stocké dans le premier noeud de la liste
         * 
         * @return element
         */
        T get_premier();

        void modif_pointeur_ajout(noeud<T> *Precedent, noeud<T> *Nouveau, noeud<T> *Suivant);

        ///////////////////////         OPERATEURS        ///////////////////////
        liste operator=(const liste &);

    private:
        /** Premier noeud **/
        noeud<T> *premier;

        /** Dernier noeud **/
        noeud<T> *dernier;

        /** Nombres de noeuds **/
        int nb_noeuds;
};
///////////////////////        IMPLEMENTATION       ///////////////////////
///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////

template <class T>
liste<T>::liste(){
    premier = nullptr;
    dernier = nullptr;
    nb_noeuds = 0;
}

template <class T>
liste<T>::liste(const liste<T> & depart)
{
    //Initialisation
    premier = nullptr;
    dernier = nullptr;
    nb_noeuds = 0;
 
    //Copie
    noeud<T> *lecteur = depart.premier;
    while (lecteur != nullptr)
    {
       ajout(lecteur->element);
       lecteur = lecteur->suivant;
    }
}

///////////////////////          METHODES         ///////////////////////

template <class T>
int liste<T>::ajout(const T & valeur){

    //Création nouveau noeud et allocation mémoire
    noeud<T> *nouveau = new noeud<T>(valeur);

    if (nouveau==nullptr){
        return EXIT_FAILURE;
    }

    modif_pointeur_ajout(nullptr, nouveau, premier);
    nb_noeuds += 1;
    
    return EXIT_SUCCESS;
}

template <class T>
int liste<T>::ajout_fin(const T & valeur){

    //Création nouveau noeud et allocation mémoire
    noeud<T> *nouveau = new noeud<T>(valeur);

    if (nouveau==nullptr){
        return EXIT_FAILURE;
    }
    
    modif_pointeur_ajout(dernier, nouveau, nullptr);
    ++nb_noeuds;
    return EXIT_SUCCESS;
}

template <class T>
T liste<T>::get_element(int position) const{

    noeud<T> *cible = premier;

    for (int i = 0; i < position; ++i){
        cible = cible->suivant;
    }
 
    return cible->element;
}

template <class T>
void liste<T>::modif_element(int position, T & nouvelle_donnee){

    noeud<T> *cible = premier;

    for (int i = 0; i < position; ++i){
        cible = cible->suivant;
    }
 
    cible->element = nouvelle_donnee;
}

template <class T>
int liste<T>::get_nb_noeuds(){
    return nb_noeuds;
}

template <class T>
T liste<T>::get_premier(){
    return premier->element;

}


template <class T>
void liste<T>::modif_pointeur_ajout(noeud<T> * Precedent, noeud<T> * Nouveau, noeud<T> * Suivant){

	// On lie le nouveau et son suivant.
	Nouveau->suivant = Suivant;

	// S'il y a un precedent, on le lie avec le nouveau.
	if (Precedent != nullptr)
		Precedent->suivant = Nouveau;

	// On ajuste la tete.
	if (Suivant == premier)
		premier = Nouveau;

	// On ajuste la queue.
	if (Precedent == dernier)
		dernier = Nouveau;

}


///////////////////////         OPERATEURS        ///////////////////////

template <class T>
liste<T> liste<T>::operator=(const liste<T> & depart){
    
    if (this != &depart){

        noeud<T> * lecteur = depart.premier;
        while (lecteur != nullptr){

            ajout_fin(lecteur->element);
            lecteur = lecteur->suivant;
        }
    }

    return *this;
}

#endif