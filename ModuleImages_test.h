#pragma once

#include "ModuleConstantes.h"
#include "ModuleAffichage.h"

#include "ModuleTests.h"
#include "ModuleImages.h"
#include "ModuleTableaux.h"

/* Procédure de test pour la conversion d'images à niveaux de gris en image binaire. */
void convertirImageVersBinaire_test(void);

/* Procédure de test pour la rotation d'images. */
void tournerImage_test(void);

/* Procédure de test pour le décalage d'images. */
void decalerImage_test(void);

/* Procédure de test pour le cisaillement vertical d'images. */
void cisaillerImageVertical_test(void);

/* Procédure de test pour le cisaillement horizontal d'images. */
void cisaillerImageHorizontal_test(void);

/* Procédure de test pour le bruitage poivre et sel. */
void bruitPoivreEtSel_test(void);