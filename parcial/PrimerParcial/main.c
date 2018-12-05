#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "menu.h"

#define LIST 20

int main()
{
    eOwner ownersList[LIST];
    eCar carsList[LIST];
    eMarca brandList[LIST];

    initOwners(ownersList, LIST);

    initCars(brandList, carsList, LIST);

    showMenu(brandList, ownersList, LIST);

    return 0;
}
