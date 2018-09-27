#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"

void inicializarAlumnosConDatos(eAlumno listado[], int tam)
{
    int legajo[5]={1,2,3,4,5};
    char nombre[5][50]={"Juan","Maria","Pedro", "Susana", "Luis"};
    float promedio[5]={3,4,5,6,8};
    char direccion[5][20]={"aaa", "bbb", "ccc", "ddd", "eee"};
    int curso[5]={100,102,101,102,100};

    int i;

    for(i=0; i<5; i++)
    {
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nombre, nombre[i]);
        listado[i].promedio = promedio[i];
        strcpy(listado[i].direccion, direccion[i]);
        listado[i].estado = OCUPADO;
        listado[i].idCurso = curso[i];
    }
}

int borrarAlumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    int encontro=0;
    printf("Ingrese legajo a buscar: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo==listado[i].legajo && listado[i].estado==OCUPADO)
        {
            printf("Ingrese el nuevo promedio");
            scanf("%f", &listado[i].promedio);

            encontro=1;
            break;
        }
    }
}

eAlumno cargarAlumno()
{
    eAlumno miAlumno;

    printf("Ingrese el legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("Ingrese el promedio: ");
    scanf("%f", &miAlumno.promedio);

    printf("Ingrese el direccion: ");
    fflush(stdin);
    gets(miAlumno.direccion);

    return miAlumno;
}

void mostrarAlumno(eAlumno alumnoParametro)
{
    printf("%d--%s--%f--%s\n", alumnoParametro.legajo, alumnoParametro.nombre, alumnoParametro.promedio,
           alumnoParametro.direccion);
}

void cargarListado(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i] = cargarAlumno();
    }

    return;
}

void mostrarListado(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarAlumno(listado[i]);
    }

    return;
}




