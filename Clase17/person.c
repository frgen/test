#include "person.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

ePerson* loadPerson(ePerson* pPerson)
{

    pPerson = (ePerson*)malloc(sizeof(ePerson));
    pPerson->edad = 20;
    pPerson->id = 100;
    strcpy(pPerson->nombre, "Pedro");

    return pPerson;
}

int showPerson(ePerson* pPerson)
{

    pPerson = loadPerson(pPerson);

    printf("%d---%d---%s", pPerson->edad, pPerson->id, pPerson->nombre);

    return 0;
}
