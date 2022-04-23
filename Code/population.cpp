//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include "population.hpp"
#include "RND.hpp"

///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////

population::population(){

    //Données
    N     = 100000;
    int nb_l_grille = 1000;
    la_population.reserve(N);
    etats.reserve(N);
    Index.reserve(N);
    Ligne.reserve(4*N); //Chaque personne a au maximum 4 voisins
    Valeur.reserve(4*N); //Chaque personne a au maximum 4 voisins

    //Infectés au départ
    int infecte1 = 1;
    int infecte2 = RND(2,N);
    infectes.ajout(infecte1);
    infectes.ajout(infecte2);

    //Génération de la population
    for(int i = 1; i <= N; i++){
        la_population.push_back(personne(i));

        if ((i==infecte1) || (i==infecte2)){
            etats.push_back(1); //On considère l'entier 1 pour le statut d'infecté
        }

        else{
            etats.push_back(0);
        }
    }

    //Génération des voisins
    unsigned int compteur = 0; // Utile pour la gestion de l'index (méthode forward star)
    

    for(int i = 1; i<(N-nb_l_grille)+1; i++){

        personne P = la_population[i-1];
        
        Index.push_back(compteur);


        //Cas première et dernière ligne exclus
        if((i%nb_l_grille >1)){

            if(i<nb_l_grille){
                //3 vosins
                //Voisin du haut
                P.ajout_contact(i+1);
                Ligne.push_back(i+1);
                Valeur.push_back(P.relation1);

                //Voisin de droite
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin du bas
                P.ajout_contact(i-1);
                Ligne.push_back(i-1);
                Valeur.push_back(P.relation3);

                compteur += 3;
            }

            if(i>nb_l_grille){
                //4 voisins
                //Voisin du haut
                P.ajout_contact(i+1);
                Ligne.push_back(i+1);
                Valeur.push_back(P.relation1);

                //Voisin de droite
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin du bas
                P.ajout_contact(i-1);
                Ligne.push_back(i-1);
                Valeur.push_back(P.relation3);

                //Voisin de gauche
                P.ajout_contact(i-nb_l_grille);
                Ligne.push_back(i-nb_l_grille);
                Valeur.push_back(P.relation4);

                compteur += 4;
            }
        }

        //Cas première ligne (bas)
        else if((i%nb_l_grille ==1)){

            if(i<nb_l_grille){
                //Voisin du haut
                P.ajout_contact(i+1);
                Ligne.push_back(i+1);
                Valeur.push_back(P.relation1);

                //Voisin de droite 
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin du droite haut
                P.ajout_contact(i+nb_l_grille+1);
                Ligne.push_back(i+nb_l_grille+1);
                Valeur.push_back(P.relation3);

                compteur += 3;
            }

            else {
                //Voisin du haut
                P.ajout_contact(i+1);
                Ligne.push_back(i+1);
                Valeur.push_back(P.relation1);

                //Voisin de droite 
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin de gauche
                P.ajout_contact(i-nb_l_grille);
                Ligne.push_back(i-nb_l_grille);
                Valeur.push_back(P.relation3);

                compteur += 3;
            }
        }

        //Cas dernière ligne (haut)
        else if((i%nb_l_grille ==0)){
            
            if(i==nb_l_grille){
                //Voisin du bas
                P.ajout_contact(i-1);
                Ligne.push_back(i-1);
                Valeur.push_back(P.relation1);

                //Voisin de droite 
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin de droite bas
                P.ajout_contact(i+nb_l_grille-1);
                Ligne.push_back(i+nb_l_grille-1);
                Valeur.push_back(P.relation3);

                compteur += 3;
            }

            else {
                //Voisin du bas
                P.ajout_contact(i-1);
                Ligne.push_back(i-1);
                Valeur.push_back(P.relation1);

                //Voisin de droite 
                P.ajout_contact(i+nb_l_grille);
                Ligne.push_back(i+nb_l_grille);
                Valeur.push_back(P.relation2);

                //Voisin de gauche
                P.ajout_contact(i-nb_l_grille);
                Ligne.push_back(i-nb_l_grille);
                Valeur.push_back(P.relation3);

                compteur += 3;
            }
        }
        
        //MAJ
        la_population[i-1] = P;
    }


    //Voisin dernière colonne
    for(int i = (N-nb_l_grille)+1; i <= N; i++){

        personne P = la_population[i-1];
    
        Index[i-1] = compteur;

        if(i == (N-nb_l_grille)+1){
            //Voisin du haut
            P.ajout_contact(i+1);
            Ligne.push_back(i+1);
            Valeur.push_back(P.relation1);

            //Voisin de gauche
            P.ajout_contact(i-nb_l_grille);
            Ligne.push_back(i-nb_l_grille);
            Valeur.push_back(P.relation2);

            //Voisin de gauche haut
            P.ajout_contact(i-nb_l_grille+1);
            Ligne.push_back(i-nb_l_grille+1);
            Valeur.push_back(P.relation3);

        }

        if(i == N){
            //Voisin du bas
            P.ajout_contact(i-1);
            Ligne.push_back(i-1);
            Valeur.push_back(P.relation1);

            //Voisin de gauche
            P.ajout_contact(i-nb_l_grille);
            Ligne.push_back(i-nb_l_grille);
            Valeur.push_back(P.relation2);

            //Voisin de gauche bas
            P.ajout_contact(i-nb_l_grille-1);
            Ligne.push_back(i-nb_l_grille-1);
            Valeur.push_back(P.relation3);
        }

        else{
            //Voisin du bas
            P.ajout_contact(i-1);
            Ligne.push_back(i-1);
            Valeur.push_back(P.relation1);

            //Voisin de gauche
            P.ajout_contact(i-nb_l_grille);
            Ligne.push_back(i-nb_l_grille);
            Valeur.push_back(P.relation2);

            //Voisin du haut
            P.ajout_contact(i+1);
            Ligne.push_back(i+1);
            Valeur.push_back(P.relation3);
        }

        compteur += 3;
        //MAJ
        la_population[i-1] = P;
    }

}
  

///////////////////////           METHODES          ///////////////////////

unsigned int population::get_Taille(){
    return N;
}

personne population::get_personne(unsigned int i){
    return la_population[i-1];
}

void population::modif_personne(unsigned int i, personne & P){
    la_population[i] = P;
}

std::vector<unsigned int> population::get_Index(){
    return Index;
}

std::vector<unsigned int> population::get_Ligne(){
    return Ligne;
}

std::vector<unsigned int> population::get_Valeur(){
    return Valeur;
}

std::vector<personne> population::get_la_population(){
    return la_population;
}
 
std::vector<int> population::get_etats(){
    return etats;
}

liste<unsigned int> population::get_infectes(){
    return infectes;
}