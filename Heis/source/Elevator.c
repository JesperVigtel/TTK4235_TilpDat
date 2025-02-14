#include "Elevator.h"

void initialize() { //For å initialisere heisen
    elevio_init();

    orderManager_init();
    motorController_init();
    doorController_init();
    sensorSystem_init();

    int floor  = 

}

void moveToFloor(int targetFloor) { //Flytter heisen til ønsket etasje

}

void updateStatus() {   //oppdaterer statusent til heisen kontinuerlig

}

void stop() {       //Stanser heisen øyeblikkelig

}
