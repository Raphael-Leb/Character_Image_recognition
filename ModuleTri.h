#pragma once
#include <stdio.h>
#include <math.h>
#include "ModuleConstantes.h"

void SWAP(int *val1, int *val2);

void triInsertion(int tab[], const int nb_elements);

/*Proc�dure de tamisage qui sert � repr�senter un tableau 1D en tas max*/
void tamiser(int tab[], int taille);

/*Cette proc�dure est une impl�mentation du tri par tas.*/
void triTas(int tab[], int taille);

/* Cette fonction partitionne un sous-ensemble d�un tableau.*/
int partitionner(int tab[], int debut, int fin);

/*Cette proc�dure est une impl�mentation du tri rapide.*/
void triRapide(int tab[], int debut, int fin);

/*Cette proc�dure est une impl�mentation du tri par introspection.*/
void triIntrospection(int tab[], int taille);