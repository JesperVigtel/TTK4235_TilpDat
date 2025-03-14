#include "Elevator.h"

Elevator elevator;

void elevator_initialize() { //For å initialisere heisen
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

void elevator_updateState() {   //oppdaterer oppførsel til heisen kontinuerlig i henhold til tilstander
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


void waitThreeSeconds() {
    struct timespec start, current;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double elapsed = 0;
    double waitTime = 3.0; 

    while (elapsed < waitTime) {
        clock_gettime(CLOCK_MONOTONIC, &current);
        elapsed = current.tv_sec - start.tv_sec + (current.tv_nsec - start.tv_nsec) / 1e9;

        panel_scanForOrders(); 

        if (elevio_obstruction()) {
            clock_gettime(CLOCK_MONOTONIC, &start); 
        }
    }
}