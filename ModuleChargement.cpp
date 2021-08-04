#define _CRT_SECURE_NO_WARNINGS

#include "ModuleChargement.h"

void chargerMNIST(const    char*   nom_fichier,	/* Le nom du fichier                                */
				  const     int    nb_images,	/* Le nombre de lignes à lire dans le fichier CSV   */
				  unsigned char*** tableau,		/* Tableau 3D pour le stockage                      */
	                        int*   etiquettes)	/* Tableau 1D pour les étiquettes                   */
{
	
	/* Ouvrir le fichier */
	FILE* FID;
	FID = fopen(nom_fichier, "r");

	/* Itérateurs */
	int i = 0;
	int j = 0;
	int k = 0;
	
	/* Variable qui contient les lignes de texte */
	char ligne[CSVBUF];

	/* Tant qu'il y a du texte ET que l'itérateur i ne dépasse pas le nombre de lignes voulues */
	while (fgets(ligne, CSVBUF, FID) && (i <= nb_images))
	{

		// Ignorer la première ligne
		if (i == 0)
		{
			++i;
			continue;
		}

		/* Lire une ligne */
		char* tmp = _strdup(ligne);

		/* On réinitialise les itérateurs de rangées (j) et colonnes (k) */
		j = 0;
		k = 0;

		/* Conteneur de jeton (i.e. morceau de string) */
		char* jeton;

		for (jeton = strtok(ligne, ","); (k < NB_PIXELS_TOTAL + 1) && (jeton && *jeton) ; ++k, jeton = strtok(nullptr, ","))
		{

			// On stocke l'étiquette qui se trouve à la première ligne
			if (k == 0)
			{
				etiquettes[i - 1] = atoi(jeton);
				continue;
			}

			/* On stocke la prochaine valeur lue */
			tableau[i - 1][j][k % NB_PIXELS_LARGEUR] = atoi(jeton);

			if (k % NB_PIXELS_LARGEUR == 0)
			{
				++j;
			}

		}

		/* La mémoire réservée par strdup doit être libérée (voir: https://man7.org/linux/man-pages/man3/strdup.3.html ) */
		free(tmp);

		/* On incrémente le compteur d'images à chaque fin de ligne */
		i++;

	}
}