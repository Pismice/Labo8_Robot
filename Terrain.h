//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_TERRAIN_H
#define LABO8_ROBOT_TERRAIN_H

#include "Case.h"
#include "Robot.h"
#include <vector>

class Robot;

class Terrain{

private:
   unsigned hauteur;
   unsigned largeur;
   std::vector<std::vector<char>> postion;
public:
   Terrain(unsigned h, unsigned l, unsigned nbreObjets);
   //Terrain();

   unsigned getHauteur() const;

   unsigned getLargeur() const;

   void setPosRobot(Robot& r);

   void simulation();
};

#endif //LABO8_ROBOT_TERRAIN_H
