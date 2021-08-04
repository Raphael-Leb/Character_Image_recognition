#include "ModuleImages_test.h"

/* Procédure de test pour la conversion d'images à niveaux de gris en image binaire */
void convertirImageVersBinaire_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_binaire = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	/* Charger l'image à niveaux de gris et la convertir en image binaire */
	chargerImageTest1(img1);

	convertirImageVersBinaire(img1, img_binaire);
	
	/* Afficher l'image transformée pour comparaison */
	afficherImage(img_binaire);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_binaire, NB_PIXELS_HAUTEUR);

}

/* Procédure de test pour la rotation d'images. */
void tournerImage_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_rot = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	
	/* Charger l'image de test no. 1 et la tourner de -20 degrés */
	chargerImageTest1(img1);

	tournerImage(img1, -20, img_rot);

	// Afficher l'image tournée
	afficherImage(img_rot);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_rot, NB_PIXELS_HAUTEUR);

}

/* Procédure de test pour le décalage d'images */
void decalerImage_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_decalee = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	/* Charger l'image de test no. 1 et la décaler de (+7,+7) unités */
	chargerImageTest1(img1);

	decalerImage(img1, 7, 7, img_decalee);

	/* Afficher l'image décalée */
	afficherImage(img_decalee);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_decalee, NB_PIXELS_HAUTEUR);

}

/* Procédure de test pour le cisaillement vertical d'images */
void cisaillerImageVertical_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_cisaillee = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	/* Charger l'image de test no. 1 et la décaler de 30 degrés */
	chargerImageTest1(img1);

	cisaillerImageVertical(img1, 70, img_cisaillee);

	/* Afficher l'image décalée */
	afficherImage(img_cisaillee);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_cisaillee, NB_PIXELS_HAUTEUR);

}

/* Procédure de test pour le cisaillement horizontal d'images */
void cisaillerImageHorizontal_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_cisaillee = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	/* Charger l'image de test no. 1 et la décaler de -30 degrés */
	chargerImageTest1(img1);

	cisaillerImageHorizontal(img1, -30, img_cisaillee);

	/* Afficher l'image décalée */
	afficherImage(img_cisaillee);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_cisaillee, NB_PIXELS_HAUTEUR);

}

/* Procédure de test pour le bruitage poivre et sel */
void bruitPoivreEtSel_test(void)
{

	unsigned char** img1 = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);
	unsigned char** img_bruitee = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	/* Charger l'image de test no. 1 et bruiter avec une probabilité de 1 (100%) */
	chargerImageTest1(img1);

	bruitPoivreEtSel(img1, 1, img_bruitee);

	/* Afficher l'image décalée */
	afficherImage(img_bruitee);

	/* Libérer la mémoire */
	supprimerTableau2D(img1, NB_PIXELS_HAUTEUR);
	supprimerTableau2D(img_bruitee, NB_PIXELS_HAUTEUR);

}