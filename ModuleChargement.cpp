#define _CRT_SECURE_NO_WARNINGS

#include "ModuleChargement.h"

void chargerMNIST(const    char*   nom_fichier,	/* Le nom du fichier                                */
				  const     int    nb_images,	/* Le nombre de lignes � lire dans le fichier CSV   */
				  unsigned char*** tableau,		/* Tableau 3D pour le stockage                      */
	                        int*   etiquettes)	/* Tableau 1D pour les �tiquettes                   */
{
	
	/* Ouvrir le fichier */
	FILE* FID;
	FID = fopen(nom_fichier, "r");

	/* It�rateurs */
	int i = 0;
	int j = 0;
	int k = 0;
	
	/* Variable qui contient les lignes de texte */
	char ligne[CSVBUF];

	/* Tant qu'il y a du texte ET que l'it�rateur i ne d�passe pas le nombre de lignes voulues */
	while (fgets(ligne, CSVBUF, FID) && (i <= nb_images))
	{

		// Ignorer la premi�re ligne
		if (i == 0)
		{
			++i;
			continue;
		}

		/* Lire une ligne */
		char* tmp = _strdup(ligne);

		/* On r�initialise les it�rateurs de rang�es (j) et colonnes (k) */
		j = 0;
		k = 0;

		/* Conteneur de jeton (i.e. morceau de string) */
		char* jeton;

		for (jeton = strtok(ligne, ","); (k < NB_PIXELS_TOTAL + 1) && (jeton && *jeton) ; ++k, jeton = strtok(nullptr, ","))
		{

			// On stocke l'�tiquette qui se trouve � la premi�re ligne
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

		/* La m�moire r�serv�e par strdup doit �tre lib�r�e (voir: https://man7.org/linux/man-pages/man3/strdup.3.html ) */
		free(tmp);

		/* On incr�mente le compteur d'images � chaque fin de ligne */
		i++;

	}
}