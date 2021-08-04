     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleImages.cpp                          */
/*...................................................................*/
/*          Par    :        équipe 04                                */
/*...................................................................*/    //
/*          Date   : mardi le 15 juin le 2021                        */   //
/*...................................................................*/  //
/*    Dernière modification : dimanche le 04 juillet  2021 07:17 P.M */ //
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

/*  ___________________________________________________________________________
	Nom	:			 convertirImageVersBinaire
	___________________________________________________________________________
	Description :	Cette fonction fait la conversion d’une image à niveaux de
					gris [0,255] en image binaire [0,1].

	___________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à une image

					Un tableau de caractères vide qui correspond à la version
					binaire de l’image.

	___________________________________________________________________________
	Retour :		  Aucun.
	___________________________________________________________________________
	Test associé :  N/A
	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void convertirImageVersBinaire(unsigned char** img,
	unsigned char** copie)
{
	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{
		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{
			if (img[i][j] > 0)
			{
				copie[i][j] = 1;
			}
			else
			{
				copie[i][j] = 0;
			}
		}
	}
}


/*  ___________________________________________________________________________
	Nom	:			 tournerImage
	___________________________________________________________________________
	Description :	Cette fonction tourne une image d’un angle donné en radians.

	___________________________________________________________________________
	Paramètres :    Un tableau de caractères qui correspond à une image à
					faire tourner.

					Un double qui correspond à un angle en degrés.

					Un tableau de caractères qui correspond à la version
					tournée de l’image
	___________________________________________________________________________
	Retour :		  Aucun
	___________________________________________________________________________
	Réquis 1 :       La fonction doit implémenter la transformation suivante :

					 𝑥∗ =  𝑥 cos 𝜃 + 𝑦 sin 𝜃


					 𝑦∗ = −𝑥 sin 𝜃 + 𝑦 cos 𝜃


					 En mots, cette transformation déplace le pixel à la
					 position (𝑥, 𝑦) de l’image originale à la position
					  (𝑥∗ ; 𝑦∗) de l’image transformée.
	___________________________________________________________________________
	Requis 2 :     La fonction doit ignorer les pixels qui sont déplacés à
				   l’extérieur de l’image originale.
	___________________________________________________________________________
	Test associé : N/A

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void tournerImage(unsigned char** img,
	const double   angle_degres,
	unsigned char** img_tournee)
{

	unsigned int i_prime = 0;
	unsigned int j_prime = 0;
	const double angle_radians = degVersRad(angle_degres);

	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{

		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{

			i_prime = (unsigned int)(i * cos(angle_radians) + j * sin(angle_radians));
			j_prime = (unsigned int)(-i * sin(angle_radians) + j * cos(angle_radians));

			if (i_prime >= 0 && j_prime >= 0 && i_prime < NB_PIXELS_HAUTEUR && j_prime < NB_PIXELS_LARGEUR)
			{
				img_tournee[i_prime][j_prime] = img[i][j];
			}
		}
	}

}


/*  ___________________________________________________________________________
	Nom	:			 decalerImage
	___________________________________________________________________________
	Description :	Cette fonction applique des décalages linéaires (horizontal
					et/ou vertical) à une image
	___________________________________________________________________________
	Paramètres :    Un tableau de caractères qui correspond à une image à
					décaler.

					Un entier qui correspond au décalage horizontal.

					Un entier qui correspond au décalage vertical.

					Un tableau de caractères qui correspond à l’image décalée.
	___________________________________________________________________________
	Retour :		  Aucun.

	___________________________________________________________________________
	Réquis 1 :      Un décalage horizontal positif doit correspondre à un
					décalage vers la droite.
	___________________________________________________________________________
	Requis 2 :      Un décalage vertical positif doit correspondre à un décalage
					vers le bas.
	___________________________________________________________________________
	Test associé : N/A

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void decalerImage(unsigned char** img,
	const int   decalage_horizontal,
	const int   decalage_vertical,
	unsigned char** img_decalee)
{

	int i_prime = 0;
	int j_prime = 0;

	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{

		i_prime = i + decalage_vertical;

		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{

			j_prime = j + decalage_horizontal;

			if (i_prime >= 0 && i_prime < NB_PIXELS_HAUTEUR && j_prime >= 0 && j_prime < NB_PIXELS_LARGEUR)
			{
				img_decalee[i_prime][j_prime] = img[i][j];
			}

		}
	}

}



/*  ___________________________________________________________________________
	Nom	:			CisaillerImageVertical
	___________________________________________________________________________
	Description :	  Cette fonction applique un cisaillement vertical à une
					  image.
	___________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à l’image à
					cisailler.

					Un double qui correspont à l’angle de cisaillement.


					Un tableau de caractères qui correspond à l’image cisaillée

	___________________________________________________________________________
	Retour :		  Aucun.

	___________________________________________________________________________
	Réquis 1 :       La fonction doit implémenter la transformation suivante :

					 𝑥∗ = 𝑥 − 𝑦 tan(𝜃/2)

					 𝑦∗ = 𝑦

					 En mots, cette transformation déplace le pixel à la
					 position (𝑥, 𝑦) de l’image originale à la position
					  (𝑥∗ ; 𝑦∗) de l’image transformée.



	___________________________________________________________________________
	Requis 2 :      La fonction doit ignorer les pixels qui sont déplacés
					à l’extérieur de l’image originale.


	___________________________________________________________________________
	Test associé :  Lorsque vous exécutez cisaillerImageVertical_test fournie
					dans ModuleImages_test, vous devez observer la figure
					suivante :

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void cisaillerImageVertical(unsigned char** img,
	const double   angle_cisaillement,
	unsigned char** img_cisaillee)
{
	int i_prime = 0;
	int j_prime = 0;

	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{

		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{

			i_prime = (unsigned int)(i - tan(degVersRad(angle_cisaillement) / 2.0) * j);

			if (i_prime >= 0 && i_prime < NB_PIXELS_HAUTEUR)
			{
				img_cisaillee[i_prime][j] = img[i][j];
			}


		}
	}
}

/*  ___________________________________________________________________________
	Nom	:			CisaillerImageHorizontale
	___________________________________________________________________________
	Description :	  Cette fonction applique un cisaillement horizontale à une
					  image.
	___________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à l’image à
					cisailler.

					Un double qui correspont à l’angle de cisaillement.


					Un tableau de caractères qui correspond à l’image cisaillée

	___________________________________________________________________________
	Retour :		  Aucun.

	___________________________________________________________________________
	Réquis 1 :       La fonction doit implémenter la transformation suivante :

					 𝑥∗ = 𝑥

					 𝑦∗ = 𝑥 sin 𝜃 + 𝑥

					 En mots, cette transformation déplace le pixel à la
					 position (𝑥, 𝑦) de l’image originale à la position
					  (𝑥∗ ; 𝑦∗) de l’image transformée.



	___________________________________________________________________________
	Requis 2 :      La fonction doit ignorer les pixels qui sont déplacés
					à l’extérieur de l’image originale.


	___________________________________________________________________________
	Test associé :  Lorsque vous exécutez cisaillerImageHorizontale_test
					fournie
					dans ModuleImages_test, vous devez observer la figure
					suivante :

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void cisaillerImageHorizontal(unsigned char** img,
	const double   angle_cisaillement,
	unsigned char** img_cisaillee)
{
	int i_prime = 0;
	int j_prime = 0;

	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{

		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{

			j_prime = (unsigned int)(sin(degVersRad(angle_cisaillement)) * i + j);

			if (j_prime >= 0 && j_prime < NB_PIXELS_LARGEUR)
			{
				img_cisaillee[i][j_prime] = img[i][j];
			}

		}
	}
}

/*  ___________________________________________________________________________
	Nom	:			calculerDistanceEuclidienne
	___________________________________________________________________________
	Description :	 Cette fonction calcule la distance euclidienne entre deux
					 images.
	___________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à la première image.


					Un tableau de caractères qui correspond à la deuxième image

	___________________________________________________________________________
	Retour :		  Un double qui correspond à la distance euclidienne.

	___________________________________________________________________________
	Réquis 1 :       La fonction doit l’équation suivante :


					𝑑(𝒂, 𝒃) = √∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)^2
							   𝑖,𝑗

	Dans cette équation 𝑎𝑖𝑗 représente l’élément de la 𝑖-ème ligne de la 𝑗-ème
	colonne de la l’image 𝒂. Le même raisonnement s’applique pour 𝑏  .
																   𝑖𝑗
	___________________________________________________________________________
	Test associé : N/A

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
double calculerDistanceEuclidienne(unsigned char** img1,
	unsigned char** img2)
{

	/*variables locales*/
	double sommation = 0.0;
	double somme_ij = 0.0;

	/*stratégie*/
	//on parcours les lignes
	for (int lig = 0; lig < NB_PIXELS_HAUTEUR; ++lig)
	{
		//on parcours les colonnes
		for (int col = 0; col < NB_PIXELS_LARGEUR; ++col)
		{
			//soustraction de la position de l'image 1 moins la position
			// de l'image 2
			//∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)

			//somme_ij = (double)img1[lig][col] - (double)img2[lig][col];
			somme_ij = (double)*(*(img1 + col) + lig) - (double)*(*(img2 + col) + lig);

			//racine carrée des positions
			//  𝑑(𝒂, 𝒃) = √∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)^2
			//   𝑖,𝑗
			somme_ij = pow(somme_ij, 2);


			//on additionne
			sommation += somme_ij;
		}
	}

	//on retourne la racine carrée de la sommation
	return sqrt(sommation);
}


