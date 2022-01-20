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
   unsigned const LARGEUR_MIN = 10;
   unsigned const LARGEUR_MAX = 1000;
   unsigned const HAUTEUR_MIN = 10;
   unsigned const HAUTEUR_MAX = 1000;
   unsigned const NBRE_OJBETS_MIN = 2;
   unsigned const NBRE_OJBETS_MAX = 9;

   // Récupération des valeurs utilisateur
   unsigned const LARGEUR = saisieDansIntervalle(LARGEUR_MIN, LARGEUR_MAX, "largeur"s);
   unsigned const HAUTEUR = saisieDansIntervalle(HAUTEUR_MIN, HAUTEUR_MAX, "hauteur"s);
   unsigned const NBRE_OBJETS = saisieDansIntervalle(2, 9, "nbre objets"s);

   // Création du terrain
   Terrain t(HAUTEUR, LARGEUR);
   t.creerRobot(NBRE_OBJETS);

   cout << t.getRobot() << endl;

   t.idRobot();

   // Placer les robots
   // DIDIER

   // Jouer les tours
   // JEREMIE
   //t.demarrerJeu();

 return EXIT_SUCCESS;
}