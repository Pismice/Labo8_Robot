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

class Robot{

   // Fonctions amies
   friend bool operator==(const Robot& lh, const Robot& rh)
   {
    return (lh.position.getX() == rh.position.getX())
            and (lh.position.getY() == rh.position.getY()) and (lh.id != rh.id);
   }

   // Propriétés statiques
   static unsigned compteur;     // Nombre de robots  instanciés
   const static unsigned NBRE_DIRECTIONS; // Nombre de directions possibles

private:
   // Propriétés privées
   unsigned id;
   Coordonnee position;
   const DataType uniteDeplacement = 1;

public:
   Robot();
   ~Robot();

   enum class Direction {HAUT, BAS, DROITE, GAUCHE};

   /**
    * Opérateur de copie
    * @param r Robot à copier
    * @return Robot affécté
    */
   Robot& operator=(const Robot& r)
   {
      id = r.id;
      position = r.position;
      return *this;
   }

   /**
    * Retourne la position du robot
    * @return Position du robot
    */
   Coordonnee getPosition() const
   {
      return this->position;
   }

   /**
    * Assigne la position en fonction de x et y
    * @param x Valeur x
    * @param y Valeur y
    */
   void setPosition(DataType x, DataType y)
   {
      this->position.setX(x);
      this->position.setY(y);
   }

   /**
    * Retourne l'id du robot
    * @return Id du robot
    */
   unsigned getId() const
   {
      return id;
   }

   /**
    * Permet au robot de se déplacer
    */
   void deplacer();
};

#endif //LABO8_ROBOT_ROBOT_H
