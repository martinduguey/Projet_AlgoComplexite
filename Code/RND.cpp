//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include "RND.hpp"

/** RND pour un int en entrée **/
int RND(int borne_inf, int borne_sup){
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_int_distribution<int> igenran(borne_inf, borne_sup);
    return (igenran(hgenerator));
}

/** RND pour un double en entrée **/
double RND(double borne_inf, double borne_sup){
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_real_distribution<double> genrand(borne_inf,borne_sup);
    return (genrand(hgenerator));
}
