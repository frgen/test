#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "arrayOwnersAndCars.h"

int addIdCar(eCar* cars, eOwner* owners, int len)
{
    int id;
    int i;
    char option;

    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            cars[i].idForOwner = id;
            if(cars[i].idForOwner==owners[i].idOwner)
            {
                printf("Desea agregar un auto nuevo a este propietario(s/n)?\n");
                fflush(stdin);
                //__fpurge(stdin);
                scanf("%c", &option);
                option = toupper(option);

                if(option=='S')
                {
                    printf("Ingrese la patente: ");
                    fflush(stdin);
                    scanf("%s", cars[i].patent);
                    printf("Ingrese la marca (1.Alpha Romeo 2. Ferrari 3. Audi 4. Otro): ");
                    scanf("%d", &cars[i].brand);
                    switch(cars[i].brand)
                    {
                    case 1:
                        cars[i].valor=150;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case 2:
                        cars[i].valor=175;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case 3:
                        cars[i].valor=200;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case 4:
                        cars[i].valor=250;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    }
                }
                break;
            }

        }
    }

    return 0;
}

int printOwnersAndCars(eCar* cars, eOwner* owners, int len)
{
    int hours;
    hours = devolverHorasEstadia();
    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            cars[i].valor=cars[i].valor*hours;
            printf("%d\t%s\t%s\t%s\t%d\t%d\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, cars[i].brand, cars[i].valor);
        }
    }
    return 0;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;
}

