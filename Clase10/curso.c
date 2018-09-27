#include "curso.h"

void inicializarCursos(eCurso* cursos)
{
    int id[3]={100,101,102};
    char nombre[3][30]={"PHP", "C#", "VB"};
    int duracion[3]={3, 5, 6};
    char profesor[3][20]={"Christian", "Octavio", "Maxi"};
    int i;
    for(i=0; i<3; i++)
    {
        cursos[i].id=id[i];
        cursos[i].duracion=duracion[i];
        strcpy(cursos[i].nombre, nombre[i]);
        strcpy(cursos[i].profesor, profesor[i]);
    }
}

void mostrarCurso(eCurso curso)
{
    printf("%s--%s--%d\n", curso.nombre, curso.profesor, curso.duracion);
}

void mostrarTodosLosCursos(eCurso* cursos, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d", cursos[i]);
    }
}
