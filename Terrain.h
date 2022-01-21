/*
-----------------------------------------------------------------------------------
Nom du fichier  : Terrain.h
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Interface permettant de gèrer et simuler un terrain en 2D,
                  il peut via un opérateur de flux envoyer son affichage, générer
                  des robots, et gérer une partie de bataille de robots

Remarque(s)     : -

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

    friend std::ostream& operator<<(std::ostream& lhs, const Terrain& rhs);

   // Constantes statiques
   const static char plafond = '^';
   const static char sol = '_';
   const static char mur = '|';
   const static char vide = ' ';

private:
   // Propriétés
   Coordonnee pointMax{};
   Coordonnee pointMin{};
   DataType valeurRebondissement = 1;

   //std::chrono::duration<unsigned, std::milli> delai = 500;
   duration delai = std::chrono::duration_cast<duration>(std::chrono::seconds (1));

   // Méthodes
   void jouerTour();
   bool siRobotPresentSurLigne(std::vector<Robot>& robotsSurMaLigne, DataType noLigne) const;

public:
   std::vector<Robot> robots; // TODO REMETTRE EN PRIVATE
   /**
   * Permet de créer les bordures du terrain
   * @param h Hauteur du terrain
   * @param l Largeur du terrain
   * @param nbreObjets
   */
   Terrain(DataType h, DataType l);
   void deploiement(unsigned nbrObjet);

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
