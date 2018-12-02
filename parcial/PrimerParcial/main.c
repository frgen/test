#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "menu.h"

#define LIST 20

int main()
{
    eOwner ownersList[LIST];
    eCar carsList[LIST];

    initOwners(ownersList, LIST);

    initCars(carsList, LIST);

    showMenu(ownersList, LIST);

    return 0;
}
