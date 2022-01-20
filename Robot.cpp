//
// Created by admin on 16.01.2022.
//

#include "Robot.h"
#include <cstdlib>
#include <thread>

unsigned Robot::compteur = 0;

Robot::Robot():id(++compteur) {
   //id = compteur;
  // ++compteur;

}

Robot::~Robot() {
   --compteur;
}

unsigned Robot::getId() const {
   return id;
}

unsigned Robot::getX() const {
   return x;
}

unsigned Robot::getY() const {
   return y;
}

unsigned Robot::getCompteur() {
   return compteur;
}

void Robot::setX(unsigned int x) {
   Robot::x = x;
}

void Robot::setY(unsigned int y) {
   Robot::y = y;
}

   /*void deplacerRobot() {
   }*/

