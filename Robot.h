//
// Created by admin on 16.01.2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H

class Robot{
    friend bool operator==(const Robot& lh, const Robot& rh){
        return (lh.x == rh.x and lh.y == rh.y);
    }

   //friend void deplacerRobot();
private:
   const unsigned id;
   unsigned x;
   unsigned y;
   static unsigned compteur;
public:
   Robot();

   //Robot(const Robot& rb);

   //Robot& operator=(const Robot& r);

  // ~Robot();

   unsigned getId() const;

   unsigned getX() const;

   unsigned getY() const;

   static unsigned getCompteur();

   void setX(unsigned int x);

   void setY(unsigned int y);
};

#endif //LABO8_ROBOT_ROBOT_H
