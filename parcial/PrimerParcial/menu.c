#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validate.h"



void showMenu(eOwner* owners, int length)
{
    eCar cars[length];
    char aux[10];
    int flag=0;
    int option;

    initOwnersHardCode(owners, length);
    initCarsHardCode(cars, length);

    do
    {
        printf("1.Alta de propietario\n2.Modificacion de propietario\n");
        printf("3.Baja de propietario\n4.Listar propietarios\n");
        printf("5.Ingreso de autos\n6.Egreso de autos\n");
        printf("7.Listado autos estacionados\n8.Recaudacion estacionamiento\n");
        printf("9.Recaudacion por marca\n");
        printf("10.Listar propietario, patente y autos estacionados segun ID\n");
        printf("11.Datos de propietarios de autos estacionados marca AUDI\n");
        printf("12.Autos estacionados y datos de sus propietarios, ordenados por patente\n");
        printf("0.Salir\n");
        printf("Elija una opcion: ");
        //fflush(stdin);
        __fpurge(stdin);
        option = getNumber(aux);

        if(option==1)
        {
            option = atoi(aux);
        }
        else
        {
            option = -1;
        }

        switch(option)
        {
        case 1:
            addOwner(owners, length);
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                printOwners(owners, length);
                editOwner(owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 3:
            if(flag==1)
            {
                printOwners(owners, length);
                removeOwner(owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 4:
            if(flag==1)
            {
                sortOwnersAndCars(cars, owners, length, 1);
                printOwners(owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 5:
            if(flag==1)
            {
                printOwners(owners, length);
                addIdCar(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 6:
            if(flag==1)
            {
                printOwnersAndCars(cars, owners, length);
                getOutCar(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 7:
            if(flag==1)
            {
                printOnlyCars(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 8:
            if(flag==1)
            {
                printf("Recaudacion total\n");
                totalCollection(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 9:
            if(flag==1)
            {
                printf("Recaudacion por marca\n");
                collectionForBrand(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 10:
            if(flag==1)
            {
                printf("Propietarios y patentes segun ID\n");
                printmeById(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 11:
            if(flag==1)
            {
                printf("Propietarios de autos marca AUDI\n");
                onlyAudiCars(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 12:
            if(flag==1)
            {
                printf("Autos y propietarios (ordenados por patente)\n");
                sortCarsbyPatent(cars, owners, length, 1);
                printOwnersAndCars(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
        //system("pause");
        //system("cls");
        printf("Presione una tecla para continuar...\n");
        __fpurge(stdin);
        getchar();
        system("clear");
    }
    while(option!=0);
}
