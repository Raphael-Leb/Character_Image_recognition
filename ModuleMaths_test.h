#pragma once

#include <stdio.h>
#include <math.h>

#include "ModuleConstantes.h"
#include "ModuleTests.h"
#include "ModuleMaths.h"
#include "ModuleTableaux.h"

/* Proc�dure de test pour la conversion de degr�s en radians */
void degVersRad_test(void);

/* Proc�dure de test pour le calcul de la distance euclidienne entre deux images */
void calculerDistanceEuclidienne_test(void);

/* Proc�dure de test pour le calcul de la distance de Manhattan entre deux images */
void calculerDistanceManhattan_test(void);

/* Proc/dure de test pour la g�n�ration de nombres al�atoires binaires */
void nombreAleatoireBinaire_test(void);