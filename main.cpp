/*
-----------------------------------------------------------------------------------
Nom du fichier  : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s)       : Jérémie Santoro
Date creation   : <jj.mm.aaaa>

Description     : <à compléter>

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Robot.h"
#include "Terrain.h"
using namespace std;

int main() {

   Terrain t(10, 20);

   srand((unsigned )time(nullptr));

   Robot R1;
   t.setPosRobot(R1);
   //this_thread :: sleep_for (100ms);
   Robot R2;
   t.setPosRobot(R2);
   //this_thread :: sleep_for (100ms);
   Robot R3;
   t.setPosRobot(R3);

   t.simulation();

 return EXIT_SUCCESS;
}