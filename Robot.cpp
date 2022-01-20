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
          if(this->position.getY() <= 0){ // hauteur mini
              setPosition(position.getX(), 2);
          }else{
              unsigned y = position.getY() + 1;
              setPosition(position.getX(), y);
          }
         break;
      case int(Robot::Direction::BAS) :
          if(this->position.getY() >= 10){ // hauteur maxi
              setPosition(position.getX(), 8);
          }else{
              unsigned y = position.getY() + 1;
              setPosition(position.getX(), y);
          }
         break;
      case int(Robot::Direction::DROITE) :
          if(this->position.getX() >= 10){ // hauteur maxi
              setPosition(8,position.getY());
          }else{
              unsigned x = position.getX() + 1;
              setPosition(x, position.getY());
          }
         break;
      case int(Robot::Direction::GAUCHE) :
          if(this->position.getX() <= 0){ // hauteur maxi
              setPosition(2,position.getY());
          }else{
              unsigned x = position.getX() + 1;
              setPosition(x, position.getY());
          }
         break;
   }
   //
}
