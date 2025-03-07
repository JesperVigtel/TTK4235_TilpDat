#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "Elevator.h"





int main(){

//Ønsket kjøring
    initialize();

    while (1) {
        updateStatus();
        panelSignals();
return 0;
}