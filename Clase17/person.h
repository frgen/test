typedef struct
{
    int edad;
    int id;
    char nombre[30];
}ePerson;

ePerson* loadPerson(ePerson*);

int showPerson(ePerson*);
