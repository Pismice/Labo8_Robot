//
// Created by admin on 16.01.2022.
//

#include "Terrain.h"
#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

/*class estOccuper{
private:
    Robot rb;
public:
    estOccuper(const Robot& init): rb(init){
        //rb.setX(init.getX());
        //rb.setY(init.getY());
    }
    bool operator() (const Robot& param){
        return !(rb == param);
    }
};*/


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


unsigned Terrain::getLargeur() const {
   return largeur;
}

void Terrain::creerRobot(unsigned nbrObjet) {

   for(unsigned j = 0; j < nbrObjet; ++j){ //boucle sur nbr d'objet a créer
       bool siCaseVierge = false;
       unsigned x, y;
       robot.reserve(nbrObjet);
       robot.size();

       while(!siCaseVierge){

           // Génération aléatoire des coordonnées
           x = rand() % ((int)hauteur - 2) + 1;
           y = rand() % ((int)largeur - 2) + 1;

          // controle si la case existe déja
           for(size_t i = 0; i < robot.size(); ++i){
               if(robot.at(i).getX() == x and robot.at(i).getY() == y){
                   siCaseVierge = false;
                   break;
               }
               siCaseVierge = true;
           }
           Robot r;
           r.setX(x);
           r.setY(y);
           robot.emplace_back(r);
           siCaseVierge = true;
       }
   }
}

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