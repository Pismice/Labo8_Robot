/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Ce programme permet d'utiliser la classe Terrain
                  qui permet de créer un jeu de simulation de batailles de robots

Remarque(s)     : - Une fois le jeu terminé, l'utilisateur peut quitter le programme

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

   // Initialisation du srand
   srand((unsigned int)time(nullptr));

   // Création du terrain
   Terrain monTerrain((DataType(HAUTEUR)), DataType(LARGEUR));

   // Placer les robots
   monTerrain.deploiement(NBRE_OBJETS);

   // Jouer les tours
   monTerrain.demarrerJeu();

 return EXIT_SUCCESS;
}