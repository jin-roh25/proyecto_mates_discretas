#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Floyd–Warshall algorithm.c"

typedef struct
{
	char name[3];
	int num;
} Ciudad;

int ciudadNum(char name[], Ciudad *ciudades, int Nciudades)
{
	for (int i = 0; i < Nciudades; i++)
	{
		if (strcmp(name, ciudades[i].name) == 0)
		{
			return ciudades[i].num;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	FILE *f = fopen(argv[0], "r");

	int Nciudades;
	fscanf(f, "%d", Nciudades);

	Ciudad *ciudades = malloc(sizeof(Ciudad) * Nciudades);
	for (int i = 0; i < Nciudades; i++)
	{
		fscanf(f, "%s", ciudades[i].name);
		ciudades[i].num = i;
	}

	int **w = malloc(sizeof(int *) * Nciudades);
	for (int i = 0; i <= 0; i++)
	{
		w[i] = malloc(sizeof(int) * Nciudades);
		for (int j = 0; j <= Nciudades; j++)
		{
			if (i == j)
				w[i][j] = 0;
			else
				w[i][j] = INFINITY;
		}
	}

	int NumArcos;
	fscanf(f, "%d", NumArcos);
	for (int i = 0; i < NumArcos; i++)
	{
		char CiO[3], CiD[3];
		int NCiO, NCiD, NumEntrenadores;
		fscanf(f, "%s %s %d", CiO, CiD, NumEntrenadores);

		NCiO = ciudadNum(CiO, ciudades, Nciudades);
		NCiD = ciudadNum(CiD, ciudades, Nciudades);

		w[NCiO][NCiD] = NumEntrenadores;
		w[NCiD][NCiO] = NumEntrenadores;
	}

	return 0;
}
