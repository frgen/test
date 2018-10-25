#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main()
{
    ePerson* somePerson;

    loadPerson(somePerson);

    showPerson(somePerson);

    return 0;
}
