#include <stdlib.h>
#include <math.h>


int vertices[2][numVertices];
int arcos[numVertices][numVertices];
int vertpasdos[numVertices];
int compConexas[numVertices][numVertices];

int **asignarVertices(int numVertices){

    int **vertices = malloc(2*sizeof(int));

    vertices[0] = malloc(numVertices * sizeof(int));
    vertices[1] = malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        vertices[0][i] = i + 1;
    }

    return vertices;
}

int **asignarArcos(int numVertices){

    int **arcos = malloc(numVertices*sizeof(int))

    for (int i = 0; i < numVertices; i++)
    {
        arcos[i] = malloc(numVertices * sizeof(int));
    }

    printf("Ingrese si existen arcos pasando por cada uno de los vertices desde el primero: \n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &arcos[j][i]);
        }
    }

    return arcos;
}

int **initListComConexas(int numVertices){

    int **comConexas = malloc(numVertices*sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        comConexas[i] = malloc(numVertices * sizeof(int));
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            compConexas[i][1] = 0;
        }
    }

    return comConexas;
}

void restablecerNoVisitado(int numVertices, int **vertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        vertices[1][i]=0;
    }
}

void visitar(int **vertices, int numVertices, int vertActual, int *vertPasados, int **arcos)
{
    if (vertices[1][vertActual] == 0)
    {
        vertices[1][vertActual]==1;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                visitar(vertices, numVertices, vertices[0][i], vertPasados, arcos);
            }
            
        }
        
        vertVisitados[t] = vertActual;
        t++;
    }
    

}

void asignar(int vertActual, int numCompomFuertConexa, int **vertices, int numVertices, int **arcos, int **compConexas)
{
    if (vertices[1][vertActual] == 0)
    {
        vertices[1][vertActual] == 1;

        compConexas[numCompomFuertConexa][t] = vertActual;
        t++;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                asignar(vertices[0][i], numCompomFuertConexa, vertices, numVertices, arcos, compConexas);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int numVertices;
    int t = 0;
    int numCompomFuertConexa = 0;

    printf("Ingrese número de vertices: \n");
    scanf("%d",&numVertices);

    printf("a.1\n");
    int **vertices = asignarVertices(numVertices);
    printf("a\n");
    int **arcos = asignarArcos(numVertices);
    printf("b\n");
    int *vertPasados = malloc(numVertices * sizeof(int))
        printf("c\n");

    int **comConexas = initListComConexas(numVertices);
    restablecerNoVisitado(numVertices,vertices);

    for (int i = 0; i < numVertices; i++)
    {
        visitar(vertices, numVertices,vertices[0][i], vertPasados, arcos);
    }

    t=0;
    restablecerNoVisitado(numVertices, vertices);

    for (int i = 0; i < numVertices; i++)
    {
        asignar(vertices[0][i], numCompomFuertConexa, vertices, numVertices, arcos, compConexas);
        numCompomFuertConexa++;
    }
    
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (compConexa[j][i]!=0)
            {
                printf("%d ", compConexa[j][i]);
            }
            
        }
        printf("\n");
    }

    return 0;
}
