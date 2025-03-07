#include "States.h"
#include <time.h>
Elevator elevator;


void state_idle(){
    int no = nextOrder();
    if (no == -1){
        elevio_motorDirection(DIRN_STOP);
    } else if (no == elevator.currentFloor){
        elevator.state = IDLE;
    } else {
        elevator.state = MOVING;
        printQueue();
    }
}    




void state_moving() {
    // Debugging statements
    //printf("Moving: Current Floor: %d, Target Floor: %d\n", elevator.currentFloor, elevator.targetFloor);
    int floorSensor = elevio_floorSensor();
    int no = nextOrder();
    if (no != -1) {
        elevator.targetFloor = no;
    }

    if (floorSensor != -1){
        elevator.currentFloor = floorSensor;
    }

    if (elevator.targetFloor > elevator.currentFloor) {
        elevator.motorDir = DIRN_UP;
    } else if (elevator.targetFloor < elevator.currentFloor) {
        elevator.motorDir = DIRN_DOWN;
    } else if (elevator.targetFloor == elevator.currentFloor) {
        elevator.motorDir = DIRN_STOP;
        elevator.state = DOOR_OPEN;
    }
    elevio_motorDirection(elevator.motorDir);
}

void state_doorOpen() {
    if (elevator.currentFloor == -1) {  //Aldri åpne dør utenfor etasje
        elevator.state = IDLE;
        return;
    }

    // Debugging statements
    //printf("Door Open: Current Floor: %d\n", elevator.currentFloor);

    elevio_motorDirection(DIRN_STOP); 
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
    nanosleep(&(struct timespec){3, 0}, NULL); 
    elevio_doorOpenLamp(0);
    elevator.state = IDLE; 
}