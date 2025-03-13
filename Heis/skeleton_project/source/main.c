#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "Elevator.h"

int main(){
    elevator_initialize();          //Initialiserer heisen til ønsket tilstand før løkke kjøres

    while (1) {
        elevator_updateState();     //Oppdaterer statusen, og avgjør handling til heisen basert på bestillinger
        panel_getOrders();          //Sjekker panelet for bestillinger, og legger til i køen
    }
return 0;
}