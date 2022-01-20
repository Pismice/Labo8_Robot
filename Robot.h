//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Coordonnee.h"

class Robot{

   //friend void deplacerRobot();
private:
   const unsigned id;
   Coordonnee position;
   static unsigned compteur;
   enum class Direction {HAUT, BAS, DROITE, GAUCHE}; // TODO : PQ PAS STATIC ? et public pour le switch case
   const unsigned nbreDirections = 4; // TODO : MOYEN DE RECUP LA TAILLE DE L ENUM CLASS
   const int uniteDeplacement = 1;

public:
   Robot();
   ~Robot();

   unsigned getId() const;
   static unsigned getCompteur();
   Coordonnee getPosition();
   void deplacer();
};

#endif //LABO8_ROBOT_ROBOT_H
