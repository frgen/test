#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define LIST 20

int main()
{
    eOwner ownersList[LIST];

    showMenu(ownersList, LIST);

    return 0;
}
