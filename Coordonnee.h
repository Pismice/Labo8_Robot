/*
-----------------------------------------------------------------------------------
Nom du fichier  : Coordonnee.h
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Cette interface accompagnée de ses définitions, permet de gèrer
                  de manière centralisée la représentation dans l'espace
Remarque(s)     : Le choix du int a été car il parait plus logique pour représenter des
                  points dans un système carthésien, le jeu pourrait évaluer de manière
                  intéressante grâce à ca

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_COORDONNEE_H
#define LABO8_ROBOT_COORDONNEE_H

using DataType = int;

class Coordonnee {
   // Propriétés
   DataType x;
   DataType y;

public:
   // Constructeur
   Coordonnee(){}
   Coordonnee(DataType newX, DataType newY) : x(newX), y(newY){}

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
   void setX(DataType newX)
   {
      this->x = newX;
   }
   void setY(DataType newY)
   {
      this->y = newY;
   }
};

#endif //LABO8_ROBOT_COORDONNEE_H
