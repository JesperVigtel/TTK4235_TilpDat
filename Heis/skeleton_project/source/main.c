#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "Elevator.h"

int main(){
    elevator_initialize();          //Initialiserer heisen til en definert starttilstand

    while (1) {
        elevator_updateState();     // Oppdaterer hvilken tilstand heisen er i (idle, moving, door open, stop), og avgjør handling
        panel_scanForOrders();          // Leser knappetrykk i panelet og oppdaterer bestillingskøen.
        
    }
return 0;
}