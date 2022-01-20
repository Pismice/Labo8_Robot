//
// Created by admin on 16.01.2022.
//

#include "Terrain.h"
#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

// TODO : bonne place ?
const char plafond = '^';
const char sol = '_';
const char mur = '|';
const char vide = ' ';

Terrain::Terrain(unsigned int h, unsigned int l){
   pointMax.setX(l);
   pointMax.setY(h);
}


void Terrain::creerRobot(unsigned nbrObjet) {

   for(unsigned j = 0; j < nbrObjet; ++j){ //boucle sur nbr d'objet a créer
       bool siCaseVierge = false;
       unsigned x, y;
       robots.reserve(nbrObjet);
       robots.size();

       while(!siCaseVierge){

           // Génération aléatoire des coordonnées
           x = rand() % ((int)pointMax.getY() - 2) + 1;
           y = rand() % ((int)pointMax.getX() - 2) + 1;

          // controle si la case existe déja
           for(size_t i = 0; i < robots.size(); ++i){
               if(robots.at(i).getPosition().getX() == x and robots.at(i).getPosition().getY() == y){
                   siCaseVierge = false;
                   break;
               }
               siCaseVierge = true;
           }
           Robot r;
           r.setPosition(x,y);
           robots.emplace_back(r);
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
      lhs << plafond;
   }
   lhs << endl;

   // Affichage des lignes du terrain
   for(unsigned y = 0 ; y < rhs.getHauteur() ; ++y)
   {
      lhs << mur;
      // TODO : tester si la ligne contient des robots
      for(unsigned x = 0 ; x < rhs.getLargeur() ; ++x)
      {

         lhs << vide;
      }
      lhs << mur;
      lhs << endl;
   }

   // Affichage du sol
   for(unsigned x = 0 ; x < rhs.getLargeur() + 2 ; ++x)
   {
      lhs << sol;
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