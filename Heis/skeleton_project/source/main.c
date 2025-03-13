#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "Elevator.h"





int main(){

//Ønsket kjøring
    initialize();

    while (1) {
        elevator_updateState();
        panel_getOrders();
    }
return 0;
}