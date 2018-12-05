#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayCars.h"

int initCarsHardCode(eMarca* brand, eCar* cars, int len)
{
    int idCar[5]= {100,101,102,103,104};
    char patent[5][20]= {"WBM123","MNB543","AAQ143","BZA987","JHG123"};
    int someBrand[5]= {1,3,2,4,3};
    int valor[5]= {150,250,175,150,200};

    int i;
    for(i=0; i<5; i++)
    {
        brand[i].idMarca=idCar[i];
        strcpy(cars[i].patent, patent[i]);
        brand[i].descripcion=someBrand[i];
        brand[i].precioPorHora=valor[i];
        cars[i].state=FULL;
    }
    return 0;
}

int initCars(eMarca* brand, eCar* cars, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        brand[i].descripcion = 0;
        brand[i].precioPorHora = 0;
        cars[i].state = EMPTY;
    }
    return 0;
}

int addCar(eMarca* brand, eCar* cars, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(cars[i].state != FULL)
        {
            printf("Ingrese la marca: ");
            fflush(stdin);
            //__fpurge(stdin);
            scanf("%d", &brand[i].descripcion);
            printf("Ingrese la patente: ");
            fflush(stdin);
            //__fpurge(stdin);
            scanf("%s", cars[i].patent);

            cars[i].state = FULL;
            break;
        }
        else if(i==len-1)
        {
            printf("No hay espacio\n");
        }
    }
    return 0;
}
