#include "ModuleAffichage_test.h"

void afficherImage_test(void)
{

	/* Charger l'image de test */
	unsigned char** img = nouveauTableau2D(NB_PIXELS_HAUTEUR, NB_PIXELS_LARGEUR);

	chargerImageTest1(img);

	/* Afficher l'image pour comparaison */
	afficherImage(img);

	/* Lib�rer la m�moire */
	supprimerTableau2D(img, NB_PIXELS_HAUTEUR);

}
