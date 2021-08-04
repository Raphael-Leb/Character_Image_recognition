     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleIntelligenceArtificielle.cpp        */
/*...................................................................*/
/*        Description    :  Ce module contient la fonction           */
/*                          kPlusProchesVoisins                      */
/*...................................................................*/
/*          Par    :        équipe 04                                */
/*...................................................................*/    //
/*          Date   : jeudi le 01 juillet  2021                       */   //
/*...................................................................*/  //
/*  Dernière modification : dimanche le 03 juillet  2021 08:31 P.M.  */ //
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




/*  ___________________________________________________________________________
	Nom	:			 kPlusProchesVoisins
	___________________________________________________________________________
	Description :	 Cette fonction implémente la méthode des 𝑘 plus proches
					 voisins.

	___________________________________________________________________________
	Paramètres :    Un entier qui correspond à la variable 𝑘
					(i.e. le nombre de voisins à considérer)

					Un tableau d’entiers 2D (en pointeur double) qui correspond
					à une image à classer.

					Un entier qui correspond au nombre de rangées de l’image.

					Un entier qui correspond au nombre de colonnes de l’image.

					Un tableau d’entiers 3D (en pointeur triple) qui correspond
					aux images d’entraînement.

					Un entier qui correspond au nombre d’images d’entraînement.

					Un tableau d’entiers 1D (en pointeur simple) qui correspond
					aux étiquettes des images d’entraînement.
	___________________________________________________________________________
	Retour :		Un entier qui correspond à l’étiquette prédit par
					l’algorithme.
	___________________________________________________________________________
	Réquis 1 :       Vous devez implémenter l’algorithme 1.
	kPlusProchesVoisins

	POUR chaque image du jeu de test
		 CALCULER la distance entre l’image courante et chacune des images
		 d’entraînement

		 TRIER les distances et les étiquettes correspondantes en ordre
		 croissant de distances

		 FIN POUR

	RETOURNER l’étiquette le plus fréquent pour les 𝑘 premiers étiquettes après
	le tri
	___________________________________________________________________________
	Test associé : N/A

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
int kPlusProchesVoisins(const int k,
	unsigned char** tab2D_img_a_classer,
	const int nb_rangees,
	const int nb_colonnes,
	unsigned char*** tab3D_img_train,
	const int nb_img_train,
	int* tab1D_etiquettes_img_train) {

	int i = 0;
	int j = 0;
	int compteur_img = 0; /*itérateur pour compter le nombre d'images*/
	int tabDistances[NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES] = { 0 };
	int taille = sizeof(tabDistances) / sizeof(int);
	int tabEtiquettes[K_VOISINS] = { 0 };

	int a_trouver_temp = 0;

	int result = 0; /*la valeur que la fonction retourne*/

	int frequence_etiquette[10] = { 0 };  // Permet de stocker le nombre 
	                                      //d'apparition de chaque etiquette 

	double distance_img_courante_img_train = 0; /*variable pour faire l'appel
												  à la fonction
												 calculerDistanceEuclidienne */
												 /*stratégie*/
												 /*implementer  l'algorithme no 1*/
	for (compteur_img = 0; compteur_img < nb_img_train; ++compteur_img) {

		/*on insère une image du jeu de test et on compte le nb fois que
		cette dernière fait apparition*/

		/*calculer la distance entre l'image courante et chacune des images
		d'entrainement, pour ce faire on fait appel  à la fonction
		calculerDistanceEuclidienne*/

		distance_img_courante_img_train = calculerDistanceEuclidienne(tab2D_img_a_classer,
			tab3D_img_train[compteur_img]);

		tabDistances[compteur_img] = (int)distance_img_courante_img_train;
	}
	/*trier les distances et les étiquettes correspondantes en ordre
	croissant de distances*/
	triIntrospection(tabDistances, taille);

	/*Faut reussir a trier les etiquettes. */
	for (int i = 0; i < K_VOISINS; ++i)
	{
		for (int j = 0; j < nb_img_train; ++j)
		{
			if (tabDistances[i] == (int)calculerDistanceEuclidienne(tab2D_img_a_classer, 
				tab3D_img_train[compteur_img]))
			{
				tabEtiquettes[i] = tab1D_etiquettes_img_train[j];
			}
		}
	}

	for (int compt_etiquettes = 0; compt_etiquettes <= 9; ++compt_etiquettes)
	{
		frequence_etiquette[compt_etiquettes] = compter_occurences(tabEtiquettes, 
			k, compt_etiquettes);
	}

	return result = ValeurMaxTableau(frequence_etiquette, 10);;
}