/*  ___________________________________________________________________________
	Nom	:			calculerDistanceManhattan
	___________________________________________________________________________
	Description :	Cette fonction calcule la distance de Manhattan entre
					deux images.
	___________________________________________________________________________
	Paramètres :	 Un tableau de caractères qui correspond à la première
					 image.

					 Un tableau de caractères qui correspond à la deuxième
					 image.

	___________________________________________________________________________
	Retour :		 Un double qui correspond à la distance de Manhattan

	___________________________________________________________________________
	Réquis 1 :        La fonction doit l’équation suivante :


					𝑑(𝒂, 𝒃) = ∑|𝑎𝑖𝑗 − 𝑏𝑖𝑗|
							  𝑖,𝑗

					   Dans cette équation 𝑎𝑖𝑗 représente l’élément de la 𝑖-ème
					   ligne de la 𝑗-ème colonne de la l’image 𝒂. Le même
					   raisonnement s’applique pour 𝑏𝑖𝑗.



	___________________________________________________________________________
	Requis 2 :      La fonction doit ignorer les pixels qui sont déplacés
					à l’extérieur de l’image originale.


	___________________________________________________________________________
	Test associé :  Vous devez écrire une procédure de test qui calcule la
					distance de Manhattan entre l’image de test 1 et l’image
					de test 2. Le test doit répliquer l’affichage suivant :

					CalculerDistanceManhattan_test: SUCCES

						   Valeur attendue : 39192.000 +/- 0.001
						   Valeur obtenue  : 39192.000




	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
double calculerDistanceManhattan(unsigned char img1[NB_PIXELS_HAUTEUR][NB_PIXELS_LARGEUR],
	unsigned char img2[NB_PIXELS_HAUTEUR][NB_PIXELS_LARGEUR]) {

	//int i, j;
	int i = 0;
	int j = 0;

	double distance = 0;

	/*stratégie*/
	//Parcourir l'image entrante
	for (i = 0; i < NB_PIXELS_HAUTEUR; i++) {

		for (j = 0; j < NB_PIXELS_LARGEUR; j++) {


			//soustraction en valeur absolue de la position de l'image 1 moins 
			// la position de l'image 2
			distance += fabs(img1[i][j] - img2[i][j]);
		}

	}

	//on retourne la distance
	return distance;

}

