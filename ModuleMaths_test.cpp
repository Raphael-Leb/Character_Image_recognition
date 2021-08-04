#include "ModuleMaths_test.h"

void degVersRad_test(void)
{
	double valeur_obtenue = degVersRad(180.0);
	double valeur_attendue = PI;

	if ((valeur_obtenue - valeur_attendue) < EPS)
	{
		printf("degVersRad_test: SUCCES\n\n");
	}
	else
	{
		printf("degVersRad_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : %.3f +/- %.3f\n", valeur_attendue, EPS);
	printf("\tValeur obtenue  : %.3f\n\n", valeur_obtenue);
}

void calculerDistanceEuclidienne_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img2 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	double valeur_obtenue;
	double valeur_attendue = 2873.548;

	chargerImageTest1(img1);
	chargerImageTest2(img2);

	valeur_obtenue = calculerDistanceEuclidienne(img1, img2);

	if ((valeur_obtenue - valeur_attendue) < EPS)
	{
		printf("calculerDistanceEuclidienne_test: SUCCES\n\n");
	}
	else
	{
		printf("calculerDistanceEuclidienne_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : %.3f +/- %.3f\n", valeur_attendue, EPS);
	printf("\tValeur obtenue  : %.3f\n\n", valeur_obtenue);

	// Libérer la mémoire
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img2, NB_PIXELS_HAUTEUR);

}

void calculerDistanceManhattan_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img2 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	double valeur_obtenue;
	double valeur_attendue = 39192.0;

	chargerImageTest1(img1);
	chargerImageTest2(img2);

	valeur_obtenue = calculerDistanceManhattan(img1, img2);

	if ((valeur_obtenue - valeur_attendue) < EPS)
	{
		printf("calculerDistanceManhattan_test: SUCCES\n\n");
	}
	else
	{
		printf("calculerDistanceManhattan_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : %.3f +/- %.3f\n", valeur_attendue, EPS);
	printf("\tValeur obtenue  : %.3f\n\n", valeur_obtenue);

	// Libérer la mémoire
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img2, NB_PIXELS_HAUTEUR);

}

void nombreAleatoireBinaire_test(void)
{
	double moyenne = 0.0;

	for (int i = 0; i < NB_ECHANTILLONS_ALEATOIRES; ++i)
	{
		moyenne += nombreAleatoireBinaire(UN_SUR_DEUX);
	}

	moyenne /= NB_ECHANTILLONS_ALEATOIRES;

	if (fabs(moyenne - 0.5) < EPS)
	{
		printf("test_nombreAleatoireBinaire: SUCCES\n\n");
	}
	else
	{
		printf("test_nombreAleatoireBinaire: ECHEC\n\n");
	}

	printf("\tValeur attendue : 0.500 +/- %.3f\n", EPS);
	printf("\tValeur obtenu   : %.3f\n\n", moyenne);

}