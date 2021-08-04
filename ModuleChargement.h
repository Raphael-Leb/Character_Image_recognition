#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ModuleConstantes.h"

/* Fonction qui fait la lecture d'un fichier CSV et qui stocke les valeurs dans un tableau 2D */
void chargerMNIST(const    char*   filename,
				  const     int    nb_images,
				  unsigned char*** tableau,
					        int*   etiquettes);
