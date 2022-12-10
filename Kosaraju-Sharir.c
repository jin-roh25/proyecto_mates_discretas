#include <stdlib.h>
#include <math.h>

int numVertices;
int t = 0;
int numCompomFuertConexa = 0;
int vertices[2][numVertices];
int arcos[numVertices][numVertices];
int vertpasdos[numVertices];
int compConexas[numVertices][numVertices];

void restablecerNoVisitado()
{
    for (int i = 0; i < numVertices; i++)
    {
        vertices[i][1]=0;
    }
}

void visitar(int vertActual)
{
    if (vertices[1][vertActual] == 0)
    {
        vertices[1][vertActual]==1;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                visitar(vertices[0][i]);
            }
            
        }
        
        vertVisitados[t] = vertActual;
        t++;
    }
    

}

void asignar(int vertActual, int numCompomFuertConexa){
    if (vertices[1][vertActual] == 0)
    {
        vertices[1][vertActual] == 1;

        compConexas[numCompomFuertConexa][t] = vertActual;
        t++;

        for (int i = 0; i < numVertices; i++)
        {
            if (arcos[vertActual][i] == 1)
            {
                asignar(vertices[0][i],numCompomFuertConexa);
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{

    printf("Ingrese número de vertices: \n");
    scanf("%d",&numVertices);
    
    for (int i = 0; i < numVertices; i++)
    {
        vertices[0][i]= i+1;
    }
    
    printf("Ingrese si existen arcos pasando por cada uno de los vertices desde el primero: \n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &arcos[j][i]);
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            compConexas[i][1] = 0;
        }
    }
    restablecerNoVisitado();

    for (int i = 0; i < numVertices; i++)
    {
        visitar(vertices[0][i]);
    }

    t=0;
    restablecerNoVisitado();

    for (int i = 0; i < numVertices; i++)
    {
        asignar(vertices[0][i],numCompomFuertConexa);
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
