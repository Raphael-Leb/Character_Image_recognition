#include "ModuleTableaux.h"

unsigned char*** nouveauTableau3D(const int dim1, const int dim2, const int dim3)
{

	// [1] Tableau de pointeurs doubles (i.e. tableau de tableaux 2D) -> TABLEAU 3D
	unsigned char*** tab = (unsigned char***)calloc(dim1, sizeof(unsigned char**));

	// Valider l'allocation de mémoire
	MALLOC_ERROR(tab);

	// Pour chaque image
	for (int i = 0; i < dim1; ++i)
	{

		// [2] Tableau de pointeurs simples (i.e. tableau de tableaux 1D) -> TABLEAU 2D
		tab[i] = (unsigned char**)calloc(dim2, sizeof(unsigned char*));

		// Valider l'allocation de mémoire
		MALLOC_ERROR(tab[i]);

		// [3] Tableau d'entiers -> TABLEAU 1D
		for (int j = 0; j < dim2; ++j)
		{
			// Allocation de mémoire pour chaque rangée du tableau 2D
			tab[i][j] = (unsigned char*)calloc(dim3, sizeof(unsigned char));

			// Valider l'allocation de mémoire
			MALLOC_ERROR(tab[i][j]);

		}

	}

	return tab;

}

// NOTE: Les avertissement C6385/C6386 peuvent être ignorés, car l'analyseur de code tente de prévenir un 
//       débordement puisqu'il ne connaît pas la valaeur de dim1, dim2 et dim3. Si vous remplacez ces 
//       valeurs par des constantes, ce message disparaît.

unsigned char** nouveauTableau2D(const int dim1, const int dim2)
{

	// [1] Tableau de pointeurs simples (i.e. tableau de tableaux 1D) -> TABLEAU 2D
	unsigned char** tab = (unsigned char**)calloc(dim1, sizeof(unsigned char*));

	// Valider l'allocation de mémoire
	MALLOC_ERROR(tab);

	// [2] Tableau d'entiers -> TABLEAU 1D
	for (int i = 0; i < dim1; ++i)
	{
		// Allocation de mémoire pour chaque rangée du tableau 2D
		tab[i] = (unsigned char*)calloc(dim2, sizeof(unsigned char));

		// Valider l'allocation de mémoire
		MALLOC_ERROR(tab[i]);

	}

	return tab;

}

int* nouveauTableau1D(const int nb_elements)
{
	int* tableau = (int*)calloc(nb_elements, sizeof(double));

	// Valider l'allocation de mémoire
	MALLOC_ERROR(tableau);

	return tableau;
}

// NOTE: Les avertissement C6385/C6386 peuvent être ignorés, car l'analyseur de code tente de prévenir un 
//       débordement puisqu'il ne connaît pas la valaeur de dim1, dim2 et dim3. Si vous remplacez ces 
//       valeurs par des constantes, ce message disparaît.

void supprimerTableau3D(unsigned char*** tableau, const int nb_rangees, const int nb_tableaux_2D)
{

	for (int i = 0; i < nb_tableaux_2D; ++i)
	{
		for (int j = 0; j < nb_rangees; ++j) 
		{
			free(tableau[i][j]);
		}
		free(tableau[i]);
	}

	free(tableau);

}

void supprimerTableau2D(unsigned char** tableau, const int nb_rangees)
{

	for (int i = 0; i < nb_rangees; i++) {
		free(tableau[i]);
	}

	free(tableau);

}

void supprimerTableau1D(int* tableau)
{
	free(tableau);
}

void copierTableau1D(int* tab_source, int* tab_destination, const int nb_elements)
{
	
	for (int i = 0; i < nb_elements; ++i)
	{
		tab_destination[i] = tab_source[i];
	}

}