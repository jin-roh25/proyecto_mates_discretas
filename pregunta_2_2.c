#include <stdlib.h>
#include <math.h>

typedef struct 
{
    char nombre[100];
    int identificación;
    int numContactos;
    int contactos[numContactos];
    int confianza[3];

}entrenador;

entrenador *crearEntrenadores(int numEntrenadores, ){

    entrenador *entrenadores = malloc(numEntrenadores * sizeof(entrenador));

    for (int i = 0; i < numEntrenadores; i++)
    {
        scanf("%s %d", &entrenadores[i].nombre, &entrenadores[i].numContactos);
        for (int j = 0; j < entrenadores[i].numContactos; j++)
        {
            scanf("%d",&entrenadores.contacto[j]);
        }
        scanf("%s",&entrenadores[i].confianza);

    }
    

    return entrenadores;

}

int main(int argc, char const *argv[])
{
    int numEntrenadores;

    scanf("%d",&numEntrenadores);

    entrenador *entrenadores = crearEntrenadores(numEntrenadores);
    
    

    return 0;
}

