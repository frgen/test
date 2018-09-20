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

int cargarAlumnoEnListado(eAlumno listado[], int tam)
{
    int indice;
    int encontro = 0;
    int i;

    indice = buscarEspacio(listado, tam);
    if(indice!=-1)
    {
        listado[i] = cargarAlumno();
        listado[i].estado = OCUPADO;
        encontro = 1;
    }
    else
    {
        printf("No hay espacio disponible");
    }

    return encontro;

}

void mostrarListado(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarAlumno(listado[i]);
        }
    }

}

void inicializarAlumnos(eAlumno lista[], int tam, int estado)
{
    int i;
    for(i=0; i< tam; i++)
    {
        lista[i].estado = estado;
    }
}

int buscarEspacio(eAlumno listado[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int borrarAlumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    int encontro;

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<tam; i++)
    {
        if(legajo==listado[i].legajo && listado[i].estado==OCUPADO)
        {
            listado[i].estado = ELIMINADO;
            encontro = 1;
            break;
        }
    }
    return encontro;
}




/*
1.Pedir legajo                no
2.Busco el legajo en el array ---> "No existe"
                              |
                              v si
                              Cambio estado a borrado
*/

