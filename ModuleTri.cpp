#pragma once
     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleIntelligenceArtificielle.cpp        */
/*...................................................................*/
/*        Description    :  Ce module contient les fonctions de tri  */
/*...................................................................*/
/*          Par    :        équipe 04                                */
/*...................................................................*/    //
/*          Date   : jeudi le 01 juillet  2021                       */   //
/*...................................................................*/  //
/*  Dernière modification : dimanche le 04 juillet  2021 06:31 P.M.  */ //
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
#include <math.h>


/*___________________________________________________________________________*/
/*						 Fichier(s) d'en-tête  	     	  	                 */
/*___________________________________________________________________________*/
#include "ModuleImages.h"
#include "ModuleMaths.h"
#include "ModuleIntelligenceArtificielle.h"
#include "ModuleTri.h"
#include "ModuleTri.h"



/*  ___________________________________________________________________________
	Nom	:			 tamiser
	___________________________________________________________________________
	Description :	 Procédure de tamisage qui sert à représenter un tableau 1D 
	                 en tas max.
	___________________________________________________________________________
	Paramètres :     Un tableau d’entiers et sa taille			
	___________________________________________________________________________
	Retour :		 aucun
    ___________________________________________________________________________
	Test associé : Lorsque vous exécutez tamiser_test fourni dans 
	               ModuleTri_test, vous devez obtenir l’affichage suivant :

    tamiser_test: SUCCES

	         Valeur attendue : [ 100, 36, 25, 17, 7, 19, 1, 2, 3 ]
			 Valeur attendue : [ 100, 36, 25, 17, 7, 19, 1, 2, 3 ]
	___________________________________________________________________________
	NOTE :  Si vous n’obtenez pas le même tableau tamisé, assurez vous que 
	        votre résultat répond à la condition de tas max donnée à la section 
			2.
    ___________________________________________________________________________
*/
void tamiser(int tab[], int taille) {

	int n = 0, parent = 0;

	while (n < taille) {

		parent = (n - 1) / 2;

		if (tab[n] > tab[parent]) {

			SWAP(&tab[parent], &tab[n]);

			n = 0;
		}
		else {
			n++;
		}
	}
}

/*  ___________________________________________________________________________
	Nom	:			triTas
	___________________________________________________________________________
	Description :	  Cette procédure est une implémentation du tri par tas
	___________________________________________________________________________
	Paramètres :      Un tableau d’entiers 
	                  Un entier qui correspond à la taille du tableau.			      
	___________________________________________________________________________
	Retour :		 aucun
	___________________________________________________________________________
	Test associé : Lorsque vous exécutez trisTas_test fourni dans
				   ModuleTri_test, vous devez obtenir l’affichage suivant :

	trisTas_test: SUCCES

			 Valeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
			 Valeur obtenue  : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
	___________________________________________________________________________
*/
void triTas(int tab[], int taille) {

	int compteur = 0;

	for (int i = 0; i < taille; i++) {

		tamiser(tab, taille-compteur);

		compteur++;

		SWAP(&tab[0], &tab[taille - compteur]);
	}
}

/*  ___________________________________________________________________________
	Nom	:			partitionner
	___________________________________________________________________________
	Description : Cette fonction partitionne un sous-ensemble d’un tableau.
	___________________________________________________________________________
	Paramètres :      Un tableau d’entiers
	                  Un entier qui correspond à l’indice de début.
					  Un entier qui correspond à l’indice de fin.
	___________________________________________________________________________
	Retour :		 Un entier qui correspond au pivot.
    ___________________________________________________________________________
	Test associé : Lorsque vous exécutez partisionner_test fourni dans
				   ModuleTri_test, vous devez obtenir l’affichage suivant :

	partisionner_test: SUCCES

			 Valeur attendue  1 : 8
			 Valeur obtenue   1 : 8

			 Valeur attendue  2 : 2
			 Valeur obtenue   2 : 2
	___________________________________________________________________________
*/
int partitionner(int tab[], int debut, int fin) {

	int pivot = tab[fin];
	int i = debut;

	for (int j = debut; j < fin; j++) {

		if (tab[j] < pivot) {

			SWAP(&tab[i], &tab[j]);

			i++;
		}
	}
	SWAP(&tab[i], &tab[fin]);

	return i;
}

/*  ___________________________________________________________________________
	Nom	:			triRapide
	___________________________________________________________________________
	Description :  Cette procédure est une implémentation du tri rapide.

	___________________________________________________________________________
	Paramètres :      Un tableau d’entiers
					  Un entier qui correspond à l’indice de début.
					  Un entier qui correspond à l’indice de fin.
	___________________________________________________________________________
	Retour :		 aucun
	___________________________________________________________________________
	Test associé : Lorsque vous exécutez  triRapide_test fourni dans
				   ModuleTri_test, vous devez obtenir l’affichage suivant :

	triRapide_test: SUCCES

				 Valeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
			     Valeur obtenue  : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
	___________________________________________________________________________
*/
void triRapide(int tab[], int debut, int fin) {

	if (debut < fin) {

		int pivot = partitionner(tab, debut, fin);

		triRapide(tab, debut, pivot - 1);

		triRapide(tab, pivot + 1, fin);
	}
}

/*  ___________________________________________________________________________
	Nom	:			triIntrospection
	___________________________________________________________________________
	Description :  Cette procédure est une implémentation du tri par
	               introspection.
	___________________________________________________________________________
	Paramètres :      Un tableau d’entiers
					  Un entier qui correspond à la taille du tableau.
	___________________________________________________________________________
	Retour :		 aucun
	___________________________________________________________________________
	Test associé : Lorsque vous exécutez triIntrospection_test fournie dans                           
	               ModuleTri_test, vous devez obtenir l’affichage suivant :


	triRapide_test: SUCCES

				 Valeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
				 Valeur obtenue  : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]
	___________________________________________________________________________
*/
void triIntrospection(int tab[], int taille) {
	 
	int pivot = partitionner(tab, 0, taille-1);

	if (pivot < 15) {

		triInsertion(tab,taille);
	}
	else if (pivot > (2 * log2(taille))) {

		triTas(tab, taille);
	}
	else {

		triRapide(tab, 0, taille);
	}
}


/*  ___________________________________________________________________________
	Nom	:			swap
	___________________________________________________________________________
	Description :  Cette procédure permet de permuter des valeurs
	___________________________________________________________________________
	Paramètres :      Un entier qui correspond à la  première valeur
					  Un entier qui correspond à la  deuxième valeur
	___________________________________________________________________________
	Retour :		 aucun
	___________________________________________________________________________
*/
void SWAP(int* val1, int* val2) {

	int temp = 0;

	temp = *val1;

	*val1 = *val2;

	*val2 = temp;
}


/*  ___________________________________________________________________________
	Nom	:			triInsertion
	___________________________________________________________________________
	Description :  Cette procédure est une implémentation du tri par
	               introspection.
	___________________________________________________________________________
	Paramètres :      Un tableau d’entiers
					  Un entier qui correspond à la taille du tableau.
	___________________________________________________________________________
	Retour :		 aucun
	___________________________________________________________________________
*/
void triInsertion(int tab[], const int nb_elements)
{
	int j = 0;

	int cle = 0;
	for (int i = 1; i < nb_elements; ++i)
	{
		cle = tab[i];
		j = i - 1;
		while (cle < tab[j] && j >= 0)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = cle;
	}
}