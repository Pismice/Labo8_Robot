/*
-----------------------------------------------------------------------------------
Nom du fichier  : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s)       : Jérémie Santoro
Date creation   : <jj.mm.aaaa>

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "Terrain.h"
#include "saisie.h"     // Librairie du 10.11.2021

using namespace std;

int main() {
   // Bornes des valeurs utilisateur
   unsigned const LARGEUR_MIN = 2;
   unsigned const LARGEUR_MAX = 1000;
   unsigned const HAUTEUR_MIN = 2;
   unsigned const HAUTEUR_MAX = 1000;
   unsigned const NBRE_OJBETS_MIN = 2;
   unsigned const NBRE_OJBETS_MAX = 25;

   // Récupération des valeurs utilisateur
   unsigned const LARGEUR = saisieDansIntervalle(LARGEUR_MIN, LARGEUR_MAX, "largeur"s);
   unsigned const HAUTEUR = saisieDansIntervalle(HAUTEUR_MIN, HAUTEUR_MAX, "hauteur"s);
   unsigned const NBRE_OBJETS = saisieDansIntervalle(NBRE_OJBETS_MIN , NBRE_OJBETS_MAX, "nbre objets"s);

   // TODO : BON ENDROIT ?
   srand((unsigned int)time(0));

   // Création du terrain
   Terrain t(HAUTEUR, LARGEUR);

   // Placer les robots
   t.deploiement(NBRE_OBJETS);

   // Jouer les tours
   t.demarrerJeu();

 return EXIT_SUCCESS;
}