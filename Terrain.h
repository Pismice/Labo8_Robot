//
// Created by admin on 16.01.2022.
//

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
   Coordonnee pointMax;
   Coordonnee pointMin;
   unsigned valeurRebondissement = 1;

   //std::chrono::duration<unsigned, std::milli> delai = 500;
   duration delai = std::chrono::duration_cast<duration>(std::chrono::seconds (1));

   // Méthodes
   void jouerTour();
   bool siRobotPresentSurLigne(std::vector<Robot>& robotsSurMaLigne, unsigned noLigne) const;

public:
   std::vector<Robot> robots; // TODO REMETTRE EN PRIVATE
   /**
   * Permet de créer les bordures du terrain
   * @param h Hauteur du terrain
   * @param l Largeur du terrain
   * @param nbreObjets
   */
   Terrain(unsigned h, unsigned l);
   void deploiement(unsigned nbrObjet);

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
