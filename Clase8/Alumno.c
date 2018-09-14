#include <stdio.h>
#include "Alumno.h"

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
    printf("%d--%s--%f--%s\n", alumnoParametro.legajo, alumnoParametro.nombre, alumnoParametro.promedio, alumnoParametro.direccion);
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

