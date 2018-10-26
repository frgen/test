#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int numero = 4;

    FILE* pArchivo;

    pArchivo = fopen("archivoBinario.dat", "wb");

    fwrite(&numero, sizeof(int), 1, pArchivo);

    fclose(pArchivo);*/

    int numero;

    FILE* pArchivo;

    pArchivo = fopen("archivoBinario.dat", "rb");

    fread(&numero, sizeof(int), 1, pArchivo);

    fclose(pArchivo);

    printf("El numero es: %d", numero);


    return 0;
}
