#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "menu.h"



void showMenu(eOwner* owners, int length)
{
    eCar cars[length];
    char option;
    int flag=0;

    initOwnersHardCode(owners, length);

    do
    {
        printf("1.Alta de propietario\n2.Modificacion de propietario\n");
        printf("3.Baja de propietario\n4.Listar propietarios\n");
        printf("5.Ingreso de autos\n6.Egreso de autos\n7.Salir\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        //__fpurge(stdin);
        scanf("%c", &option);

        switch(option)
        {
        case '1':
            addOwner(owners, length);
            flag=1;
            break;
        case '2':
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
        case '3':
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
        case '4':
            if(flag==1)
            {
                printOwners(owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case '5':
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
        case '6':
            if(flag==1)
            {
                printOwnersAndCars(cars, owners, length);
            }
            else
            {
                printf("No se ingresaron datos\n");
            }
            break;
        case '7':
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
        system("pause");
        system("cls");
        //system("sleep 3s");
        //system("clear");
    }
    while(option!='7');
}
