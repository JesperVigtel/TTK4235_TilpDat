#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include "driver/elevio.h"

struct OrderManager = {
    //Medlemsvariabler
    int* orderQueue;    //Pointer to a dynamic array, husk å dealloker
    int numOrders;

    //Medlemsfunksjoner

}


#endif //ORDERMANAGER
