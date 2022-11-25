#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Floyd–Warshall algorithm.c"

#define Gimnasio_MIN 0
#define Gimnasio_MAX 18

#define Liga_Pokemon 0
#define Ciudad_Teja 1
#define Ciudad_Caolin 2
#define Pueblo_Ladrillo 3
#define Ciudad_Marga 4
#define Ciudad_Loza 5
#define Pueblo_Chamota 6
#define Pueblo_Arenisca 7
#define Ciudad_Fayenza 8
#define Ciudad_Mayolica 9
#define Ciudad_Negra 10
#define Pueblo_Ocre 11
#define Ciudad_Hormigon 12
#define Ciudad_Porcelana 13
#define Ciudad_Esmalte 14
#define Ciudad_Gres 15
#define Pueblo_Terracota 16
#define Ciudad_Engobe 17
#define Pueblo_Arcilla 18

int main()
{
	int **w = malloc(sizeof(int *) * (Gimnasio_MAX + 1));
	for (int i = 0; i <= Gimnasio_MAX; i++)
	{
		w[i] = malloc(sizeof(int) * (Gimnasio_MAX + 1));
		for (int j = 0; j <= Gimnasio_MAX; j++)
		{
			if (i == j)
				w[i][j] = 0;
			else
				w[i][j] = INFINITY;
		}
	}

	w[Liga_Pokemon][Ciudad_Marga] = 5;
	w[Ciudad_Marga][Pueblo_Arenisca] = 15;
	w[Pueblo_Arenisca][Ciudad_Negra] = 14;
	w[Ciudad_Negra][Ciudad_Mayolica] = 10;
	w[Ciudad_Mayolica][Ciudad_Fayenza] = 10;
	w[Ciudad_Fayenza][Ciudad_Loza] = 14;
	w[Ciudad_Loza][Ciudad_Teja] = 18;
	w[Ciudad_Teja][Ciudad_Caolin] = 6;
	w[Ciudad_Caolin][Pueblo_Ladrillo] = 20;

	w[Pueblo_Arcilla][Pueblo_Terracota] = 13;
	w[Pueblo_Terracota][Ciudad_Gres] = 8;
	w[Ciudad_Gres][Ciudad_Esmalte] = 8;
	w[Ciudad_Esmalte][Ciudad_Porcelana] = 19;
	w[Ciudad_Porcelana][Ciudad_Hormigon] = 13;
	w[Ciudad_Hormigon][Pueblo_Ocre] = 5;
	w[Pueblo_Ocre][Ciudad_Engobe] = 10;

	w[Pueblo_Arenisca][Pueblo_Chamota] = 13;
	w[Ciudad_Mayolica][Ciudad_Porcelana] = 16;

	for (int i = 0; i <= Gimnasio_MAX; i++)
	{
		for (int j = 0; j <= Gimnasio_MAX; j++)
		{
			if (i != j && w[i][j] != INFINITY)
			{
				w[j][i] = w[i][j];
			}
		}
	}
}