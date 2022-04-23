//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#ifndef _POPULATION_HPP_
#define _POPULATION_HPP_

#include "personne.hpp"
#include "liste.hpp"
#include <vector>

/**
 * @brief Cette classe permet de définir une population de 10 000 000 d'individus.
 * 
 * Une population est composé d'un nombre de personnes et d'une liste chaînée dont les noeuds pointent 
 * vers les états des différentes personnes de la population. On représente notre population comme une grille que l'on 
 * peut visualiser de la façon suivante pour une population de 10 000 000 d'individus :
 * 
 *  1000 .  2000 .                   10000000 .
 *  999  .  1999 .                    9999999 .
 *  998  .  1998 .                    9999998 .
 *  997  .  1997 .                    9999997 .
 *   .        .                         .
 *   .        .         .   .   .       .
 *   .        .                         .
 *   3   .  1003 .                    9999003 .       
 *   2   .  1002 .                    9999002 .
 *   1   .  1001 .                    9999001 .
 * 
 * On la représente comme une grille de 1000 lignes et 10 000 colonnes. Cette visualisation sous forme de grille permet de
 * définir directement des voisins. Les points sur le bord, ont automatiquement 3 voisins. En revanche les points intérieurs 
 * ont 4 voisins potentiels. Il faudra en choisir 3 parmi les 4 (on laisse ce choix à la fonction RND).
 * 
*/

class population {

    public : 

        ///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////
        /** 
         * @brief Constructeur par défaut de la population
         * 
         */
        population();

        /** 
         * @brief Constructeur
         * 
         */
        population(unsigned int Taille);

        /**
         * @brief Destructeur par défaut
         * 
         */
        ~population() = default;

        ///////////////////////           METHODES          ///////////////////////
        /**
         * @brief Permet d'obtenir la taille de la population
         * 
         * @return N
         */
        unsigned int get_Taille();

        /**
         * @brief Permet d'obtenir une personne de la population
         * 
         * @return personne
         */
        personne get_personne(unsigned int i);

        /**
         * @brief Permet de modifier une personne
         * 
         * @param[in] i indice de la personne que l'on veut modifier dans la liste
         * @param[in] P personne par laquelle on veut la remplacer
         */
        void modif_personne(unsigned int i, personne & P);

        /**
         * @brief Permet d'obtenir la matrice d'adjacence stockée sous forme forward star
         * 
         * @return Index
         */
        std::vector<unsigned int> get_Index();

        /**
         * @brief Permet d'obtenir la matrice d'adjacence stockée sous forme forward star
         * 
         * @return Ligne
         */
        std::vector<unsigned int> get_Ligne();

        /**
         * @brief Permet d'obtenir la matrice d'adjacence stockée sous forme forward star
         * 
         * @return Valeur
         */
        std::vector<unsigned int> get_Valeur();

        /**
         * @brief Permet d'obtenir la population
         * 
         * @return la_population
         */
        std::vector<personne> get_la_population();

        /**
         * @brief Permet d'obtenir les états de la population
         * 
         * @return etats
         */
        std::vector<int> get_etats();

        /**
         * @brief Permet d'obtenir les infectés dans la population
         * 
         * @return infectes
         */
        liste<unsigned int> get_infectes();

        ///////////////////////          OPERATEURS         ///////////////////////
    private : 
        
        /** Nombre de personnes **/
        unsigned int N;

        /** Personnes de la population **/
        //liste<personne> la_population;
        std::vector<personne> la_population;

        /** Etats des différentes personnes **/
        std::vector<int> etats;

        /** Id des personnes initialement infectées **/
        liste<unsigned int> infectes;

        //Matrice ajdacence stockée sous forme forward star
        std::vector<unsigned int> Index;
        std::vector<unsigned int> Ligne;
        std::vector<unsigned int> Valeur;

};




#endif