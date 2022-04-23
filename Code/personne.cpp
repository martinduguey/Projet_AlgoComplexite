//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include <string>

#include "personne.hpp"
#include "declaration_fct.hpp"
#include "RND.hpp"

///////////////////////  CONSTRUCTEURS/DESTRUCTEUR  ///////////////////////

personne::personne(unsigned int Id){
    using namespace std;

    /** Age **/
    age = gen_age();

    /** Sexe **/
    if(RND(0.,1.)<=0.5){
        sexe = "feminin";
    }

    else{
        sexe = "masculin";
    }

    /** Id **/
    id = Id;

    /** Relations **/
    relation1 = RND(0.,1.);
    relation2 = RND(0.,1.);
    relation3 = RND(0.,1.);
    relation4 = RND(0.,1.);

} 

///////////////////////           METHODES          ///////////////////////

int personne::get_age(){
    return age;
}

std::string personne::get_sexe(){
    return sexe;
}

unsigned int personne::get_id(){
    return id;
}

int personne::get_nb_contacts(){
    return contacts.get_nb_noeuds();
}

void personne::ajout_contact(unsigned int id){

    int c = contacts.get_nb_noeuds();

    if(c<=3){
        contacts.ajout(id);
    }
}

liste<unsigned int> personne::get_contacts(){
    return contacts;
}

double personne::get_r1(){
    return relation1;
}

double personne::get_r2(){
    return relation2;
}

double personne::get_r3(){
    return relation3;
}

double personne::get_r4(){
    return relation4;
}

///////////////////////          OPERATEURS         ///////////////////////

personne personne::operator=(const personne & depart){
    
    if (this != &depart){

        //Attributs de base
        this->age = depart.age;
        this->sexe = depart.sexe;
        this->id = depart.id;

        //Relations
        this->relation1 = depart.relation1;
        this->relation2 = depart.relation2;
        this->relation3 = depart.relation3;
        this->relation4 = depart.relation4;

        //Contact
        this->contacts = depart.contacts;
    }
    
    return *this;
}