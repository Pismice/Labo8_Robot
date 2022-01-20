//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H

class Robot{

   //friend void deplacerRobot();
private:
   const unsigned id;
   unsigned x;
   unsigned y;
   static unsigned compteur;
public:
   Robot();
   ~Robot();

   unsigned getId() const;

   unsigned getX() const;

   unsigned getY() const;

   static unsigned getCompteur();

   void setX(unsigned int x);

   void setY(unsigned int y);
};

#endif //LABO8_ROBOT_ROBOT_H
