#include <stdio.h>
#include <stdlib.h>
#define A 3 //cantidad de alumnos
#include "Alumno.h"
#include "curso.h"

int main()
{
    /*
    eAlumno miAlumno={450, "Juan", 7, "xxx", 1, 10, 8, 1996};

    mostrarAlumno(miAlumno);
    */

    eAlumno listaAlumnos[A];
    int opcion, flag, aux, i, j;

    eCurso misCursos[3];

    //inicializarCursos(misCursos);

    //mostrarTodosLosCursos(misCursos);

    //inicializarAlumno(listaAlumnos, A, VACIO);
    //inicializarAlumnosConDatos(listaAlumnos, A, VACIO);

    do
    {
        printf("1. Cargar alumno\n");
        printf("2. Mostrar alumno\n");
        printf("3. Borrar alumno\n");
        printf("4. Modificar alumno\n");
        printf("5. Mostrar alumnos con datos\n");
        printf("10. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            /*if(cargarAlumnoEnListado(listaAlumnos, A)==1)
            {
                printf("Dato cargado con exito\n");
            }
            else
            {
                printf("No existe espacio disponible\n");
            }*/

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            for(i=0; i<A; i++) //Por cada alumno
            {
                if(listaAlumnos[i].estado==OCUPADO)
                {
                    printf("%d--%s--%f--\n", listaAlumnos[i].legajo,
                                             listaAlumnos[i].nombre,
                                             listaAlumnos[i].promedio);
                    for(j=0; j<3; j++)
                    {
                        if(listaAlumnos[i].idCurso==misCursos[j].id)
                        {
                            printf("%s\n", misCursos[j].nombre);
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    while(opcion!=10);

    return 0;
}
