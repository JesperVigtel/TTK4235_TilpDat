#include "Elevator.h"

Elevator elevator;
OrderManager orderManager;

void initialize() { //For å initialisere heisen
    elevio_init();
    elevator.currentFloor = -1;


    orderManager_init();
    doorController_init();
    sensorSystem_init();

    while (elevator.currentFloor == -1) {   // Flytt heisen nedover for å finne en definert etasje
        elevio_motorDirection(DIRN_DOWN);
        elevator.currentFloor = elevio_floorSensor();
    }
    // Når en gyldig etasje er funnet, stopp motoren
    elevio_motorDirection(DIRN_STOP);
    elevio_floorIndicator(elevator.currentFloor);

}

void moveToFloor(int targetFloor) { //Flytter heisen til ønsket etasje
    elevator.targetFloor = targetFloor;
    elevator.state = MOVING;
}

void updateStatus() {   //oppdaterer statusent til heisen kontinuerlig
    switch(elevator.state){
        case IDLE:
            idle();
            //Stå stille
            break;
        case MOVING:
            //Bevegelse
            break;
        case DOOR_OPEN:
            //Vent til døra er igjen
            break;
        case EMERGENCY_STOP:
            stop();
            //Stans umiddelbart og vent
            break;
    }
}

void stop() {       //Stanser heisen øyeblikkelig
    elevio_motorDirection(DIRN_STOP);

}

void idle(){
    if (orderManager.numOrders = 0) {
        elevator.state = IDLE;
        
        //Stå stille, men ta imot bestillinger
    } else if (orderManager.numOrders > 0) {
        //Ta imot bestillinger
    }
    

}
