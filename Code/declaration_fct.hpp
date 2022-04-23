//DUGUEY MARTIN - MACS2 - ALGO&COMPLEXITE
#include <iostream>
#include "personne.hpp"
#include "types.hpp"

using res = Resultat_propagation;

/**
* @brief On déclare dans ce fichier toutes les fonctions utiles au programme.
* 
*/

/**
 * @brief Cette fonction génère un age selon les données de la répartition des âges pour la métropole de Lille (~1 million d'habitants)
 * (Ressources)
 */
int gen_age();

/**
 * @brief Cette fonction qui prend en argument une liste de population, d'états et d'infectés permet d'initialiser la propagation
 */
res propagation_init(std::vector<personne> population, std::vector<int> etats, liste<unsigned int> infectes);

/**
 * @brief Cette fonction qui prend en argument une structure de résultats et des données liées à 
 * l'épidémie permet de simuler la propagation sur 1 journée(arbitraire).
 */
res propagation(res R, double taux_mortalite, double taux_gravite, double taux_contagion, int seuil_age);