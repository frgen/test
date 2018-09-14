#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 3

int main()
{
    eAlumno listaAlumnos[A];

    cargarListado(listaAlumnos, A);

    mostrarListado(listaAlumnos, A);

    return 0;
}
