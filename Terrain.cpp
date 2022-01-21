#include "Terrain.h"
#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

// TODO : bonne place ?


Terrain::Terrain(unsigned int h, unsigned int l){
   pointMax.setX(l);
   pointMax.setY(h);
}


void Terrain::deploiement(unsigned nbrObjet) {

   robots.resize(nbrObjet);

   for(size_t j = 0; j < nbrObjet; ++j)
   {
       bool estUneCaseVierge = false;
       unsigned x, y;

       while(!estUneCaseVierge)
       {

           // Génération aléatoire des coordonnées
           x = unsigned(rand() % ((int)Terrain::getLargeur()));
           y = unsigned(rand() % ((int)Terrain::getHauteur()));
           estUneCaseVierge = true;
          // Controle si ces x et y existent déjà sur un robot existant
           for(size_t i = 0; i < robots.size(); ++i)
           {
               if(robots.at(i).getPosition().getX() == x and robots.at(i).getPosition().getY() == y)
               {
                  estUneCaseVierge = false;
                  break;
               }
           }
       }
//       Robot r;
//       r.setPosition(x,y);
//       robots.push_back(r);
       robots.at(j).setPosition(x,y);
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
}

void Terrain::jouerTour()
{
   // Bouger tous les robots
   for(Robot& r : robots) // TODO : vraiment & ?
   {
      r.deplacer();

       // Vérifier si dans les cases
       if(r.getPosition().getY() == MINY){ // hauteur mini
           r.setPosition(r.getPosition().getX(), (MINY + 2));
       }
       if(r.getPosition().getY() == pointMax.getY()){
           r.setPosition(r.getPosition().getX(), (Terrain::getHauteur() - 2));
       }
       if(r.getPosition().getX() == MINX){
           r.setPosition((MINX + 2), r.getPosition().getY());
       }
       if(r.getPosition().getX() == pointMax.getX()) {
           r.setPosition((Terrain::getLargeur() - 2), r.getPosition().getY());
       }

      // Vérifier si le robot arrive sur la case d'un robot
      //remove(robots.begin(), robots.end(), r);

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
   this_thread::sleep_for(test1);
}

bool Terrain::siRobotPresentSurLigne(vector<Robot>& robotsSurMaLigne, unsigned noLigne) const
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
   for(unsigned x = 0 ; x < rhs.getLargeur() + 2 ; ++x)
   {
      lhs << rhs.plafond;
   }
   lhs << endl;

   // Affichage des lignes du terrain
   for(unsigned y = 0 ; y < rhs.getHauteur() ; ++y)
   {
      // Affichage du mur gauche
      lhs << rhs.mur;

      // Affichage de la ligne du milieu
      string ligne(rhs.getLargeur(), rhs.vide);
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
      lhs << rhs.mur;

      lhs << endl;
   }

   // Affichage du sol
   for(unsigned x = 0 ; x < rhs.getLargeur() + 2 ; ++x)
   {
      lhs << rhs.sol;
   }
   lhs << endl;

   // TODO : supprimer l affichage des coordonnees
//   for(Robot r : rhs.robots)
//   {
//      lhs << "ID = " << r.getId() << endl;
//      lhs << "x = " << r.getPosition().getX() << endl;
//      lhs << "y = " << r.getPosition().getY() << endl;
//      lhs << endl;
//   }

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

