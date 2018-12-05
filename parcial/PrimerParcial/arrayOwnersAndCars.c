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
                    owners[i].carsNumber += 1;
                    printf("Ingrese la patente: ");
                    fflush(stdin);
                    //__fpurge(stdin);
                    scanf("%s", cars[i].patent);

                    printf("Ingrese la marca (1.Alpha Romeo 2. Ferrari 3. Audi 4. Otro): ");
                    scanf("%d", &cars[i].brand);

                    //listCarsEveryone(cars, owners, len);

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

int listCarsEveryone(eCar* cars, eOwner* owners, int len)
{
    int i, j;
    eCar auxList[20];
    initCars(auxList, 20);

    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            for(j=0; j<=owners[i].carsNumber; j++)
            {
                if(auxList[j].state==EMPTY)
                {
                    auxList[j].state=FULL;
                    strcpy(auxList[j].patent, cars[i].patent);
                    auxList[j].brand=cars[i].brand;
                    auxList[j].valor=cars[i].valor;
                    auxList[j].idForOwner=cars[i].idForOwner;
                    break;
                }
                printf("%d\t%s\t%d\n", auxList[j].idForOwner, auxList[j].patent, auxList[j].brand);
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
        if(owners[i].state==FULL && owners[i].carsNumber!=0 && cars[i].state==FULL)
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
            }

            printf("%d\t%s\t%s\t%s\t%s\t\t%d\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, textBrand, owners[i].carsNumber);
        }

    }

    return 0;
}

int printOnlyCars(eCar* cars, eOwner* owners, int len)
{
    char textBrand[20];
    int carsNumber = 0;

    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
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
            carsNumber += owners[i].carsNumber;
        }
    }
    printf("El numero de autos estacionados es: %d\n", carsNumber);

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
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            for(j=i+1; j<len; j++)
            {
                if(owners[j].state==FULL && cars[j].state==FULL && strcmp(owners[i].lastName, owners[j].lastName)>0)
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

                    temp=owners[i].carsNumber;
                    owners[i].carsNumber=owners[j].carsNumber;
                    owners[j].carsNumber=temp;

                    strcpy(tempText, owners[i].creditCard);
                    strcpy(owners[i].creditCard, owners[j].creditCard);
                    strcpy(owners[j].creditCard, tempText);

                    strcpy(tempText, cars[i].patent);
                    strcpy(cars[i].patent, cars[j].patent);
                    strcpy(cars[j].patent, tempText);

                    temp=cars[i].brand;
                    cars[i].brand=cars[j].brand;
                    cars[j].brand=temp;

                }
                else if(owners[j].state==FULL && strcmp(owners[i].name, owners[j].name)>0)
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

int sortCarsbyPatent(eCar* cars, eOwner* owners, int len, int order)
{
    char tempText[51];
    int temp;

    int i, j;
    for(i=0; i<len-1; i++)
    {
        if(cars[i].state==FULL)
        {
            for(j=i+1; j<len; j++)
            {
                if(cars[j].state==FULL && strcmp(cars[i].patent, cars[j].patent)>0)
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

                    strcpy(tempText, owners[i].creditCard);
                    strcpy(owners[i].creditCard, owners[j].creditCard);
                    strcpy(owners[j].creditCard, tempText);

                    strcpy(tempText, cars[i].patent);
                    strcpy(cars[i].patent, cars[j].patent);
                    strcpy(cars[j].patent, tempText);

                    temp=cars[i].brand;
                    cars[i].brand=cars[j].brand;
                    cars[j].brand=temp;

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
    char textBrand[20];

    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            if(id==owners[i].idOwner)
            {
                if(cars[i].brand>0 &&cars[i].brand<=4)
                {
                    switch(cars[i].brand)
                    {
                    case ALPHA_ROMEO:
                        strcpy(textBrand, "Alpha Romeo");
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
                    }
                }
                printf("Tiene %d auto/s estacionado/s \n", owners[i].carsNumber);
                printf("%s\t%s\n", cars[i].patent, textBrand);
                break;
            }

        }

    }
    return 0;
}

int onlyAudiCars(eCar* cars, eOwner* owners, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            if(cars[i].brand==3)
            {
                printf("%d\t%s\t%s\t%s\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                       owners[i].creditCard);
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

