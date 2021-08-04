//#pragma once

#include <stdio.h>
#include <stdlib.h>

// Macro qui affiche un message d'erreur quand l'allocation de m�moire �choue
#define MALLOC_ERROR(val)	{\
								if (val == nullptr)\
								{\
									fprintf(stderr, "Memoire insuffisante");\
									exit(EXIT_FAILURE);\
								}\
							}

// Fonction qui fait la lecture d'un fichier CSV et qui stocke les valeurs dans un tableau 2D
void chargerMNIST(const    char* filename,
	const     int    nb_images,
	unsigned char*** tableau,
	int* etiquettes);

// Fonction qui d�clare un tableau 3D dynamique de caract�res non sign�s
unsigned char*** nouveauTableau3D(const int dim1, const int dim2, const int dim3);

// Fonction qui d�clare un tableau 2D dynamique de caract�res non sign�s
unsigned char** nouveauTableau2D(const int dim1, const int dim2);

// Fonction qui d�clare un tableau 1D dynamique de caract�res non sign�s
int* nouveauTableau1D(const int nb_elements);

// Fonction qui lib�re la m�moire d'un tableau 3D dynamique de caract�res non sign�s
void supprimerTableau3D(unsigned char*** tableau, const int nb_rangees, const int nb_tableaux_2D);

// Fonction qui lib�re la m�moire d'un tableau 2D dynamique de caract�res non sign�s
void supprimerTableau2D(unsigned char** tableau, const int nb_rangees);

// Fonction qui lib�re la m�moire d'un tableau 1D dynamique de caract�res non sign�s
void supprimerTableau1D(int* tableau);

// Fonction qui copie un tableau 1D d'entiers
void copierTableau1D(int* tab_source, int* tab_destination, const int nb_elements);
