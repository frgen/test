#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void showMenu(eOwner* owners, int length)
{
    char option;
    int flag=0;

    initOwnersHardCode(owners, length);

    do
    {
        printf("1.Alta de propietario\n2.Modificacion de propietario\n");
        printf("3.Baja de propietario\n4.Listar propietarios\n5.Salir\n");
        printf("Elija una opcion: ");
        fflush(stdin);
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
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
        system("pause");
        system("cls");
    }
    while(option!='5');
}
