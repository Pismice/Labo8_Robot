/*
-----------------------------------------------------------------------------------
Nom du fichier  : saisie.cpp
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 10.11.2021

Description     : Définitions permettant de simplifier les saisies utilisateur et met
                  également à disposition des fonctions spécifiques qui peuvent être
                  utilisés dans de nombreux projets

Modification(s) : - Amélioration de la fonction saisieOuiOuNon (Jérémie Santoro)

Remarque(s)     : - https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice/1452738
                  Si comme demandé, le code des librairies doit être le plus réutilisable
                  et modulable que possible il est recommandé de ne pas utiliser using
                  namespace std, pour les raisons citées dans le lien ci-dessus
                  UPDATE 17.01.2020 : Les 2 versions avec using namespace std ou non se valent
                  - Les saisies sont contrôlées


Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>

// Boucle de saisie, pour obtenir une saisie utilisateur correcte
unsigned int saisieDansIntervalle(unsigned int b_inf, unsigned int b_sup,
                                  const std::string &valeur) {
   unsigned int valeurSaisieIntervalle;
   bool erreurSaisieIntervalle;

   do {
      erreurSaisieIntervalle = false;

      std::cout << valeur << " [" << b_inf << " - " << b_sup
                << "] :";
      std::cin >> valeurSaisieIntervalle;

      if (!std::cin.good() || valeurSaisieIntervalle < b_inf ||
          valeurSaisieIntervalle > b_sup) {
         erreurSaisieIntervalle = true;
         std::cin.clear();
      }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   } while (erreurSaisieIntervalle);

   return valeurSaisieIntervalle;
}

// Boucle de saisie utilisateur, pour savoir si il veut recommencer ou pas
bool saisieOuiOuNon(const std::string &question, char yes, char no) {
   char valeurSaisie;
   bool erreurSaisieCharactere;

   do {

      erreurSaisieCharactere = false;

      std::cout << question << " [" << yes << "|" << no << "] :";
      std::cin >> valeurSaisie;

      if (!std::cin.good() || (valeurSaisie != yes && valeurSaisie != no)) {
         erreurSaisieCharactere = true;
         std::cin.clear();
      }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   } while (erreurSaisieCharactere);

   if (valeurSaisie == yes) {
      return true;
   } else {
      return false;
   }
}

bool saisieIdentiqueA(char reponse) {
   char userCharacter;

   std::cout << reponse << " :";

   std::cin >> userCharacter;

   if (!std::cin.good()) {
      std::cin.clear();
   }

   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return (reponse == userCharacter);
}