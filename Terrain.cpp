/*
-----------------------------------------------------------------------------------
Nom du fichier  : Terrain.cpp
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 21.01.2022

Description     : Définitions permettant de gèrer et simuler un terrain en 2D,
                  il peut via un opérateur de flux envoyer son affichage, générer
                  des robots et gérer une partie de bataille de robots

Remarque(s)     : - Ne gère pas le cas ou le nombre de robots est supérieurs au nombre
                    de cases

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Terrain.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <experimental/random>

using namespace std;

Terrain::Terrain(DataType h, DataType l){
   pointMax.setX(l-1);
   pointMax.setY(h-1);
   pointMin.setX(0);
   pointMin.setX(0);
}

void Terrain::deploiement(unsigned nbrObjet) {

   //robots.resize(nbrObjet);

   for(size_t j = 0; j < nbrObjet; ++j)
   {
       bool estUneCaseVierge = false;
       DataType x, y;

       while(!estUneCaseVierge)
       {

           // Génération aléatoire des coordonnées
           x = DataType (rand() % ((int)Terrain::pointMax.getX()));
           y = DataType (rand() % ((int)Terrain::pointMax.getY()));
           estUneCaseVierge = true;

          // Controle si ces x et y existent déjà sur un robot existant
           for(auto & robot : robots)
           {
               if(robot.getPosition().getX() == x and robot.getPosition().getY() == y)
               {
                  estUneCaseVierge = false;
                  break;
               }
           }
       }
       Robot r;
       r.setPosition(x,y);
       robots.push_back(r);
       //robots.at(j).setPosition(x,y);
   }
}

void Terrain::demarrerJeu()
{
   // Afficher terrain
   cout << (*this);

   // Tant qu'il y a assez de robots pour jouer: JOUER!
   while(robots.size() > 1)
   {
      jouerTour();
   }
   cout << "finitooooo";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Terrain::jouerTour()
{
   // Bouger tous les robots
   for(Robot& r : robots)
   {
       r.deplacer();

       // Vérifier si dans les limites du terrain
       if(r.getPosition().getY() <= pointMin.getY())
       {
           r.setPosition(r.getPosition().getX(), (pointMin.getY() + valeurRebondissement));
       }
       if(r.getPosition().getY() >= pointMax.getY())
       {
           r.setPosition(r.getPosition().getX(), (pointMax.getY() - valeurRebondissement));
       }
       if(r.getPosition().getX() <= pointMin.getX())
       {
           r.setPosition(pointMin.getX() + valeurRebondissement, r.getPosition().getY());
       }
       if(r.getPosition().getX() >= pointMax.getX())
       {
           r.setPosition(pointMax.getX() - valeurRebondissement, r.getPosition().getY());
       }

      // Vérifier si le robot arrive sur la case d'un robot
      for(auto i = robots.begin(); i != robots.end(); i++)
      {
         if(*i == r)
         {
            robots.erase(i);
         }
      }
   }

   // Afficher le terrrain (avec surchage <<)
   cout << (*this);
   this_thread::sleep_for(delai);
}

bool Terrain::siRobotPresentSurLigne(vector<Robot>& robotsSurMaLigne, DataType noLigne) const
{
   bool robotPresent = false;
   for(const Robot& robot : robots)
   {
      if(robot.getPosition().getY() == noLigne)
      {
         robotsSurMaLigne.emplace_back(robot);
         robotPresent = true;
      }
   }

   return robotPresent;
}

ostream &operator<<(ostream &lhs, const Terrain &rhs)
{
   system("cls");

   // Affichage du plafond
   for(DataType x = 0 ; x < rhs.pointMax.getX() + 2 ; ++x)
   {
      lhs << Terrain::plafond;
   }
   lhs << endl;

   // Affichage des lignes du terrain
   for(DataType y = 0 ; y < rhs.pointMax.getY() + 1; ++y)
   {
      // Affichage du mur gauche
      lhs << Terrain::mur;

      // Affichage de la ligne du milieu
      string ligne(size_t(rhs.pointMax.getX()), Terrain::vide);
      vector<Robot> robotsSurMaLigne;
      if(rhs.siRobotPresentSurLigne(robotsSurMaLigne, y))
      {
         for(const Robot& r : robotsSurMaLigne)
         {
            ligne.at(size_t(r.getPosition().getX())) = char(r.getId() + '0') ;
         }
      }
      lhs << ligne;

      // Affichage du mur droite
      lhs << Terrain::mur;

      lhs << endl;
   }

   // Affichage du sol
   for(DataType x = 0 ; x < rhs.pointMax.getX() + 2 ; ++x)
   {
      lhs << Terrain::sol;
   }
   lhs << endl;

   return lhs;
}