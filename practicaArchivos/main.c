#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombres[5][20];
    int edad[5];
} ePersona;

int main()
{
    //FILE* archivo;
    ePersona persona;

    char nombres[5][20]= {"Jazmin","Pedro","Juan","Belen","Rodrigo"};
    int edad[5]= {20,25,21,24,22};

    int i;
    for(i=0; i<5; i++)
    {
        strcpy(persona.nombres[i], nombres[i]);
        persona.edad[i]= edad[i];
    }

    FILE* pArchivo;

    pArchivo = fopen("texto.txt", "w");

    for(i=0; i<5; i++)
    {
    fwrite();
        //fprintf(pArchivo, "%s ", persona.nombres[i]);
        //fprintf(pArchivo, "%d\n", persona.edad[i]);
    }

    fclose(pArchivo);

    pArchivo = fopen("texto.txt", "r");

    for(i=0; i<5; i++)
    {
        fgets(persona.nombres[i], 20, pArchivo);
        fscanf(pArchivo, "%d\n", &persona.edad[i]);

        printf("%s", persona.nombres[i]);
    }

    fclose(pArchivo);

    /*char p1[20];
    char p2[20];

    archivo = fopen("texto.txt", "r");

    fgets(p1, 20, archivo);

    puts(p1);

    fgets(p2, 20, archivo);

    puts(p2);*/

    /*archivo = fopen("texto.txt", "w");
    fprintf(archivo, "Hola\n");
    fprintf(archivo, "Chau");
    fclose(archivo);*/

    return 0;
}
