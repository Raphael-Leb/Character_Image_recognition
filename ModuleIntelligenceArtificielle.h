#pragma once
     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleIntelligenceArtificielle.h          */
/*...................................................................*/
/*        Description    :  Ce module contient la déclaration du     */
/*                 prototype de la fonction  kPlusProchesVoisins     */
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
	int* tab1D_etiquettes_img_train);

