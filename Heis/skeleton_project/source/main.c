#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "Elevator.h"





int main(){

//Ønsket kjøring
    elevator_initialize();

    while (1) {
        elevator_updateState();
        panel_getOrders();
    }
return 0;
}