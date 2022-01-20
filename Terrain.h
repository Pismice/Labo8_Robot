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
   std::vector<Robot> robots;
   const char plafond = '^';
   const char sol = '_';
   const char mur = '|';
   const char vide = ' ';

   std::vector<Robot> robot;

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

    unsigned getRobot() const;

    void creerRobot(unsigned nbrObjet);

    void idRobot();

   /**
   * Permet de démarer le jeu et simuler les déplacements et combats des robots
   */
   void demarrerJeu();
};

#endif //LABO8_ROBOT_TERRAIN_H
