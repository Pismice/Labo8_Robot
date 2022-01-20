//
// Created by admin on 16.01.2022.
//

#include "Terrain.h"
#include <iostream>

using namespace std;

Terrain::Terrain(unsigned int h, unsigned int l){
   pointMax.setX(l);
   pointMax.setY(h);

//   for(unsigned ligne = 0; ligne < hauteur; ++ligne){
//      for(unsigned colonne = 0; colonne < largeur; ++colonne){
//         if(ligne == 0 or ligne == hauteur - 1 ){
//            postion[ligne][colonne] = '-';
//         }
//         if(colonne == 0 or colonne == largeur - 1){
//            postion[ligne][colonne] = '|';
//         }
//      }
//   }
}


//void Terrain::setPosRobot(Robot &r) {
//
//   r.setX(rand() % ((int)Terrain::getHauteur() - 2) + 1);
//   r.setY(rand() % ((int)Terrain::getLargeur() - 2) + 1);
//
//
//   std::this_thread::sleep_for(std::chrono::microseconds(500));
//}

void Terrain::demarrerJeu() {
   // Afficher terrain
   cout << (*this);

   // Tant qu'il y a assez de robots pour jouer: JOUER!
   while(robots.size() > 1)
   {
      jouerTour();
   }

   // TODO : AFFICHER LE GAGNANT OU PAS ?
}

void Terrain::jouerTour() {
   // Bouger tous les robots
   for(Robot r : robots)
   {

   }

   // Afficher le terrrain (avec surchage <<)
   cout << (*this);
}

ostream &operator<<(ostream &lhs, const Terrain &rhs) {
   system("cls");

   // Affichage du plafond
   for(unsigned x = 0 ; x < rhs.getLargeur() + 2 ; ++x)
   {
      lhs << rhs.plafond;
   }
   lhs << endl;

   // Affichage des lignes du terrain
   for(unsigned y = 0 ; y < rhs.getHauteur() ; ++y)
   {
      lhs << rhs.mur;
      // TODO : tester si la ligne contient des robots
      for(unsigned x = 0 ; x < rhs.getLargeur() ; ++x)
      {

         lhs << rhs.vide;
      }
      lhs << rhs.mur;
      lhs << endl;
   }

   // Affichage du sol
   for(unsigned x = 0 ; x < rhs.getLargeur() + 2 ; ++x)
   {
      lhs << rhs.sol;
   }
   lhs << endl;

   return lhs;
}

unsigned Terrain::getHauteur() const
{
   return unsigned(this->pointMax.getY());
}

unsigned Terrain::getLargeur() const
{
   return unsigned(this->pointMax.getX());
}