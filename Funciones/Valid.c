#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Valid.h"

char* validarNombre(char nombre[20])
{
    char buffer[1000];

    puts("Ingrese su nombre: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>19)
    {
        puts("Reingrese su nombre: ");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(nombre, buffer);

    strlwr(nombre);
    nombre[0] = toupper(nombre[0]);

    return nombre;
}
