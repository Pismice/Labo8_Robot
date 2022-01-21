//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Coordonnee.h"

class Robot{
   // TODO : INLINE ??
   // TODO : soit getter soit propriétés, pas mic mac
    friend bool operator==(const Robot& lh, const Robot& rh)
    {
        return (lh.position.getX() == rh.position.getX() and lh.position.getY() == rh.position.getY() and lh.id != rh.id);
    }


private:
   const unsigned id;
   Coordonnee position;
   static unsigned compteur;
   enum class Direction {HAUT, BAS, DROITE, GAUCHE}; // TODO : PQ PAS STATIC ? et public pour le switch case
   const unsigned nbreDirections = 4; // TODO : MOYEN DE RECUP LA TAILLE DE L ENUM CLASS
   const int uniteDeplacement = 1;

public:
   Robot();

   Robot& operator=(const Robot& r)
   {
      // TODO  : best practice ?
      Robot temp = r;
      return temp;
   }

   Coordonnee getPosition() const
   {
      return this->position;
   }
   void setPosition(unsigned x, unsigned y)
   {
      this->position.setX(x);
      this->position.setY(y);
   }

   unsigned getId() const;
   static unsigned getCompteur();
   void deplacer();
};

#endif //LABO8_ROBOT_ROBOT_H
