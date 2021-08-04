#pragma once

// Dimensions des images
#define NB_PIXELS_HAUTEUR 28
#define NB_PIXELS_LARGEUR 28
#define NB_PIXELS_TOTAL   784

// Constantes mathématiques
#define PI 3.14159265359
#define PI_DEG 180.0

// Tolérance pour les tests
#define EPS 0.001

// Booléens	
#define TRUE 1
#define FALSE 0

// Constantes utilisées dans les tests
#define NB_ECHANTILLONS_ALEATOIRES 1000000
#define PROB_SEL_ET_POIVRE 1
#define UN_SUR_DEUX 0.5

// Tampon pour la lecture des fichiers CSV
#define CSVBUF 8196

#define TAILLE_TEMP 50

// Les define du programme principal
#define NB_IMAGES_ENTRAINEMENT 1000			/* Vous ne devez PAS modifier cette valeur */
#define NB_IMAGES_ARTIFICIELLES 500			/* Vous pouvez modifier cette valeur       */
#define NB_IMAGES_TEST 50                   /* Vous ne devez PAS modifier cette valeur */
#define K_VOISINS 3                         /* Vous pouvez modifier cette valeur       */  /*Prendre une valeur impaire*/

