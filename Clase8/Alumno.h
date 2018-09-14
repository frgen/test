typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion[20];
}eAlumno;

void mostrarAlumno(eAlumno alumnoParametro);

eAlumno cargarAlumno();

void cargarListado(eAlumno[], int);
void mostrarListado(eAlumno[], int);

/*
Las estructuras en C son parecidas a las clases
en los lenguajes POO (paradigmas orientados a objetos)
*/
