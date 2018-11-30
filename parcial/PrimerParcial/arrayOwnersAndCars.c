#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
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
                    case ALPHA_ROMEO:
                        cars[i].valor=150;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case FERRARI:
                        cars[i].valor=175;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case AUDI:
                        cars[i].valor=200;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case OTRO:
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

int getOutCar(eCar* cars, eOwner* owners, int len)
{
    int hours;
    int id;
    int i;
    char option;

    hours = devolverHorasEstadia();
    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            cars[i].idForOwner = id;
            if(cars[i].idForOwner==owners[i].idOwner)
            {
                printf("Desea egresar el auto del propietario(s/n)?\n");
                fflush(stdin);
                //__fpurge(stdin);
                scanf("%c", &option);
                option = toupper(option);

                if(option=='S')
                {
                    cars[i].valor=cars[i].valor*hours;
                    cars[i].state = FIRED;
                    printf("Egresado con exito\n");
                }
                break;
            }

        }
    }

    return 0;
}

int printOwnersAndCars(eCar* cars, eOwner* owners, int len)
{
    char textBrand[20];
    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state>EMPTY)
        {
            switch(cars[i].brand)
            {
            case ALPHA_ROMEO:
                strcpy(textBrand, "AlphaRomeo");
                break;
            case FERRARI:
                strcpy(textBrand, "Ferrari");
                break;
            case AUDI:
                strcpy(textBrand, "Audi");
                break;
            case OTRO:
                strcpy(textBrand, "Otro");
                break;
            default:
                strcpy(textBrand, "N/I");
                strcpy(cars[i].patent, "N/I");
                break;
            }

            printf("%d\t%s\t%s\t%s\t%s\t\t%d\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, textBrand, cars[i].valor);
        }
        /*else if(cars[i].state==EMPTY)
        {

        }*/
    }

    return 0;
}

int printOnlyCars(eCar* cars, eOwner* owners, int len)
{
    char textBrand[20];

    int i;
    for(i=0; i<len; i++)
    {
        if(cars[i].state==FULL)
        {
            switch(cars[i].brand)
            {
            case 1:
                strcpy(textBrand, "AlphaRomeo");
                break;
            case 2:
                strcpy(textBrand, "Ferrari");
                break;
            case 3:
                strcpy(textBrand, "Audi");
                break;
            case 4:
                strcpy(textBrand, "Otro");
                break;
            }

            printf("%s\t%s\n", cars[i].patent, textBrand);
        }
    }
    return 0;
}

int totalCollection(eCar* cars, eOwner* owners, int len)
{
    int i, sum=0;
    for(i=0; i<len; i++)
    {
        if(cars[i].state==FIRED)
        {
            sum +=cars[i].valor;
        }
    }

    printf("La recaudacion total es de: %d\n", sum);

    return 0;
}

int collectionForBrand(eCar* cars, eOwner* owners, int len)
{

    int hours;
    hours = devolverHorasEstadia();
    int i;
    for(i=0; i<len; i++)
    {
        if(cars[i].state==FIRED)
        {
            switch(cars[i].brand)
            {
            case 1:
                cars[i].valor = hours*150;
                break;
            case 2:
                cars[i].valor = hours*175;
                break;
            case 3:
                cars[i].valor = hours*200;
                break;
            case 4:
                cars[i].valor=250;
                break;
            }
            cars[i].valor=cars[i].valor*hours;
            printf("%d\t%s\t%s\t%s\t%d\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, cars[i].valor);
        }
    }
    return 0;
}

int sortOwnersAndCars(eCar* cars, eOwner* owners, int len, int order)
{
    char tempText[51];
    int temp;

    int i, j;
    for(i=0; i<len-1; i++)
    {
        if(owners[i].state==FULL)
        {
            for(j=i+1; j<len; j++)
            {
                if(owners[j].state==FULL && stricmp(owners[i].lastName, owners[j].lastName)>0)
                {
                    strcpy(tempText, owners[i].lastName);
                    strcpy(owners[i].lastName, owners[j].lastName);
                    strcpy(owners[j].lastName, tempText);

                    strcpy(tempText, owners[i].name);
                    strcpy(owners[i].name, owners[j].name);
                    strcpy(owners[j].name, tempText);

                    temp=owners[i].idOwner;
                    owners[i].idOwner=owners[j].idOwner;
                    owners[j].idOwner=temp;

                    strcpy(tempText, owners[i].cardNumber);
                    strcpy(owners[i].cardNumber, owners[j].cardNumber);
                    strcpy(owners[j].cardNumber, tempText);

                    strcpy(tempText, cars[i].patent);
                    strcpy(cars[i].patent, cars[j].patent);
                    strcpy(cars[j].patent, tempText);

                    temp=cars[i].brand;
                    cars[i].brand=cars[j].brand;
                    cars[j].brand=temp;

                }
                else if(owners[j].state==FULL && stricmp(owners[i].name, owners[j].name)>0)
                {
                    if(owners[i].lastName>owners[j].lastName)
                    {
                        strcpy(tempText, owners[i].lastName);
                        strcpy(owners[i].lastName, owners[j].lastName);
                        strcpy(owners[j].lastName, tempText);
                    }
                }
            }
        }
    }
    return 0;
}

int printmeById(eCar* cars, eOwner* owners, int len)
{
    int id;
    int i;
    char option;

    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            if(cars[i].idForOwner==id)
            {

                printf("Ingrese la marca (1.Alpha Romeo 2. Ferrari 3. Audi 4. Otro): ");
                scanf("%d", &cars[i].brand);
                switch(cars[i].brand)
                {
                case ALPHA_ROMEO:
                    cars[i].valor=150;
                    cars[i].state=FULL;
                    printf("Agregado con exito\n");
                    continue;
                case FERRARI:
                    cars[i].valor=175;
                    cars[i].state=FULL;
                    printf("Agregado con exito\n");
                    continue;
                case AUDI:
                    cars[i].valor=200;
                    cars[i].state=FULL;
                    printf("Agregado con exito\n");
                    continue;
                case OTRO:
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

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;
}

