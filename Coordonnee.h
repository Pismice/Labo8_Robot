//
// Created by pismice on 20.01.2022.
//

#ifndef LABO8_ROBOT_COORDONNEE_H
#define LABO8_ROBOT_COORDONNEE_H

using DataType = int;

class Coordonnee {
   // Propriétés
   DataType x;
   DataType y;



public:
   // Getters
   DataType getX() const
   {
      return x;
   }
   DataType getY() const
   {
      return y;
   }

   // Setters
   void setX(DataType x)
   {
      this->x = x;
   }
   void setY(DataType y)
   {
      this->y = y;
   }


};


#endif //LABO8_ROBOT_COORDONNEE_H
