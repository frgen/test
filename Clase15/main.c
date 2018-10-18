#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int entero;
    char caracter;
}eDato;

int main()
{
    eDato miDato[] = {1, 'B', 1 ,'C'};

    int i;
    pDato = miDato;

    /*eDato miDato = {1, 'B'};
    eDato* pDato=&miDato;

    printf("%d--%c\n", (*pDato).entero, (*pDato).caracter);
    printf("%d--%c", pDato->entero, pDato->caracter);*/

    return 0;
}


















//void cargar(int*, int);
//void mostrar(int*, int);


/*int array[5];

    cargar(array, 5);
    mostrar(array, 5);*/



/*void cargar(int* pArray, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pArray+i);
    }
}

void mostrar(int* pArray, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\n", *(pArray+i));
    }
}*/



/*
Aritmetica de punteros

Sobre un puntero puedo realizar operaciones de adicion y sustraccion

pEntero + 1 = pEntero + sizeof(int)

pEntero + 2 = pEntero + sizeof(int)*2

*/


//pEntero = &array;
    //pEntero = &array[0];

    /*printf("%d\n", &entero);
    printf("%d\n", *(pEntero -1));
    printf("%d\n", pEntero +1);
    printf("%d\n", pEntero +2);*/

    //pLetter=&letter;
    //Ingreso el char a traves del puntero

    //printf("Ingrese un caracter: \n");
    //fflush(stdin);
    //*pLetter = getche();
    //scanf("%c", pLetter);

    // Muestro el char a traves del puntero

    //printf("%c", *pLetter);



    /*printf("%d\n", &letter);
    printf("%d\n", &pLetter);
    printf("%c\n", letter);
    printf("%d\n", pLetter);
    printf("%c\n", *pLetter);

    if(pLetter!=NULL)
    {
        printf("Hola a todos\n");
    }*/
