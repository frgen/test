#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    /*char otroNombre[20]="Anibal";*/
    int cantidad;
    /*int compara;
    int i;*/

    printf("Ingrese su nombre: ");
    fgets(nombre, 20, stdin);

    puts(nombre);

    nombre[strlen(nombre)-1] ='\0';

    cantidad = strlen(nombre);

    printf("%d", cantidad);

    /* scanf("%[^\n]", nombre);


    /*strupr(nombre);

  /*  for(i=0; i<strlen(nombre); i++)
    {
   /*     printf("%c\n", nombre[i]);
    }




    return 0;

    /*strupr(otroNombre);

    strcat(nombre, otroNombre);

    printf("%s\n", nombre);

    /*printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);*/
    /*printf("%s", nombre);

    /*compara = stricmp(nombre, otroNombre);

    if(compara==0)
    {
        printf("\nSon iguales");
    }
    else
    {
        if(compara>0)
        {
            printf("\n%s esta despues que %s", nombre, otroNombre);
        }
        else
        {
            printf("\n%s esta despues que %s", otroNombre, nombre);
        }
    }

    /*cantidad = strlen(nombre);*/
    /* printf("\nLa cantidad de caracteres es: %d", cantidad);*/
    /*printf("\nCompara: %d", compara);*/


}


/** \brief variables
 *
 * \param  (variables bloqueadas) nombre --------vvvv
 * \param  (variables bloqueadas) apellido------->>>>Ingreso maximo de 2 caracter c/u
           apellido y nombre------>>> Concatena c/ el sig formato:

                                  Gomez, Juan Luis
 * \return
 *
 */

