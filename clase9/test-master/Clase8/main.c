#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumno.h"

#define A 3

int main()
{
    eAlumno listaAlumnos[A];
    int opcion;

    inicializarAlumnos(listaAlumnos, A, VACIO);

    do
    {
        printf("1.Cargar\n2.Mostrar\n10.Salir\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(cargarAlumnoEnListado(listaAlumnos, A)==1)
            {
                printf("Dato cargado con exito");
            }
            else
            {
                printf("No existe espacio disponible");
            }
            break;
        case 2:
            mostrarListado(listaAlumnos, A);
            break;
        case 3:
            if(!borrarAlumno(listaAlumnos, A))
            {
                printf("Dato no encontrado");
            }
            break;
        case 10:
            break;
        }
    }
    while(opcion!=10);


    return 0;
}
