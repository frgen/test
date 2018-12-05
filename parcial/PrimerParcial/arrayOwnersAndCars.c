#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "arrayOwnersAndCars.h"

int addIdCar(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    int id;
    int i;
    //int j;
    char option;

    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            brand[i].idMarca = id;
            if(brand[i].idMarca==owners[i].idOwner)
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
                    scanf("%d", &brand[i].descripcion);

                    switch(brand[i].descripcion)
                    {
                    case ALPHA_ROMEO:
                        brand[i].precioPorHora=150;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case FERRARI:
                        brand[i].precioPorHora=175;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case AUDI:
                        brand[i].precioPorHora=200;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;
                    case OTRO:
                        brand[i].precioPorHora=250;
                        cars[i].state=FULL;
                        printf("Agregado con exito\n");
                        continue;


                    /*for(j=0; j<len; j++)
                    {
                        if(auxCars[j].state==EMPTY && auxBrand[j].state==EMPTY)
                        {
                        auxCars[j].state=FULL;
                        auxCars[j].idForOwner = id;
                        auxCars[j].patent = cars[i].patent;
                        auxBrand[j].state=FULL;
                        auxBrand[j].idMarca = id;
                        auxBrand[j].precioPorHora= brand[i].precioPorHora;
                        auxBrand[j].descripcion=brand[i].descripcion;
                        }
                    }*/

                    }
                }
                break;
            }
        }
    }

    return 0;
}


int getOutCar(eMarca* brand, eCar* cars, eOwner* owners, int len)
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
            brand[i].idMarca = id;
            if(brand[i].idMarca==owners[i].idOwner)
            {
                printf("Desea egresar el auto del propietario(s/n)?\n");
                fflush(stdin);
                //__fpurge(stdin);
                scanf("%c", &option);
                option = toupper(option);

                if(option=='S')
                {
                    brand[i].precioPorHora=brand[i].precioPorHora*hours;
                    cars[i].state = FIRED;
                    printf("Egresado con exito\n");
                }
                break;
            }

        }
    }

    return 0;
}

int printOwnersAndCars(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    char textBrand[30];
    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && owners[i].carsNumber!=0 && cars[i].state==FULL)
        {
            switch(brand[i].descripcion)
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

            printf("%d\t%s\t%s\t%s\t%s\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, textBrand);
        }

    }

    return 0;
}

int printOnlyCars(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    char textBrand[30];
    int carsNumber = 0;

    int i;
    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            switch(brand[i].descripcion)
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

int totalCollection(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    int i, sum=0;
    for(i=0; i<len; i++)
    {
        if(cars[i].state==FIRED)
        {
            sum +=brand[i].precioPorHora;
        }
    }

    printf("La recaudacion total es de: %d\n", sum);

    return 0;
}

int collectionForBrand(eMarca* brand, eCar* cars, eOwner* owners, int len)
{

    int hours;
    hours = devolverHorasEstadia();
    int i;
    for(i=0; i<len; i++)
    {
        if(cars[i].state==FIRED)
        {
            switch(brand[i].descripcion)
            {
            case 1:
                brand[i].precioPorHora = hours*150;
                break;
            case 2:
                brand[i].precioPorHora = hours*175;
                break;
            case 3:
                brand[i].precioPorHora = hours*200;
                break;
            case 4:
                brand[i].precioPorHora=250;
                break;
            }
            brand[i].precioPorHora=brand[i].precioPorHora*hours;
            printf("%d\t%s\t%s\t%s\t%d\n", owners[i].idOwner, owners[i].name, owners[i].lastName,
                   cars[i].patent, brand[i].precioPorHora);
        }
    }
    return 0;
}

int sortOwnersAndCars(eMarca* brand, eCar* cars, eOwner* owners, int len, int order)
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

                    temp=brand[i].descripcion;
                    brand[i].descripcion=brand[j].descripcion;
                    brand[j].descripcion=temp;

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

int sortCarsbyPatent(eMarca* brand, eCar* cars, eOwner* owners, int len, int order)
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

                    temp=brand[i].descripcion;
                    brand[i].descripcion=brand[j].descripcion;
                    brand[j].descripcion=temp;

                }
            }
        }
    }
    return 0;
}

int printmeById(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    int id;
    int i;
    char textBrand[30];

    id = findOwnerById(owners,len,owners[len].idOwner);

    if(id!=-1)
    {
        for(i=0; i<len; i++)
        {
            if(id==owners[i].idOwner)
            {
                if(brand[i].descripcion>0 &&brand[i].descripcion<=4)
                {
                    switch(brand[i].descripcion)
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

int onlyAudiCars(eMarca* brand, eCar* cars, eOwner* owners, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(owners[i].state==FULL && cars[i].state==FULL)
        {
            if(brand[i].descripcion==3)
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

