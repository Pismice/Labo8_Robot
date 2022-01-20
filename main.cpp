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
   unsigned const NBRE_OJBETS_MAX = 12;

   // Récupération des valeurs utilisateur
   unsigned const LARGEUR = saisieDansIntervalle(LARGEUR_MIN, LARGEUR_MAX, "largeur"s);
   unsigned const HAUTEUR = saisieDansIntervalle(HAUTEUR_MIN, HAUTEUR_MAX, "hauteur"s);
   unsigned const NBRE_OBJETS = saisieDansIntervalle(2, 12, "nbre objets"s);

   // Création du terrain
   Terrain t(HAUTEUR, LARGEUR);

    srand((unsigned int)time(0));
   // Placer les robots
   t.deploiement(NBRE_OBJETS);

   for(Robot r : t.robots)
   {
      cout << "ID = " << r.getId() << endl;
      cout << "x = " << r.getPosition().getX() << endl;
      cout << "y = " << r.getPosition().getY() << endl;
      cout << endl;
   }

   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   // Jouer les tours
   //t.demarrerJeu();

 return EXIT_SUCCESS;
}