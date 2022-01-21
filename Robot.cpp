/*
-----------------------------------------------------------------------------------
Nom du fichier  : Robot.cpp
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Définitions permettant de gèrer et simuler un robot dans un espace 2D

Remarque(s)     : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include "Robot.h"
#include <cstdlib>

unsigned Robot::compteur = 0;

Robot::Robot():id(compteur)
{
   ++compteur;
}

Robot::~Robot()
{
   --compteur;
}

void Robot::deplacer()
{
   auto d = short(unsigned(rand()) % nbreDirections);

   switch (d) {
      case int(Direction::HAUT) :
              setPosition(position.getX(), position.getY() - uniteDeplacement);
              break;
      case int(Direction::BAS) :
              setPosition(position.getX(), position.getY() + uniteDeplacement);
               break;
      case int(Direction::DROITE) :
              setPosition(position.getX() + uniteDeplacement, position.getY());
              break;
      case int(Direction::GAUCHE) :
              setPosition(position.getX() -uniteDeplacement , position.getY());
              break;
   }
}
