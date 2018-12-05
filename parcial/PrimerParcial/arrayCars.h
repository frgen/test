#define FULL 1
#define EMPTY 0
#define FIRED -1

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


typedef struct
{
    int idForOwner;
    char patent[20];
    int state;
} eCar;

typedef struct
{
    int idMarca;
    int descripcion;
    int precioPorHora;
    int state;
}eMarca;


int initCarsHardCode(eMarca*, eCar*, int);

int initCars(eMarca*, eCar*, int);

int addCar(eMarca*, eCar*, int);

int dataCars(int);
