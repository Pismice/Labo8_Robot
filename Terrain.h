/*
-----------------------------------------------------------------------------------
Nom du fichier  : Terrain.h
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Interface permettant de gèrer et simuler un terrain en 2D,
                  il peut via un opérateur de flux envoyer son affichage, générer
                  des robots, et gérer une partie de bataille de robots

Remarque(s)     : - Ne gère pas le cas ou le nombre de robots est supérieurs au nombre
                    de cases

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_TERRAIN_H
#define LABO8_ROBOT_TERRAIN_H

#include "Robot.h"
#include <vector>
#include <ostream>
#include <thread>
#include <chrono>
#include "Coordonnee.h"

typedef std::chrono::duration<unsigned long long> duration;

class Terrain{
   // Fonctions amies
   /**
    * Permet de surcharger l'opérateur de flux pour afficher le terrain et ses robots
    * @param lhs Flux de sortie
    * @param rhs Terrain à "sortir" (afficher)
    * @return Flux de sortie
    */
   friend std::ostream& operator<<(std::ostream& lhs, const Terrain& rhs);

   // Constantes statiques
   const static char PLAFOND = '^';
   const static char SOL = '_';
   const static char MUR = '|';
   const static char VIDE = ' ';

private:
   // Propriétés
   const Coordonnee pointMax;     // Correspond au point en bas à droite
   const Coordonnee pointMin;     // Correspond au point en haut à gauche
   const DataType valeurRebondissement = 2;  // Capacité de rebondissement des robots
   const unsigned nbreMsDelai = 1000;     // Délai entre chaque tour en seconde(s)

   std::vector<Robot> robots;    // Contient tous les robots du jeu

   duration delai = std::chrono::duration_cast<duration>(std::chrono::milliseconds (nbreMsDelai));

   // Méthodes
   /**
    * Permet de jouer un tour sur tous les robots
    */
   void jouerTour();

   /**
    * Permet de savoir si un ou plusieurs robots sont présents sur la ligne
   // et retourne les robots présents
    * @param robotsSurMaLigne Liste de robots
    * @param noLigne Ligne à vérifier
    * @return Si un ou plusieurs robots sont présents
    */
   bool siRobotPresentSurLigne(std::vector<Robot>& robotsSurMaLigne, DataType noLigne) const;

public:
   /**
   * Permet de créer les bordures du terrain
   * @param h Hauteur du terrain
   * @param l Largeur du terrain
   */
   Terrain(DataType h, DataType l);

   /**
    * Permet de déployer un nombre choisi de robots
    * sur le terrain
    * @param nbrObjet Nombre d'objects voulus
    */
   void deploiement(unsigned nbrObjet);

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
