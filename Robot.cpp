//
// Created by admin on 16.01.2022.
//

#include "Robot.h"
#include <cstdlib>
#include <thread>

unsigned Robot::compteur = 0;

Robot::Robot():id(compteur)
{
   ++compteur;
}

unsigned Robot::getId() const {
   return id;
}


unsigned Robot::getCompteur() {
   return compteur;
}

void Robot::deplacer() {
   auto d = short(rand() % nbreDirections-1);

   switch (d) {
      case int(Robot::Direction::HAUT) :
              //setPosition(position.getX(), position.getY() + 1);
      case int(Robot::Direction::BAS) :
              setPosition(position.getX(), position.getY() + 1);
         break;
      case int(Robot::Direction::DROITE) :
              //setPosition(position.getX() + 1, position.getY());
      case int(Robot::Direction::GAUCHE) :
              setPosition(position.getX() + 1, position.getY());
         break;
   }
   //
}
