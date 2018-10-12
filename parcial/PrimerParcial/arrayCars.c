#include <stdio_ext.h>
#include "arrayCars.h"

int initCars(eCar* cars, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        cars[i].state = EMPTY;
    }
    return 0;
}

int addCar(eCar* cars, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(cars[i].state != FULL)
        {
            printf("Ingrese la marca: ");
            //fflush(stdin);
            __fpurge(stdin);
            scanf("%s", cars[i].brand);
            printf("Ingrese la patente: ");
            //fflush(stdin);
            __fpurge(stdin);
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
