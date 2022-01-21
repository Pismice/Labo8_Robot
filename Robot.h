/*
-----------------------------------------------------------------------------------
Nom du fichier  : Robot.h
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Interface permettant de gèrer et simuler un robot dans un espace 2D

Remarque(s)     : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Coordonnee.h"

enum class Direction {HAUT = 1, BAS, DROITE, GAUCHE};

class Robot{

   // Fonctions amies
   friend bool operator==(const Robot& lh, const Robot& rh)
   {
    return (lh.position.getX() == rh.position.getX())
            and (lh.position.getY() == rh.position.getY()) and (lh.id != rh.id);
   }

   // Propriétés statiques
   static unsigned compteur;
   const static unsigned nbreDirections; // TODO : MOYEN DE RECUP LA TAILLE DE L ENUM CLASS

private:
   // Propriétés privées
   unsigned id;
   Coordonnee position{};
   const DataType uniteDeplacement = 1;

public:
   Robot();
   //~Robot();

   Robot& operator=(const Robot& r)
   {
      id = r.id;
      position = r.position;
      return *this;
   }

   Coordonnee getPosition() const
   {
      return this->position;
   }

   void setPosition(DataType x, DataType y)
   {
      this->position.setX(x);
      this->position.setY(y);
   }

   unsigned getId() const
   {
      return id;
   }

   void deplacer();
};

#endif //LABO8_ROBOT_ROBOT_H
