#include <stdlib.h>
#include <math.h>

int **Floyd_Warshall_algorithm(int **w, int V)
{

	int **dis = malloc(sizeof(int *) * V);
	for (int i = 0; i < V; i++)
	{
		dis[i] = malloc(sizeof(int) * V);
		for (int j = 0; j < V; j++)
			dis[i][j] = w[i][j];
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	//a

	return dis;
}
