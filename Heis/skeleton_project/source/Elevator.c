#include "Elevator.h"

Elevator elevator;

void initialize() { //For å initialisere heisen
    clearAllOrders();
    elevio_init();
    panelInit();
    elevator.currentFloor = -1;

    while (elevator.currentFloor == -1) {   // Flytt heisen nedover for å finne en definert etasje
        elevio_motorDirection(DIRN_DOWN);
        elevator.currentFloor = elevio_floorSensor();
    }
    // Når en gyldig etasje er funnet, stopp motoren
    elevio_motorDirection(DIRN_STOP);
}

void elevator_updateState() {   //oppdaterer statusen til heisen kontinuerlig
    if (elevio_stopButton()) {
        elevator.state = EMERGENCY_STOP;
    }
 
    floorLight();
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