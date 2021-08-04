
     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleMaths.cpp                            */
/*...................................................................*/
/*          Par    :                                                 */
/*...................................................................*/    //
/*          Date   : mardi le 15 juin le 2021                        */   //
/*...................................................................*/  //
/*    Dernière modification : lundi le 21 juin le 2021 06:21 P.M.    */ //
/*___________________________________________________________________*///
/*    propelled by       C   H    N   O                              */
/*                          8  10   4   2                            */
/*___________________________________________________________________*/
/*                        GBS enabled                                */
/*___________________________________________________________________*/


/*___________________________________________________________________________*/
/*			   Commandes préprocesseur et modules	     		             */
/*___________________________________________________________________________*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*___________________________________________________________________________*/
/*						 Fichier(s) d'en-tête  	     	  	                 */
/*___________________________________________________________________________*/


#include "ModuleImages.h"
#include "ModuleMaths.h"
#include "ModuleConstantes.h"
/*  ___________________________________________________________________________
	Nom	:			 degVersRad
	___________________________________________________________________________
	Description :	Cette fonction fait la conversion de degrés vers radians

	___________________________________________________________________________
	Paramètres :	Un double qui correspond à l’angle en degrés.
	___________________________________________________________________________
	Retour :		Un double qui correspond à l’angle en radians.
	___________________________________________________________________________
	Test associé :  Votre test doit valider que 180° vaut 𝜋 en reproduisant
					l’affichage suivant :

	degVeRad_test : SUCCES

		valeur attendue : 3.1416 +/- 0.001
		valeur obtenue : 3.1416
	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
double degVersRad(const double deg)
{
	return (deg * PI / PI_DEG);
}
/*  ___________________________________________________________________________
	Nom	:			nombreAleatoireBinaire
	___________________________________________________________________________
	Description :	Cette fonction génère un nombre aléatoire binaire
					uniformément distribué suivant une proportion 𝑝 donnée.
					La probabilité de retourner la valeur 1 est de 𝑝 et la
					probabilité de retourner la valeur 0 est son complément,
					soit 1 − 𝑝.
	___________________________________________________________________________
	Paramètres :	Un double qui correspond à la probabilité de générer
					la valeur 1.
	___________________________________________________________________________
	Retour :		Un entier qui correspond à un nombre binaire aléatoire
	___________________________________________________________________________
	Test associé : Vous devez écrire une procédure de test qui calcule la
				   moyenne de 106 nombres aléatoires binaires et qui possède
				   l’affichage suivant :

	  test_nombreAleatoireBinaire : SUCCES

			  valeur obtenue :  0.500
			  valeur attendue : 0.500   +/- 0.001


	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
int nombreAleatoireBinaire(const double prob)
{
	return (double)rand() / RAND_MAX <= prob ? 1 : 0;
}

double nombreAleatoireEntreBornes(const double min, const double max)
{
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

int compter_occurences(const int tab[TAILLE_TEMP],
	const int nb_elements,
	const int a_trouver)
{

	int nb_occurences = 0;

	for (int i = 0; i < nb_elements; ++i)
	{


		if (tab[i] == a_trouver) {

			nb_occurences += 1;
		}

	}

	return nb_occurences;

}

int ValeurMaxTableau(int tab[], int taille)
{
	int max = tab[0];

	for (int i = 1; i < taille; i++) {

		if (tab[i] > max) {

			max = tab[i];
		}
	}

	return max;
}