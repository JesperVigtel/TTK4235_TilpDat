#include "States.h"
#include <time.h>
Elevator elevator;


void state_idle(){
    int no = nextOrder();
    if (no == -1){
        elevio_motorDirection(DIRN_STOP);
    } else if(no != -1){
        moveToFloor(no);
    }
}



void state_moving() {
    // Debugging statements
    printf("Moving: Current Floor: %d, Target Floor: %d\n", elevator.currentFloor, elevator.targetFloor);

    if (elevio_floorSensor() != -1){
        elevator.currentFloor = elevio_floorSensor();
    }

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

void state_doorOpen() {
    if (elevator.currentFloor == -1) { // S2: Heisdøren skal aldri åpne seg utenfor en etasje
        elevator.state = IDLE;
        return;
    }

    // Debugging statements
    printf("Door Open: Current Floor: %d\n", elevator.currentFloor);


    elevio_motorDirection(DIRN_STOP); // S1: Heisen skal alltid stå stille når døren er åpen
    elevio_doorOpenLamp(1);
    nanosleep(&(struct timespec){3, 0}, NULL);

    while (elevio_obstruction()) {
        nanosleep(&(struct timespec){3, 0}, NULL);  //Pauser på 3 sek, grunnet vente 3 sekunder tter obstruction
    }
    elevio_doorOpenLamp(0);
    elevator.state = IDLE;
}



void state_stop() {       //Stanser heisen øyeblikkelig
    elevio_motorDirection(DIRN_STOP);
    clearAllOrders(); 
    while (elevio_stopButton()) { //Så lenge stoppknappen er trykket inn, skal heisen ikke kunne bevege seg
        if (elevator.state == DOOR_OPEN) {
            elevio_doorOpenLamp(1); 
        }
    }
    elevator.state = IDLE; 
    nanosleep(&(struct timespec){3, 0}, NULL); 
    elevio_doorOpenLamp(0);
}