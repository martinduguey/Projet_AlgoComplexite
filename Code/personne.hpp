//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#ifndef _PERSONNE_HPP_
#define _PERSONNE_HPP_

#include <string>
#include "liste.hpp"

/**
 * @brief Cette classe permet de définir une personne.
 * 
 * Une personne est composé d'un sexe, d'un âge et d'un identifiant. Elle est aussi reliée à 3 voisins et la relation entre 
 * une personne et son voisin est caractérisée par une relation: double compris entre 0 et 1, 1 les deux personnes sont des proches 
 * 0 elles ne se fréquentent pas.
 * 
*/

class personne {

    friend class population;

    public :

        ///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////
        /**
         * @brief Constructeur par défaut
         * 
         * Attribue aléatoirement un age, un sexe et un identifiant
         * 
         */
        personne() = default;

        /**
         * @brief Constructeur 
         * 
         * @param[in] id (chaîne de caractère)
         */
        personne(unsigned int Id); 

        /**
         * @brief Destructeur par défaut
         * 
         */
        ~personne() = default;

        ///////////////////////           METHODES          ///////////////////////
        /**
         * @brief Permet d'obtenir l'age d'une personne
         * 
         * @return age
         */
        int get_age();

        /**
         * @brief Permet d'obtenir le sexe d'une personne
         * 
         * @return sexe
         */
        std::string get_sexe();

        /**
         * @brief Permet d'obtenir l'identifiant d'une personne
         * 
         * @return sexe
         */
        unsigned int get_id();

        /**
         * @brief Permet d'obtenir l'identifiant d'une personne
         * 
         * @return nb de contact
         */
        int get_nb_contacts();

        /**
         * @brief Permet d'ajouter un contact
         * 
         * @param[in] id de la personne qu'on veut définir comme contact
         */
        void ajout_contact(unsigned int id);

        /**
         * @brief Permet d'obtenir la liste des contacts
         * 
         * @return contacts
         */
        liste<unsigned int> get_contacts();

        /**
         * @brief Permet d'obtenir la relation1
         * 
         * @return relation1
         */
        double get_r1();

        /**
         * @brief Permet d'obtenir la relation2
         * 
         * @return relation2
         */
        double get_r2();

        /**
         * @brief Permet d'obtenir la relation3
         * 
         * @return relation3
         */
        double get_r3();

        /**
         * @brief Permet d'obtenir la relation4
         * 
         * @return relation4
         */
        double get_r4();

        ///////////////////////          OPERATEURS         ///////////////////////
        personne operator=(const personne &);

    private : 
        /** Âge **/
        int age;

        /** Sexe : feminin ou masculin **/
        std::string sexe;

        /** Identifiant **/
        unsigned int id;

        /** Relation avec le vosin 1 **/
        double relation1;

        /** Relation avec le vosin 2 **/
        double relation2;

        /** Relation avec le vosin 3 **/
        double relation3;

        /** Relation avec le vosin 3 **/
        double relation4;

        /** Liste de contact **/
        liste<unsigned int> contacts;

};




#endif