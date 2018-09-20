#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define T 100

int main()
{
    int miVector[T];
    int suma;
    int opcion;

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Sumar\n4.Salir\nElija una opcion:\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            cargarVector(miVector, T);
            break;
        case 2:
            mostrarVector(miVector, T);
            break;
        case 3:
            inicializarVector(miVector, T);
            suma= sumarValores(miVector, T);
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }while(opcion!=4);

    printf("La suma es: %d", suma);

    return 0;
}
