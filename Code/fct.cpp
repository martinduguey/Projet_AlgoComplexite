//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include "declaration_fct.hpp"
#include "RND.hpp"
#include <list>
#include <vector>


/**
* @brief On définit ici toutes les fonctions utiles au programme
* 
*/


int gen_age(){

    int age = RND(1,100);
    //Tirage aléatoire entre 0 et 1
    /*int random = RND(0.,1.);

    if(random<=0.157){
        //Moins de 15 ans
        age = RND(0,14);
    }

    if((random>0.157) && (random<=0.510)){
        //15-29 ans
        age = RND(0,14)+15;
    }

    if((random>0.510) && (random<=0.717)){
        //30-44 ans
        age = RND(0,14)+30;
    }

    if((random>0.717) && (random<=0.856)){
        //45-59 ans
        age = RND(0,14)+45;
    }

    if((random>0.856) && (random<=0.949)){
        //60-74 ans
        age = RND(0,14)+60;
    }

    if(random>0.949){
        //75 ans et plus
        age = RND(0,25)+75;
    }*/

    return age;

}

res propagation_init(std::vector<personne> population, std::vector<int> etats, liste<unsigned int> infectes){
    
    //Initialisation
    res Rinit;
    Rinit.nb_morts = 0;
    Rinit.nb_cas = 0;
    Rinit.nb_cas_grave = 0;

    Rinit.moyenne_age_deces = 0;
    Rinit.nb_femmes_deces = 0;
    Rinit.nb_hommes_deces = 0;

    Rinit.population = population;
    Rinit.etats = etats;   
    
    for(int i = 0; i < infectes.get_nb_noeuds(); i++){
        Rinit.inf.push_back(infectes.get_element(i));
        Rinit.inf_j.push_back(1);
        Rinit.nb_cas += 1;
    }

    return Rinit;
};

res propagation(res R, double taux_mortalite, double taux_gravite, double taux_contagion, int seuil_age){
    //On récupère les données
    res Rs = R;

    //Infectés
    for(int i = 0; i < Rs.inf.size(); i++){

        personne P = Rs.population[Rs.inf[i]-1];
        
        if((Rs.etats[Rs.inf[i]-1] != -2) && (Rs.etats[Rs.inf[i]-1] != -1)){

            liste<unsigned int> P_contacts = P.get_contacts();
            ////////////////Transmission////////////////
            for(int j = 0; j < P.get_nb_contacts(); j++){

                personne C = Rs.population[P_contacts.get_element(j)-1];

                if(j==0){
                    if((P.get_r1() > taux_contagion) && (Rs.etats[C.get_id()-1]==0)){
                        Rs.etats[C.get_id()-1] = 1;
                        Rs.inf.push_back(C.get_id());
                        Rs.inf_j.push_back(1);
                        Rs.nb_cas += 1;
                    }
                }

                else if(j==1){
                    if((P.get_r2() > taux_contagion) && (Rs.etats[C.get_id()-1]==0)){
                        Rs.etats[C.get_id()-1] = 1;
                        Rs.inf.push_back(C.get_id());
                        Rs.inf_j.push_back(1);
                        Rs.nb_cas += 1;
                    }
                }

                else if(j==2){
                    if((P.get_r3() > taux_contagion) && (Rs.etats[C.get_id()-1]==0)){
                        Rs.etats[C.get_id()-1] = 1;
                        Rs.inf.push_back(C.get_id());
                        Rs.inf_j.push_back(1);
                        Rs.nb_cas += 1;
                    }
                }

                else if(j==3){
                    if((P.get_r4() > taux_contagion) && (Rs.etats[C.get_id()-1]==0)){
                        Rs.etats[C.get_id()-1] = 1;
                        Rs.inf.push_back(C.get_id());
                        Rs.inf_j.push_back(1);
                        Rs.nb_cas += 1;
                    }
                }
            }
            
            ////////////////Mise à jour////////////////
            if(R.inf_j[i]>5){

                if(P.get_age()> seuil_age){
                    if(RND(0.,1.)<=(2*taux_mortalite)){
                        Rs.morts.push_back(Rs.inf[i]);
                        Rs.etats[Rs.inf[i]-1] = -2; //Décès
                        Rs.nb_morts += 1;
                    }
                }

                else if(RND(0.,1.)<=taux_mortalite){
                    Rs.morts.push_back(Rs.inf[i]);
                    Rs.etats[Rs.inf[i]-1] = -2; //Décès
                    Rs.nb_morts += 1;
                }

                Rs.nb_cas_grave += 1;
            }

            else if((R.inf_j[i]<=5) && (RND(0.,1.)>=taux_gravite)){
                Rs.etats[Rs.inf[i]-1] = -1; //-1 correspond au statut rétabli puis immunisé
            }

            else{
                Rs.inf_j[i] += 1;
            }
            
        }
    }

    double moyenne_age = 0.0;
    int compteur_femme = 0;
    int compteur_homme = 0;

    for(int i = 0; i < Rs.morts.size(); i++){
        personne P = Rs.population[Rs.morts[i]-1];

        if(P.get_sexe() == "feminin"){
            compteur_femme += 1;
        }

        else{
            compteur_homme += 1;
        }

        moyenne_age += P.get_age();
    }

    Rs.moyenne_age_deces = (moyenne_age)/(Rs.nb_morts);
    Rs.nb_femmes_deces = compteur_femme;
    Rs.nb_hommes_deces = compteur_homme; 

    return Rs;
}