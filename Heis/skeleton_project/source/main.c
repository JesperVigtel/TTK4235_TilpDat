#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "Elevator.h"





int main(){

//Ønsket kjøring
    initialize();

    while (1) {
        for (int floor = 0; floor < N_FLOORS; floor++) {
            for (int button = 0; button < N_BUTTONS; button++) {
                if (elevio_callButton(floor, button)) {
                    addOrder(floor, button);
                }
            }
        }

    return 0;
}
}