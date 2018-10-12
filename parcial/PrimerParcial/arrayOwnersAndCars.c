#include <stdio.h>
#include "arrayOwnersAndCars.h"

int addIdCar(eCar* cars, eOwner* owners, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        printf("Ingrese el ID del propietario: ");
        scanf("%d", &cars[i].idForOwner);

        if(owners[i].idOwner==cars[i].idForOwner)
        {
            addCar(cars, len);
            break;
        }
        else
        {
            printf("El ID no coincide con ningun propietario\n");
            break;
        }
    }

    return 0;
}

