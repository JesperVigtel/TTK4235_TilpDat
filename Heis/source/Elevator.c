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



void idle(){
    int no = nextOrder();
    if (no == -1){
        elevio_motorDirection(DIRN_STOP);
    } elif(no != -1){
        moveToFloor(no);
    }
}

void moveToFloor(int targetFloor) { //Flytter heisen til ønsket etasje
    elevator.targetFloor = targetFloor;
    elevator.state = MOVING;
}


void moving() {
    if (elevator.targetFloor > elevator.currentFloor) {
        elevator.motorDir = DIRN_UP;
    } else if (elevator.targetFloor < elevator.currentFloor) {
        elevator.motorDir = DIRN_DOWN;
    } else {
        elevator.motorDir = DIRN_STOP;
        elevator.state = DOOR_OPEN;
    }
    elevio_motorDirection(elevator.motorDir);
}

void doorOpen() {
    elevio_doorOpenLamp(1);
    nanosleep(&(struct timespec){3, 0}, NULL);

    while (elevio_obstruction()){
        //nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
        nanosleep(&(struct timespec){3, 0}, NULL);
    }
    elevio_doorOpenLamp(0);
    elevator.state = IDLE; 
}

void stop() {       //Stanser heisen øyeblikkelig
    elevio_motorDirection(DIRN_STOP);
        clearAllOrders(); 
        while (elevio_stopButtonPressed()) {
            if (elevator.state == DOOR_OPEN) {
                elevio_doorOpenLamp(1); 
            }
        }
        elevator.state = IDLE; 
        nanosleep(&(struct timespec){3, 0}, NULL); 
        elevio_doorOpenLamp(0);
        return;
}

void updateStatus() {   //oppdaterer statusen til heisen kontinuerlig
    if (elevio_stopButton()) {
        elevator.motorDir = DIRN_STOP;
        elevio_motorDirection(DIRN_STOP);
        clearAllOrders(); 
        while (elevio_stopButtonPressed()) {
            if (elevator.state == DOOR_OPEN) {
                elevio_doorOpenLamp(1); 
            }
        }
        elevator.state = IDLE; 
        return;
    }

    switch(elevator.state){
        case IDLE:
            idle();
            break;
        case MOVING:
            moving();
            break;
        case DOOR_OPEN:
            doorOpen();
            break;
        case EMERGENCY_STOP:
            stop();
            break;
    }
}