/*  ___________________________________________________________________________
	Nom	:			bruitPoivreEtSel
	____________________________________________________________________________
	Description :	Cette fonction applique du bruit poivre et sel à une image.
	____________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à l’image à bruiter

					Un double qui correspond à la probabilité de bruitage d’un
					pixel.

					Un tableau de caractères qui correspond à l’image bruitée.


	___________________________________________________________________________
	Retour :		 Aucun

	___________________________________________________________________________
	Réquis 1 :       La fonction doit utiliser le sous-programme 10
					 (nombreAleatoireBinaire).
	___________________________________________________________________________
	Requis 2 :     La fonction doit ignorer les pixels vides.

	___________________________________________________________________________
	Test associé : N/A
	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
void bruitPoivreEtSel(unsigned char** img,
	const double   prob,
	unsigned char** img_bruitee)
{
	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{
		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{
			if (nombreAleatoireBinaire(prob) == TRUE && img[i][j] != 0)
			{
				if (nombreAleatoireBinaire(UN_SUR_DEUX) == TRUE)
				{
					img_bruitee[i][j] = 0;
				}
				else
				{
					img_bruitee[i][j] = 255;
				}
			}
			else
			{
				img_bruitee[i][j] = img[i][j];
			}
		}
	}
}


/*  ___________________________________________________________________________
	Nom	:			calculerDistanceEuclidienne
	___________________________________________________________________________
	Description :	 Cette fonction calcule la distance euclidienne entre deux
					 images.
	___________________________________________________________________________
	Paramètres :	Un tableau de caractères qui correspond à la première image.


					Un tableau de caractères qui correspond à la deuxième image

	___________________________________________________________________________
	Retour :		  Un double qui correspond à la distance euclidienne.

	___________________________________________________________________________
	Réquis 1 :       La fonction doit l’équation suivante :


					𝑑(𝒂, 𝒃) = √∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)^2
							   𝑖,𝑗

	Dans cette équation 𝑎𝑖𝑗 représente l’élément de la 𝑖-ème ligne de la 𝑗-ème
	colonne de la l’image 𝒂. Le même raisonnement s’applique pour 𝑏  .
																   𝑖𝑗
	___________________________________________________________________________
	Test associé : N/A

	___________________________________________________________________________
	Spécification : N/A
	___________________________________________________________________________
*/
double calculerDistanceEuclidienne(unsigned char** img1,
	unsigned char** img2)
{

	/*variables locales*/
	double sommation = 0.0;
	double somme_ij = 0.0;

	/*stratégie*/
	//on parcours les lignes
	for (int lig = 0; lig < NB_PIXELS_HAUTEUR; ++lig)
	{
		//on parcours les colonnes
		for (int col = 0; col < NB_PIXELS_LARGEUR; ++col)
		{
			//soustraction de la position de l'image 1 moins la position
			// de l'image 2
			//∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)

			//somme_ij = (double)img1[lig][col] - (double)img2[lig][col];
			somme_ij = (double)*(*(img1 + col) + lig) - (double)*(*(img2 + col) + lig);

			//racine carrée des positions
			//  𝑑(𝒂, 𝒃) = √∑(𝑎𝑖𝑗 − 𝑏𝑖𝑗)^2
			//   𝑖,𝑗
			somme_ij = pow(somme_ij, 2);


			//on additionne
			sommation += somme_ij;
		}
	}

	//on retourne la racine carrée de la sommation
	return sqrt(sommation);
}

