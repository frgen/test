#include <stdio.h>
#include <stdlib.h>
#define T 5

int main()
{
    int* vector;
    int* pAux;
    int i;

    vector = (int*)malloc(sizeof(int)*T);

    if(vector!=NULL)
    {
        for(i=0; i<T; i++)
        {
            *(vector+i) = i+1;
        }

        for(i=0; i<T; i++)
        {
            printf("%d\n", *(vector+i));
        }

        pAux = realloc(vector, sizeof(int) * (T+5));

        if(pAux!=NULL)
        {
            vector = pAux;
            for(i=T; i<T+5; i++)
            {
                *(vector+i) = i+1;
            }

            printf("\nACA TENGO 10\n");
            for(i=0; i<T+5; i++)
            {
                printf("%d\n", *(vector+i));
            }

            printf("\nACA TENGO 3\n");
            vector = realloc(vector, sizeof(int)*3);

            for(i=0; i<3; i++)
            {
                printf("%d\n", *(vector+i));
            }

        }

    }
    else
    {
        printf("No hay suficiente espacio\n");
    }

    return 0;
}


/*
La funcion malloc reserva un espacio en la memoria HEAP
*/
