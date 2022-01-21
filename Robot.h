//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Coordonnee.h"

enum class Direction {HAUT, BAS, DROITE, GAUCHE};

class Robot{
   // TODO : INLINE ??
   // TODO : soit getter soit propriétés, pas mic mac
    friend bool operator==(const Robot& lh, const Robot& rh)
    {
       return (lh.position.getX() == rh.position.getX()) and (lh.position.getY() == rh.position.getY()) and (lh.id != rh.id);
    }


private:
   const unsigned id;
   Coordonnee position;
   static unsigned compteur;
   const unsigned nbreDirections = 4; // TODO : MOYEN DE RECUP LA TAILLE DE L ENUM CLASS
   //const unsigned uniteDeplacement = 1;

public:
   Robot();
   ~Robot();

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
