//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_TERRAIN_H
#define LABO8_ROBOT_TERRAIN_H

#include "Robot.h"
#include <vector>
#include <ostream>
#include <thread>
#include "Coordonnee.h"

class Terrain{

    friend std::ostream& operator<<(std::ostream& lhs, const Terrain& rhs);

private:
   // Propriétés
   Coordonnee pointMax;
   const unsigned MINX = 0;
   const unsigned MINY = 0;

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
   unsigned getHauteur() const;
   unsigned getLargeur() const;
   void deploiement(unsigned nbrObjet);

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