/*  ___________________________________________________________________________
	Nom	:			augmenterDonnees
	____________________________________________________________________________
	Description :	 Cette procédure ajoute des images artificielles créées par
	                 les algorithmes de la partie 1.
	____________________________________________________________________________
	Paramètres :	 Un tableau d’entiers 3D (en pointeur triple) qui
	                 correspond  aux images d’entraînement.
	                
					 Un tableau d’entiers 1D (en pointeur simple) qui
					 correspond aux étiquettes des images d’entraînement.

					 Un entier qui correspond à un indice de départ.

					 Un entier qui correspond à un indice de fin.
	___________________________________________________________________________
	Retour :		 Un entier qui correspond à l’étiquette prédit par
	                 l’algorithme.
	___________________________________________________________________________
	Réquis 1 :      Votre devez créer une procédure qui génère des images 
	                artificielles dérivées des images originales à partir des
					algorithmes de la partie 1. Vous êtes libres de choisir les
					transformations utilisées et les paramètres de ces 
					transformations (p.	ex. l’angle de rotation, l’angle de 
					cisaillement, le décalage horizontal, etc.). Vous devez
					aussi stocker les étiquettes de ces images artificielles
					dans la deuxième entrée. Votre objectif est de créer une 
					procédure qui améliore la précision de l’algorithme de 
					classification d’au moins 2% par rapport à une précision 
					minimale  de 80%, donc 82% avec augmentation. Les fonctions
					qui génèrent des nombres aléatoires peuvent être utiles.
	___________________________________________________________________________
	Notes :         Si vous voulez ajouter 500 images artificielles 28 par 28 à 
	                un tableau de 1000 images. Vous devez passer un tableau 3D
					dont les dimensions sont 1500 par 28 par 28. L’indice de
					début est donc 1000 et l’indice de fin est 1499.

	___________________________________________________________________________
*/
void augmenterDonnees(unsigned char*** tab3D_img_train_aug,
	int* tab1D_etiquettes_img_train_aug,
	const int depart,
	const int fin)
{
	double choix_procedure = 0.0;
	double parametre_aleatoire_1 = 0.0;
	double parametre_aleatoire_2 = 0.0;
	for (int i = 0; depart + i <= fin; ++i)
	{
		// On utilise un nombre aleatoire pour choisir la procedure qui donnera
		//la nouvelle image d'entrainement.
		choix_procedure = nombreAleatoireEntreBornes(0.0, 100.0);

		// Convertir en image binaire
		if (choix_procedure <= 16.6)
		{
			convertirImageVersBinaire(tab3D_img_train_aug[i],
				tab3D_img_train_aug[depart + i]);
		}
		// Tourner l'image
		else if (choix_procedure > 16.6 && choix_procedure <= 33.3)
		{
			// On limite la rotation de 5 a 30 degrees, afin de ne pas fausser
			//les resultat.
			parametre_aleatoire_1 = nombreAleatoireEntreBornes(5, 30.0);
			// On donne 50% de chance que le parametre soit negatif
			if (nombreAleatoireBinaire(0.5) == 1)
			{
				parametre_aleatoire_1 *= -1;
			}
			tournerImage(tab3D_img_train_aug[i], parametre_aleatoire_1, 
				tab3D_img_train_aug[depart + i]);
		}
		// Decaler l'image
		else if (choix_procedure > 33.3 && choix_procedure <= 50)
		{
			// On limite le decalage de 1 a 8 colonne / rangee, afin d'eviter 
			//de trop perdre d'information sur l'image

			parametre_aleatoire_1 = (int)nombreAleatoireEntreBornes(1, 8);

			parametre_aleatoire_2 = (int)nombreAleatoireEntreBornes(1, 8);

			// On donne 50% de chance que le parametre soit negatif
			if (nombreAleatoireBinaire(0.5) == 1)
			{
				parametre_aleatoire_1 *= -1;
			}
			if (nombreAleatoireBinaire(0.5) == 1)
			{
				parametre_aleatoire_2 *= -1;
			}
			decalerImage(tab3D_img_train_aug[i], parametre_aleatoire_1,
				parametre_aleatoire_2, tab3D_img_train_aug[depart + i]);
		}
		// Cisailler l'image verticalement
		else if (choix_procedure > 50 && choix_procedure <= 66.6)
		{
			// On limite le cisaillement de 5 a 25 degree pour ne pas trop
			//deformer l'image.

			parametre_aleatoire_1 = nombreAleatoireEntreBornes(5, 25);
			// On donne 50% de chance que le parametre soit negatif
			if (nombreAleatoireBinaire(0.5) == 1)
			{
				parametre_aleatoire_1 *= -1;
			}
			cisaillerImageVertical(tab3D_img_train_aug[i], parametre_aleatoire_1, 
				tab3D_img_train_aug[depart + i]);
		}
		// Cisailler l'image horizontalement
		else if (choix_procedure > 66.6 && choix_procedure <= 83.3)
		{
			// On limite le cisaillement de 5 a 25 degree pour ne pas trop 
			//deformer l'image.
			parametre_aleatoire_1 = nombreAleatoireEntreBornes(5, 25);
			// On donne 50% de chance que le parametre soit negatif
			if (nombreAleatoireBinaire(0.5) == 1)
			{
				parametre_aleatoire_1 *= -1;
			}
			cisaillerImageHorizontal(tab3D_img_train_aug[i], parametre_aleatoire_1, 
				tab3D_img_train_aug[depart + i]);
		}
		// Ajouter un bruit sel et poivre
		else if (choix_procedure > 83.3)
		{
			// On donne de 10 a 30 % 
			parametre_aleatoire_1 = nombreAleatoireEntreBornes(10, 30);
			bruitPoivreEtSel(tab3D_img_train_aug[i], parametre_aleatoire_1,
				tab3D_img_train_aug[depart + i]);
		}
	}
}