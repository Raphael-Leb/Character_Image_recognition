#pragma once
     /*___________________________________________________________________*/
   //                                                                    // 
  //                                                                    //
 //                                                                    //
/*____________________________________________________________________*/
/*          Nom du module :ModuleImages.h                            */
/*...................................................................*/
/*          Par    :     fourni par Iannick Gagnon                   */
/*                        Maître d'enseignement                      */
/*...................................................................*/    //
/*          Date   :    N/A                                          */   //
/*...................................................................*/  //
/*    Dernière modification :  N/A                                   */ //
/*___________________________________________________________________*///
/*    propelled by       C   H    N   O                              */
/*                          8  10   4   2                            */
/*___________________________________________________________________*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "ModuleMaths.h"
#include "ModuleConstantes.h"

/* Procédure de conversion d'une image à niveaux de gris en image binaire */
void convertirImageVersBinaire(unsigned char** img,
	unsigned char** copie);

/* Procédure qui sert à tourner une image d'un angle donné */
void tournerImage(unsigned char** img,
	const double   angle_degres,
	unsigned char** img_tournee);

/* Procédure qui sert à décaler une image  */
void decalerImage(unsigned char** img,
	const int   decalage_horizontal,
	const int   decalage_vertical,
	unsigned char** img_decalee);

/* Procédure qui applique un cisaillement vertical d'un angle donné */
void cisaillerImageVertical(unsigned char** img,
	const double   angle_cisaillement,
	unsigned char** img_cisaillee);

/* Procédure qui applique un cisaillement horizontal d'un angle donné */
void cisaillerImageHorizontal(unsigned char** img,
	const double   angle_cisaillement,
	unsigned char** img_cisaillee);

/* Procédure de bruitage poivre et sel */
void bruitPoivreEtSel(unsigned char** img,
	const double   prob,
	unsigned char** img_bruitee);

/* Fonction qui calculer la distance euclidienne entre deux images */
double calculerDistanceEuclidienne(unsigned char** img1,
	unsigned char** img2);

/* Fonction qui calcule la distance de Manhattan entre deux images */
double calculerDistanceManhattan(unsigned char** img1,
	unsigned char** img2);


/* Procedure d'augmentation des donnees d'entrainement*/
void augmenterDonnees(unsigned char*** tab3D_img_train,
	int* tab1D_etiquettes_img_train,
	const int depart,
	const int fin);