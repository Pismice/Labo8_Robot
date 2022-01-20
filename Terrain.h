//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_TERRAIN_H
#define LABO8_ROBOT_TERRAIN_H

#include "Robot.h"
#include <vector>
#include <ostream>

class Terrain{

private:
   // Propriétés
   unsigned hauteur;
   unsigned largeur;

   std::vector<std::vector<Robot>> robots;

   // Méthodes
   void jouerTour();


public:

   /**
   * Permet de créer les bordures du terrain
   * @param h Hauteur du terrain
   * @param l Largeur du terrain
   * @param nbreObjets
   */
   Terrain(unsigned h, unsigned l);

   unsigned getHauteur() const;

   unsigned getLargeur() const;

   friend std::ostream& operator<<(std::ostream& lhs, const Terrain& rhs);

   //void setPosRobot(Robot& r);

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
