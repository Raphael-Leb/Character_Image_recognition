#pragma once

#include <stdlib.h>
#include <math.h>

#include "ModuleConstantes.h"

/* Fonction de conversion entre les degr�s et les radians. */
double degVersRad(const double deg);

/* Fonction qui calculer la distance euclidienne entre deux images */ 
double calculerDistanceEuclidienne(unsigned char** img1,
								   unsigned char** img2);

/* Fonction qui calcule la distance de Manhattan entre deux images */
double calculerDistanceManhattan(unsigned char** img1,
								 unsigned char** img2);

/* Fonction qui g�n�re un nombre al�atoire binaire suivant une probabilit� donn�e de g�n�rer la valeur 1 */
int nombreAleatoireBinaire(const double prob);

/* Fonction qui g�n�re un nombre al�atoire entre bornes */
double nombreAleatoireEntreBornes(const double min, const double max);
int compter_occurences(const int tab[TAILLE_TEMP],
	const int nb_elements,
	const int a_trouver);