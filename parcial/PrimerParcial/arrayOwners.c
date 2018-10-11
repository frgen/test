#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayOwners.h"

int initOwners(eOwner* owners, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        owners[i].state = EMPTY;
    }
    return 0;
}

int initOwnersHardCode(eOwner* owners, int len)
{
    int id[10]= {100,101,102,103,104,105,106,107,108,109};
    char name[10][51]= {"Walter","Maria","Andres","Belen","Jose","Susana","Pablo","Ursula","Pedro","Lucia"};
    char lastName[10][51]= {"Ramirez","Perez","Gomez","Soto","Oliva","Lopez","Alvarez","Barrios","Torres","Pereira"};
    char address[10][51]= {"aaa","bbb","ccc","ddd","eee","fff","ggg","hhh","iii","jjj"};
    char cardNumber[10][51]= {"1000111122223333","1000111122223345","1000111122223369",
    "1000111122223333","1000111122223345","1000111122223369","1000111122223333",
    "1000111122223345","1000111122223369","1000111122223345"};

    int i;
    for(i=0; i<10; i++)
    {
        owners[i].idOwner=id[i];
        strcpy(owners[i].name, name[i]);
        strcpy(owners[i].lastName, lastName[i]);
        strcpy(owners[i].address, address[i]);
        strcpy(owners[i].cardNumber, cardNumber[i]);
        owners[i].state=FULL;
    }
    return 0;
}

int addOwner(eOwner* owners, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state != FULL)
        {
            owners[i].idOwner = rand() % 10 + 200;
            printf("Ingrese el nombre: ");
            scanf("%s", owners[i].name);
            printf("Ingrese el apellido: ");
            scanf("%s", owners[i].lastName);
            printf("Ingrese la direccion: ");
            scanf("%s", owners[i].address);
            printf("Ingrese el numero de tarjeta de credito: ");
            scanf("%s", owners[i].cardNumber);
            owners[i].state = FULL;
            break;
        }
        else if(i==len-1)
        {
            printf("No hay espacio\n");
        }
    }
    return 0;
}

int findOwnerById(eOwner* owners, int len, int id)
{
    int index;
    int i;
    printf("Ingrese el numero de ID: ");
    scanf("%d", &index);

    for(i=0; i<len; i++)
    {
        if(owners[i].idOwner==index)
        {
            printf("El propietario es: %s %s\n", owners[i].name, owners[i].lastName);
            index = owners[i].idOwner;
            break;
        }
        else if(i==len-1)
        {
            printf("Numero no encontrado\n");
            index = -1;
        }
    }
    return index;
}

int removeOwner(eOwner* owners, int len)
{
    int i;
    int id;
    char option;

    id = findOwnerById(owners,len,owners[len].idOwner);

    for(i=0; i<len; i++)
    {
        if(owners[i].idOwner==id)
        {
            printf("Esta seguro de borrar(s/n)?(No se puede deshacer)\n");
            fflush(stdin);
            scanf("%c", &option);
            option = toupper(option);

            if(option=='S')
            {
                owners[i].state = FIRED;
                printf("Borrando...\n");
                printf("Borrado con exito\n");
            }
            break;
        }
    }
    return 0;
}

int editOwner(eOwner* owners, int len)
{
    int id;
    int i;
    char option;

    id = findOwnerById(owners,len,owners[len].idOwner);

    for(i=0; i<len; i++)
    {
        if(owners[i].idOwner==id)
        {
            printf("Esta seguro de modificar(s/n)?\n");
            fflush(stdin);
            scanf("%c", &option);
            option = toupper(option);

            if(option=='S')
            {
                printf("Ingrese nuevo numero de tarjeta: ");
                scanf("%s", owners[i].cardNumber);
                printf("Modificado con exito\n");
            }
            break;
        }
    }

    return 0;
}

int printOwners(eOwner* owners, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL)
        {
            printf("%d\t%s\t%s\t%s\n", owners[i].idOwner, owners[i].name, owners[i].lastName, owners[i].cardNumber);
        }
    }
    return 0;
}

