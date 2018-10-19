#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
}eDato;

eDato* miFuncion();

int main()
{
    eDato* d;
    d = miFuncion();

    printf("%d--%c", d->a, d->b);

    return 0;
}

eDato* miFuncion()
{
    eDato* pDato;

    pDato = (eDato*)malloc(sizeof(eDato));
    pDato->a = 4;
    pDato->b = 'F';

    return pDato;
}




/*
crear estructura
funcion que devuelva estructura
en el main llamo la funcion y recibo los datos
*/
