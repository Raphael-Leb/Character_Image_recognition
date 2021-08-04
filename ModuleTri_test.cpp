#include "ModuleTri_test.h"

void tamiser_test(void)
{

	int succes = TRUE;

	int tab_reference[] = { 100, 36, 25, 17, 7, 19, 1, 2, 3 };
	int tab_tamise[] = { 19, 7, 100, 2, 36, 25, 1, 17, 3 };

	int taille = sizeof(tab_reference) / sizeof(int);

	tamiser(tab_tamise, taille);

	// Comparer les deux tableaux
	for (int i = 0; i < taille; ++i)
	{
		if (tab_reference[i] != tab_tamise[i])
		{
			succes = FALSE;
			break;
		}
	}
	
	// Affichage
	if (succes == TRUE)
	{
		printf("tamiser_test: SUCCES\n\n");
	}
	else
	{
		printf("tamiser_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : [ 100, 36, 25, 17, 7, 19, 1, 2, 3 ]\n");

	printf("\tValeur obtenue  : [ %i, %i, %i, %i, %i, %i, %i, %i, %i ]\n",
		tab_tamise[0],
		tab_tamise[1], 
		tab_tamise[2], 
		tab_tamise[3], 
		tab_tamise[4], 
		tab_tamise[5], 
		tab_tamise[6], 
		tab_tamise[7], 
		tab_tamise[8]);

} 

void triTas_test(void)
{

	int succes = TRUE;

	int tab_reference[] = { 1, 2, 3, 7, 17, 19, 25, 36, 100 };
	int tab_trie[] = { 19, 7, 100, 2, 36, 25, 1, 17, 3 };

	int taille = sizeof(tab_reference) / sizeof(int);

	triTas(tab_trie, taille);

	// Comparer les deux tableaux
	for (int i = 0; i < taille; ++i)
	{
		if (tab_reference[i] != tab_trie[i])
		{
			succes = FALSE;
			break;
		}
	}

	// Affichage
	if (succes == TRUE)
	{
		printf("triTas_test: SUCCES\n\n");
	}
	else
	{
		printf("triTas_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]\n");

	printf("\tValeur obtenue  : [ %i, %i, %i, %i, %i, %i, %i, %i, %i ]\n",
		tab_trie[0],
		tab_trie[1],
		tab_trie[2],
		tab_trie[3],
		tab_trie[4],
		tab_trie[5],
		tab_trie[6],
		tab_trie[7],
		tab_trie[8]);

}

void partitionner_test(void)
{

	int tab_reference1[] = { 1, 2, 3, 7, 17, 19, 25, 36, 100 };
	int tab_reference2[] = { 19, 7, 100, 2, 36, 25, 1, 17, 3 };

	int valeur_obtenue1 = partitionner(tab_reference1, 0, sizeof(tab_reference1) / sizeof(int) - 1);
	int valeur_obtenue2 = partitionner(tab_reference2, 0, sizeof(tab_reference1) / sizeof(int) - 1);
	
	int valeur_attendue1 = 8;
	int valeur_attendue2 = 2;

	if ((valeur_obtenue1 == valeur_attendue1) && (valeur_attendue2 == valeur_obtenue2))
	{
		printf("partitionner_test: SUCCES\n\n");
	}
	else
	{
		printf("partitionner_test: ECHEC\n\n");
	}

	printf("\tValeur attendue 1 : %i\n", valeur_attendue1);
	printf("\tValeur obtenue  1 : %i\n\n", valeur_obtenue1);
	printf("\tValeur attendue 2 : %i\n", valeur_attendue2);
	printf("\tValeur obtenue  2 : %i\n", valeur_obtenue2);
}

void triRapide_test(void)
{

	int succes = TRUE;

	int tab_reference[] = { 1, 2, 3, 7, 17, 19, 25, 36, 100 };
	int tab_trie[] = { 19, 7, 100, 2, 36, 25, 1, 17, 3 };

	int taille = sizeof(tab_reference) / sizeof(int);

	triRapide(tab_trie, 0, taille - 1);

	// Comparer les deux tableaux
	for (int i = 0; i < taille; ++i)
	{
		if (tab_reference[i] != tab_trie[i])
		{
			succes = FALSE;
			break;
		}
	}

	// Affichage
	if (succes == TRUE)
	{
		printf("triRapide_test: SUCCES\n\n");
	}
	else
	{
		printf("triRapide_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]\n");

	printf("\tValeur obtenue  : [ %i, %i, %i, %i, %i, %i, %i, %i, %i ]\n",
		tab_trie[0],
		tab_trie[1],
		tab_trie[2],
		tab_trie[3],
		tab_trie[4],
		tab_trie[5],
		tab_trie[6],
		tab_trie[7],
		tab_trie[8]);

}

void triIntrospection_test(void)
{

	int succes = TRUE;

	int tab_reference[] = { 1, 2, 3, 7, 17, 19, 25, 36, 100 };
	int tab_trie[] = { 19, 7, 100, 2, 36, 25, 1, 17, 3 };

	int taille = sizeof(tab_reference) / sizeof(int);

	triIntrospection(tab_trie, taille);

	// Comparer les deux tableaux
	for (int i = 0; i < taille; ++i)
	{
		if (tab_reference[i] != tab_trie[i])
		{
			succes = FALSE;
			break;
		}
	}

	// Affichage
	if (succes == TRUE)
	{
		printf("triIntrospection_test: SUCCES\n\n");
	}
	else
	{
		printf("triIntrospection_test: ECHEC\n\n");
	}

	printf("\tValeur attendue : [ 1, 2, 3, 7, 17, 19, 25, 36, 100 ]\n");

	printf("\tValeur obtenue  : [ %i, %i, %i, %i, %i, %i, %i, %i, %i ]\n",
		tab_trie[0],
		tab_trie[1],
		tab_trie[2],
		tab_trie[3],
		tab_trie[4],
		tab_trie[5],
		tab_trie[6],
		tab_trie[7],
		tab_trie[8]);
	
}