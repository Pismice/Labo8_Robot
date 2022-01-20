//
// Created by admin on 16.01.2022.
//

#include "Terrain.h"
#include <iostream>
#include <thread>

using namespace std;

Terrain::Terrain(unsigned int h, unsigned int l){
   hauteur = h;
   largeur = l;

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

unsigned Terrain::getHauteur() const {
   return hauteur;
}

unsigned Terrain::getLargeur() const {
   return largeur;
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

   // boucle while sur jouerTour() tant que > 1 robot en vie
}

void Terrain::jouerTour() {
   // Bouger tous les robots

   // Afficher le terrrain (avec surchage <<)
}

ostream &operator<<(ostream &lhs, const Terrain &rhs) {
   cout << "ceci est mon terrain :)" << endl;
   return lhs;
}
