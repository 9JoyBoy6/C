/**
 * \file polynome.c
 * \Fonctions de manipulation de polynômes.
 */

#include "polynome.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Constructeurs
////////////////////////////////////////////////////////////////////////////////

polynome* polynome_addition(const polynome* const P1, const polynome* const P2)
{
  liste* resultat = liste_vide();
  /* (Peut-être) À compléter ou modifier. */
  liste * poly1 = liste_debut(P1);
  liste * poly2 = liste_debut(P2);

  if(!poly1)
    return poly2;
  else if(!poly2)
    return poly1;
  else{
    while(poly1)
    {
      resultat = liste_inserer(resultat,liste_monome(poly1));
      poly1 = liste_suivant(poly1);
    }
    while(poly2)
    {
      resultat = liste_inserer(resultat, liste_monome(poly2));
      poly2 = liste_suivant(poly2);
    }
  }

  resultat = liste_normaliser(resultat);

  return resultat;
}

polynome* polynome_multiplication(
    const polynome* const P1, const polynome* const P2)
{
  liste* resultat = liste_vide();
  /* (Peut-être) À compléter ou modifier. */
  liste * poly1 = liste_debut(P1);
  liste * poly2 = NULL;
  monome reponse;
  monome poly_un;
  monome poly_deux;

  if(liste_est_vide(P1) || liste_est_vide(P2))
    return NULL;
  else
  {
    while(poly1)
    {
      poly_un = liste_monome(poly1);
      poly2 = liste_debut(P2);
      while(poly2)
      {
        poly_deux = liste_monome(poly2);
        reponse.degre = poly_un.degre + poly_deux.degre;
        reponse.coefficient = poly_un.coefficient * poly_deux.coefficient;
        resultat = liste_inserer(resultat,reponse);
        poly2 = liste_suivant(poly2);
      }
      poly1 = liste_suivant(poly1);
    }
  }

  return liste_normaliser(resultat);
}

polynome* polynome_derivee(const polynome* const P1)
{
  /* (Peut-être) À compléter ou modifier. */
    liste * poly1 = liste_debut(P1);
    liste * resultat = NULL;
    monome courant;

    if(liste_est_vide(P1))
      return NULL;
    else
    {
      while(poly1)
      {
        courant = liste_monome(poly1);
        courant.coefficient *= courant.degre;
        courant.degre--;
        resultat = liste_inserer(resultat,courant);
        poly1 = liste_suivant(poly1);
      }
    }
  return liste_normaliser(resultat);
}

////////////////////////////////////////////////////////////////////////////////
// Divers
////////////////////////////////////////////////////////////////////////////////

void polynome_free(polynome* p){
free(p);
}



polynome* polynome_fread(FILE* const stream)
{
  polynome* p = liste_fread(stream);
  p = liste_normaliser(p);
  return p;
}

void polynome_fwrite(FILE* const stream, const polynome* const p)
{
  liste_fwrite(stream, p);
}
