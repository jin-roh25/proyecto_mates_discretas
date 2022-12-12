#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int t = 0;

int **asignarVertices(int numVertices)
{

    int **vertices = malloc(2 * sizeof(int));

    vertices[0] = malloc(numVertices * sizeof(int));
    vertices[1] = malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        vertices[0][i] = i + 1;
    }

    return vertices;
}

int **iniciarVertPasados(int numVertices)
{

    int **vertPasados = malloc(2 * sizeof(int));

    vertPasados[0] = malloc(numVertices * sizeof(int));
    vertPasados[1] = malloc(numVertices * sizeof(int));

    return vertPasados;
}

int **asignarArcos(int numVertices)
{
    int **arcos = malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
    {
        arcos[i] = malloc((numVertices) * sizeof(int));
    }
    printf("Ingrese si existen(1) arcos pasando por cada uno de los vertices desde el primero: \n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &arcos[i][j]);
        }
    }

    return arcos;
}

int **initListComConexas(int numVertices)
{

    int **comConexas = malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        comConexas[i] = malloc(numVertices * sizeof(int));
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            comConexas[i][1] = 0;
        }
    }

    return comConexas;
}

void restablecerNoVisitado(int numVertices, int **vertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        vertices[1][i] = 0;
    }
}

void visitar(int **vertices, int numVertices, int vertActual, int **vertPasados, int **arcos)
{
    if (vertices[1][vertActual] == 0)
    {

        vertices[1][vertActual] = 1;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                visitar(vertices, numVertices, i, vertPasados, arcos);
            }
        }

        vertPasados[0][t] = vertActual;
        t++;
    }
}

void asignar(int vertActual, int numCompomFuertConexa, int **vertPasados, int numVertices, int **arcos, int **compConexas)
{
    if (vertPasados[1][vertActual] == 0)
    {
        vertPasados[1][vertActual] = 1;

        compConexas[numCompomFuertConexa][t] = vertPasados[0][vertActual];
        t++;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                asignar(i, numCompomFuertConexa, vertPasados, numVertices, arcos, compConexas);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int numVertices;
    int numCompomFuertConexa = 0;

    printf("Ingrese número de vertices: \n");
    scanf("%d", &numVertices);

    int **vertices = asignarVertices(numVertices);
    int **arcos = asignarArcos(numVertices);
    int **vertPasados = iniciarVertPasados(numVertices);

    int **comConexas = initListComConexas(numVertices);
    restablecerNoVisitado(numVertices, vertices);
    for (int i = 0; i < numVertices; i++)
    {
        visitar(vertices, numVertices, i, vertPasados, arcos);
    }

    t = 0;
    restablecerNoVisitado(numVertices, vertices);

    for (int i = 0; i < numVertices; i++)
    {

        asignar(i, numCompomFuertConexa, vertPasados, numVertices, arcos, comConexas);
        numCompomFuertConexa++;
    }

    for (int i = 0; i < numVertices; i++)
    {
        printf("componete conexa n°%d: ", i + 1);
        if (comConexas[i][0] != 0)
        {
        }
        for (int j = 0; j < numVertices; j++)
        {
            if (comConexas[i][j] != 0)
            {
                printf("%d ", comConexas[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
