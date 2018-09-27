#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion[20];
    int idCurso;
    int estado;
    //eFecha fechaNacimiento;
    //eFecha fechaIngreso;
} eAlumno;

void mostrarAlumno(eAlumno);

eAlumno cargarAlumno();

void inicializarAlumnosConDatos(eAlumno [], int);
void cargarListado(eAlumno[], int);
int modificarAlumno(eAlumno[], int);
int cargarAlumnoEnListado(eAlumno[], int);
void mostrarListado(eAlumno[], int);
void inicializarAlumno(eAlumno[], int, int);
int buscarEspacio(eAlumno[], int);
int borrarAlumno(eAlumno[], int);

/*
Las estructuras en C son parecidas a las clases
en los lenguajes POO (paradigmas orientados a objetos)

1-alumnos que cursan PHP
2-por cada curso todos los alumnos
*/

