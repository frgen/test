#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 3

/*
a) Cargar los datos (carga aleatoria)
b) Modificar: se ingresa el legajo, lo busca y si lo encuentra modifica la nota1
c) Informes
1- Los alumnos con promedio 6 o mas
2- El/Los alumno/s con maximo promedio
3- La/s alumna/s con minimo promedio
4- Cantidad de alumnos desaprobados
5- Cantidad de alumnos aprobados
6- Porcentaje de aprobados y desaprobados
7- Mostrar los alumnos que se llamen Juan
8- Ordenar los datos alfabeticamente por nombre
9- Ordenar por nombre y ante igualdad de nombre por promedio
10- Mostrar los alumnos cuyo nombre comience con P
11- Ordenar alumnos por sexo
12- Realizar un grafico que muestre:
    Alumnos entre 15-18 (inclusive)
                  19 y 25 (inclusive)
                  26 o mas
*/

float calcularPromedio(int, int, int);
int cargarAlumnos(char[][50], char[][50], char, int[], int[], int[], float[], int, int);
int mostrarAlumnos(char[][50], char[][50], char, int[], int[], int[], float[], int, int);

int main()
{
    char nombreCompleto[T][50];
    int nota1[T];
    int nota2[T];
    int nota3[T];
    float promedio[T];
    char email[T][50];
    char sexo;
    int edad;

    cargarAlumnos(nombreCompleto, email, sexo, nota1, nota2, nota3, promedio, edad, T);
    mostrarAlumnos(nombreCompleto, email, sexo, nota1, nota2, nota3, promedio, edad, T);

    return 0;
}

float calcularPromedio(int nota1, int nota2, int nota3)
{
    float promedio;

    promedio = (float)(nota1 + nota2 + nota3)/3;
    return promedio;
}

int cargarAlumnos(char nombre[][50], char email[][50], char sexo, int nota1[], int nota2[], int nota3[], float promedio[], int edad, int tam)
{
    int i;

    for(i=0; i<T; i++)
    {
        printf("Ingrese su nombre completo: ");
        fflush(stdin);
        gets(nombre[i]);
        printf("Ingrese su email: ");
        fflush(stdin);
        gets(email[i]);
        printf("Ingrese su sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
        printf("Ingrese su edad: ");
        fflush(stdin);
        scanf("%d", &edad);
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

int mostrarAlumnos(char nombre[][50], char email[][50], char sexo, int nota1[], int nota2[], int nota3[], float promedio[], int edad, int tam)
{
    int i;

    printf("%20s %6s %6s %6s %6s %6s %6s %8s\n", "Nombre", "Email", "Sexo", "Edad", "Nota1", "Nota2", "Nota3", "Promedio");
    for(i=0; i<T; i++)
    {
        printf("%20s %20s %6c %6d %6d %6d %6d %.2f\n", nombre[i], email[i], sexo[i], edad[i], nota1[i], nota2[i], nota3[i], promedio[i]);
    }

    return 0;
}


/*char nombre[20];
    char apellido[20];
    char nombreCompleto[50];
    char buffer[1000];
    int i;

    puts("Ingrese su nombre: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>19)
    {
        puts("Reingrese su nombre: ");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(nombre, buffer);

    puts("Ingrese su apellido: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>19)
    {
        puts("Reingrese su apellido: ");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(apellido, buffer);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0; i<strlen(nombreCompleto); i++)
    {
        if(isspace(nombreCompleto[i]))
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    puts(nombreCompleto);*/


//char cadena1[10];
//char cadena2[50] = "Hola a todos, como estan?";
//strncpy(cadena1, cadena2, 9);

//puts(cadena1);
