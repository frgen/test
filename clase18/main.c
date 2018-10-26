#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* archivo;

    char p1[20];
    char p2[20];

    archivo = fopen("texto.txt", "r");

    fgets(p1, 20, archivo);

    puts(p1);

    fgets(p2, 20, archivo);

    puts(p2);


    /*archivo = fopen("texto.txt", "w");

    fprintf(archivo, "Hola\n");
    fprintf(archivo, "Chau");

    fclose(archivo);*/

    /*char palabra[20]="Hola";
    FILE* pArchivo;
    pArchivo = fopen("texto", "w");

    fprintf(pArchivo, "%s, como estan todos?", palabra);

    fclose(pArchivo);

    pArchivo = fopen("texto", "r");

    fgets(palabra, 20, pArchivo);

    fclose(pArchivo);

    puts(palabra);*/

    return 0;
}







/*char palabra[20]="Hola";
    FILE* pArchivo;
    pArchivo = fopen("texto.txt", "w");

    fprintf(pArchivo, "%d, como estan todos?", 9);

    fclose(pArchivo);*/




/*FILE* pArchivo;
    pArchivo = fopen("texto.txt", "w");

    fprintf(pArchivo, "Hola");

    fclose(pArchivo);*/
