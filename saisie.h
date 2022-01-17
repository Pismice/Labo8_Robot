/*
-----------------------------------------------------------------------------------
Nom du fichier  : saisie.h
Auteur(s)       : Jérémie Santoro, Didier Lokokpe
Date creation   : 10.11.2021

Description     : Interface qui permet de simplifier les saisies utilisateur et met
                  également à disposition des fonctions spécifiques qui peuvent être
                  utilisés dans de nombreux projets

Modification(s) : - Amélioration de la fonction saisieOuiOuNon (Jérémie Santoro)

Remarque(s)     : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef SAISIE_H
#define SAISIE_H

/**
 * Permet de saisir une valeur entre 2 intervalles inclues
 * @param b_inf Borne inférieure (inclue)
 * @param b_sup Borne supérieure (inclue)
 * @param valeur Description de la valeur
 * @return
 */
unsigned int saisieDansIntervalle(unsigned int b_inf, unsigned int b_sup, const std::string& valeur);

/**
 * Permet de retourner si l'utilisateur a répondu oui ou non à la question
 * @param Question qui sera posée à l'utilisateur
 * @param yes Charactère pour lequel la valeur sera vraie
 * @param no  Charactère pour lequel la valeur sera fausse
 * @return
 */
bool saisieOuiOuNon(const std::string& question, char yes, char no);

/**
 * Permet de prendre une entrée et vérifier si celle-ci correspond au paramètre
 * @param Valeur qui doit correspondre
 * @return Si la saisie utilisateur est identique au paramètre ou pas
 */
bool saisieIdentiqueA(char reponse);

#endif //SAISIE_H
