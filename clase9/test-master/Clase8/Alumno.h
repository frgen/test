#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion[20];
    int estado;
}eAlumno;

eAlumno cargarAlumno();

void mostrarAlumno(eAlumno alumnoParametro);

/** \brief da de alta un alumno en el listado
 *
 * \param eAlumno[] el listado
 * \param tam int el tamaño del listado
 * \return int 0 [si la capacidad de la lista se agoto]
               1 [si pudo guardar]
 *
 */
int cargarAlumnoEnListado(eAlumno[], int);

void mostrarListado(eAlumno[], int);
void inicializarAlumnos(eAlumno[], int, int);
int buscarEspacio(eAlumno[], int);
int borrarAlumno(eAlumno[], int);

/*
Las estructuras en C son parecidas a las clases
en los lenguajes POO (paradigmas orientados a objetos)
*/
