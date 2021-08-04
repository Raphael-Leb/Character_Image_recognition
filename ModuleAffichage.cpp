#include "ModuleAffichage.h"

void afficherImage(unsigned char** img)
{
	for (int i = 0; i < NB_PIXELS_HAUTEUR; ++i)
	{
		for (int j = 0; j < NB_PIXELS_LARGEUR; ++j)
		{
			if (img[i][j] > 0)
			{
				printf("%4i", img[i][j]);
			}
			else
			{
				printf("    ");
			}
		}
		printf("\n");
	}
}