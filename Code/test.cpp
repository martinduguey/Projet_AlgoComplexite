//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include <iostream>

#include <vector>
#include "population.hpp"
#include "RND.hpp"
#include "declaration_fct.hpp"
#include "types.hpp"
#include <chrono>

int main(){

    ///////////////////////// DONNES NUMERIQUES /////////////////////////
    double taux_mortalite = 0.1237; 
    double taux_gravite = 0.3;
    double taux_contagion = 0.51;
    int seuil_age = 64;

    /////////////////////////   INITIALISATION  /////////////////////////
    double t1 = clock();
    population Population_test;
    double t2 = clock();
    std::cout << "============ \n" << std::endl;
    std::cout << "La population a été créée en " << (t2-t1)/100000 << "\n" << std::endl;
    std::cout << "============ \n" << std::endl;

    Resultat_propagation R1;
    R1 = propagation_init(Population_test.get_la_population(), Population_test.get_etats(), Population_test.get_infectes());

    /////////////////////////     SIMULATION  /////////////////////////
    Resultat_propagation R;
    int J = 365;
    for(int i = 1; i <= J; i++){
        if(i==1){
            R = propagation(R1, taux_mortalite, taux_gravite, taux_contagion, seuil_age);
        }

        else{
            R = propagation(R, taux_mortalite, taux_gravite, taux_contagion, seuil_age);
        }
    } 
    double t3 = clock();

    std::cout << "Après 365 jours, il y a eu, sur une population de " << Population_test.get_Taille() << " personnes : \n" << std::endl;
    std::cout << R.nb_cas << " contaminations, \n"<< std::endl;
    std::cout << R.nb_cas_grave << " contaminations graves, \n"<< std::endl;
    std::cout << R.nb_morts << " décès, \n"<< std::endl;
    std::cout << "dont " <<R.nb_hommes_deces << " hommes, \n"<< std::endl;
    std::cout << "et " <<R.nb_femmes_deces << " femmes, \n"<< std::endl;
    std::cout << "L'âge moyen de décès est de : " <<R.moyenne_age_deces << " ans. \n"<< std::endl;

    std::cout << "Durée totale du programme : " << (t3-t1)/100000 << "\n" << std::endl;
     
    return EXIT_SUCCESS;
}