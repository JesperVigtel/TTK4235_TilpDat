#include "Elevator.h"

Elevator elevator;

void initialize() { //For å initialisere heisen
    elevio_init();
    elevator.currentFloor = -1;

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

void updateStatus() {   //oppdaterer statusen til heisen kontinuerlig
    if (elevio_stopButton()) {
        elevator.state = EMERGENCY_STOP;
    }

    switch(elevator.state){
        case IDLE:
            state_idle();
            break;

        case MOVING:
            state_moving();
            break;

        case DOOR_OPEN:
            state_doorOpen();
            break;

        case EMERGENCY_STOP:
            state_stop();
            break;
    }
}