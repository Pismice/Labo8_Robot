//
// Created by admin on 16.01.2022.
//

#include "Robot.h"
#include <cstdlib>
#include <thread>

unsigned Robot::compteur = 0;

Robot::Robot():id(++compteur) {}
/*Robot::Robot(const Robot& rb):x(rb.x),y(rb.y) {}
Robot &Robot::operator=(const Robot &r){
    this->x = r.x;
    this->y = r.y;
    return *this;
}

Robot::~Robot() {
   --compteur;
}*/

unsigned Robot::getId() const {
   return id;
}

Coordonnee Robot::getPosition()
{
   return this->position;
}

unsigned Robot::getCompteur() {
   return compteur;
}

void Robot::deplacer() {
   short d = short(rand() % nbreDirections-1);

   switch (d) {
      case int(Robot::Direction::HAUT) :

         break;
      case int(Robot::Direction::BAS) :

         break;
      case int(Robot::Direction::DROITE) :

         break;
      case int(Robot::Direction::GAUCHE) :

         break;
   }
   //
}
