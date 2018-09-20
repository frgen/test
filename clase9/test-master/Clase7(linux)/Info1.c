#include <stdio_ext.h>
#include "Info1.h"
#define T 3

float calcularPromedio(int nota1, int nota2, int nota3)
{
    float promedio;

    promedio = (float)(nota1 + nota2 + nota3)/3;
    return promedio;
}

int cargarAlumnos(char nombre[][50], char email[][50], char sexo[], int nota1[], int nota2[], int nota3[], float promedio[], int edad[], int tam)
{
    int i;

    for(i=0; i<T; i++)
    {
        printf("Ingrese su nombre completo: ");
        __fpurge(stdin);
        scanf("%s", nombre[i]);
        printf("Ingrese su email: ");
        __fpurge(stdin);
        scanf("%s", email[i]);
        printf("Ingrese su sexo: ");
        __fpurge(stdin);
        scanf("%c", &sexo[i]);
        printf("Ingrese su edad: ");
        __fpurge(stdin);
        scanf("%d", &edad[i]);
        printf("Ingrese la nota 1: ");
        scanf("%d", &nota1[i]);
        printf("Ingrese la nota 2: ");
        scanf("%d", &nota2[i]);
        printf("Ingrese la nota 3: ");
        scanf("%d", &nota3[i]);

        promedio[i] = calcularPromedio(nota1[i], nota2[i], nota3[i]);
    }

    return 0;
}

int mostrarAlumnos(char nombre[][50], char email[][50], char sexo[], int nota1[], int nota2[], int nota3[], float promedio[], int edad[], int tam)
{
    int i;

    printf("%20s %10s %6s %6s %6s %6s %6s %8s\n", "Nombre", "Email", "Sexo", "Edad", "Nota1", "Nota2", "Nota3", "Promedio");
    for(i=0; i<T; i++)
    {
        printf("%20s %10s %6c %6d %6d %6d %6d %.2f\n", nombre[i], email[i], sexo[i], edad[i], nota1[i], nota2[i], nota3[i], promedio[i]);
    }

    return 0;
}
