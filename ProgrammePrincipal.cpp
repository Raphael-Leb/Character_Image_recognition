#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ModuleAffichage.h"
#include "ModuleConstantes.h"
#include "ModuleImages.h"
#include "ModuleMaths.h"
#include "ModuleMaths_test.h"
#include "ModuleAffichage_test.h"
#include "ModuleImages_test.h"
#include "ModuleTableaux.h"
#include "ModuleTri.h"
#include "ModuleTri_test.h"
#include "ModuleIntelligenceArtificielle.h"

#define NB_IMAGES_ENTRAINEMENT 1000			/* Vous ne devez PAS modifier cette valeur */
#define NB_IMAGES_ARTIFICIELLES 50			/* Vous pouvez modifier cette valeur       */
#define NB_IMAGES_TEST 50                   /* Vous ne devez PAS modifier cette valeur */
#define K_VOISINS 2                         /* Vous pouvez modifier cette valeur       */

#define DEBUG TRUE                         /* Constante utilisée pour changer le mode d'exécution */

#if DEBUG == FALSE

int main(void)
{

	// Images
	unsigned char*** img_entrainement = nouveauTableau3D(NB_IMAGES_ENTRAINEMENT, 
		                                                 NB_PIXELS_HAUTEUR, 
		                                                 NB_PIXELS_LARGEUR);

	unsigned char*** img_entrainement_augmente = 
		             nouveauTableau3D(NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES, 
						              NB_PIXELS_HAUTEUR, 
						              NB_PIXELS_LARGEUR);

	unsigned char*** img_test = nouveauTableau3D(NB_IMAGES_ENTRAINEMENT, 
		                                         NB_PIXELS_HAUTEUR, 
		                                         NB_PIXELS_LARGEUR);

	// Étiquettes
	int etiquettes_entrainement[NB_IMAGES_ENTRAINEMENT];
	int etiquettes_entrainement_augmente[NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES];
	int etiquettes_test[NB_IMAGES_TEST];

	// Charger les données et les étiquettes
	chargerMNIST("mnist_train.csv", 
		         NB_IMAGES_ENTRAINEMENT, 
		         img_entrainement, 
		         etiquettes_entrainement);

	chargerMNIST("mnist_train.csv", 
		         NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES, 
		         img_entrainement_augmente, 
		         etiquettes_entrainement_augmente);
	
	chargerMNIST("mnist_test.csv", 
		         NB_IMAGES_TEST, 
		         img_test, 
		         etiquettes_test);

	// Augmenter les données
	augmenterDonnees(img_entrainement_augmente, 
		             etiquettes_entrainement_augmente, 
		             NB_IMAGES_ENTRAINEMENT, 
		             NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES - 1);

	// Calcul de la précision
	double precision_sans_aug = 0.0;
	double precision_avec_aug = 0.0;

	for (int i = 0; i < NB_IMAGES_TEST; ++i)
	{

		// Sans augmentation
		if (etiquettes_test[i] == kPlusProchesVoisins(K_VOISINS, 
			                                          img_test[i], 
			                                          NB_PIXELS_HAUTEUR, 
			                                          NB_PIXELS_LARGEUR, 
			                                          img_entrainement, 
			                                          NB_IMAGES_ENTRAINEMENT, 
			                                          etiquettes_entrainement))
		{
			precision_sans_aug += 1.0;
		}

		// Avec augmentation
		if (etiquettes_test[i] == kPlusProchesVoisins(K_VOISINS,
													  img_test[i],
													  NB_PIXELS_HAUTEUR,
													  NB_PIXELS_LARGEUR,
													  img_entrainement_augmente,
													  NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES,
													  etiquettes_entrainement_augmente))
		{
			precision_avec_aug += 1.0;
		}

	}
	
	precision_sans_aug /= NB_IMAGES_TEST;
	precision_avec_aug /= NB_IMAGES_TEST;

	// Afficher résultats
	printf("Precision sans augmentation = %.4f%\n", precision_sans_aug);
	printf("Precision avec augmentation = %.4f%\n", precision_avec_aug);

	// Libérer la mémoire
	supprimerTableau3D(img_entrainement, 
		               NB_PIXELS_HAUTEUR, 
		               NB_IMAGES_ENTRAINEMENT);

	supprimerTableau3D(img_entrainement_augmente, 
		               NB_PIXELS_HAUTEUR, 
		               NB_IMAGES_ENTRAINEMENT + NB_IMAGES_ARTIFICIELLES);
	
	supprimerTableau3D(img_test, 
		               NB_PIXELS_HAUTEUR, 
		               NB_IMAGES_TEST);

	system("pause");
	return EXIT_SUCCESS;

	}

#elif DEBUG == TRUE

	int main(void)
	{

		printf("MODULE MATHS\n\n");

		/* Procédure de test pour la conversion de degrés en radians */
		degVersRad_test();

		/* Procédure de test pour le calcul de la distance euclidienne entre deux images */
		calculerDistanceEuclidienne_test();

		/* Procédure de test pour le calcul de la distance de Manhattan entre deux images */
		calculerDistanceManhattan_test();

		/* Proc/dure de test pour la génération de nombres aléatoires binaires */
		nombreAleatoireBinaire_test();

		printf("\nMODULE AFFICHAGE\n\n");

		/* Procédure de test pour l'affichage d'une image */
		afficherImage_test();

		printf("\nMODULE IMAGES\n\n");

		printf("IMAGE BINAIRE\n");

		/* Procédure de test pour la conversion d'images à niveaux de gris en image binaire. */
		convertirImageVersBinaire_test();

		printf("\n\nIMAGE TOURNEE\n");

		/* Procédure de test pour la rotation d'images. */
		tournerImage_test();

		printf("\n\nIMAGE DECALEE\n");

		/* Procédure de test pour le décalage d'images. */
		decalerImage_test();

		printf("\n\nIMAGE CISAILLEE VERTICAL\n");

		/* Procédure de test pour le cisaillement vertical d'images. */
		cisaillerImageVertical_test();

		printf("\n\nIMAGE CISAILLEE HORIZONTAL\n");

		/* Procédure de test pour le cisaillement horizontal d'images. */
		cisaillerImageHorizontal_test();

		printf("\n\nIMAGE BRUITEE\n");

		/* Procédure de test pour le bruitage poivre et sel. */
		bruitPoivreEtSel_test();

		printf("\n\nMODULE TRI\n\n");

		/* Procédure de test pour le tamisage */
		tamiser_test();

		printf("\n");

		/* Procédure de test pour le tri par tas */
		triTas_test();

		printf("\n");

		/* Procédure de test pour le partitionnement */
		partitionner_test();

		printf("\n");

		/* Procédure de test pour le tri rapide */
		triRapide_test();

		printf("\n");

		/* Procédure de test pour le tri par introspection */
		triIntrospection_test();

		printf("\n");

		system("pause");
		return EXIT_SUCCESS;
	}

#endif