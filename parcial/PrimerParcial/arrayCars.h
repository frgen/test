
#define FULL 1
#define EMPTY 0
#define FIRED -1

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
    char patent[20];
    char brand[30];
    int idForOwner;
    int state;
} eCar;

int initCars(eCar*, int);

int addCar(eCar*, int);
