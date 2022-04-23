//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <vector>
#include "personne.hpp"

struct Resultat_propagation {
    //Donnees épidémiques
    unsigned int nb_morts;
    unsigned int nb_cas;
    unsigned int nb_cas_grave;

    double moyenne_age_deces;
    int nb_femmes_deces;
    int nb_hommes_deces;

    //Transmission à jour pour étape suivante
    std::vector<personne> population;
    std::vector<int> etats;
    std::vector<unsigned int> inf;
    std::vector<unsigned int> morts;

    std::vector<int> inf_j;
} ;

#endif