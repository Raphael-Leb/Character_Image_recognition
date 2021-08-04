#pragma once

#include <stdio.h>
#include <math.h>

#include "ModuleConstantes.h"
#include "ModuleTests.h"
#include "ModuleMaths.h"
#include "ModuleTableaux.h"

/* Procédure de test pour la conversion de degrés en radians */
void degVersRad_test(void);

/* Procédure de test pour le calcul de la distance euclidienne entre deux images */
void calculerDistanceEuclidienne_test(void);

/* Procédure de test pour le calcul de la distance de Manhattan entre deux images */
void calculerDistanceManhattan_test(void);

/* Proc/dure de test pour la génération de nombres aléatoires binaires */
void nombreAleatoireBinaire_test(void);