#include "States.h"
#include <time.h>
Elevator elevator;


void state_idle(){
    int no = nextOrder();
    if (no == -1){
        elevio_motorDirection(DIRN_STOP);
    } else if (no == elevator.currentFloor && elevio_floorSensor() != -1){
        elevator.state = DOOR_OPEN;
    } else {
        elevator.state = MOVING;
        printf("jeg printer her");
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

    if (elevator.targetFloor > elevator.currentFloor) {
        elevator.motorDir = DIRN_UP;
    } else if (elevator.targetFloor < elevator.currentFloor) {
        elevator.motorDir = DIRN_DOWN;
    } else if (elevator.targetFloor == elevator.currentFloor && floorSensor != -1) {
        elevator.motorDir = DIRN_STOP;
        elevator.state = DOOR_OPEN;
    } else if (elevator.targetFloor == elevator.currentFloor){
        if (elevator.stopDir == DIRN_DOWN){
            elevator.motorDir = DIRN_UP;
        } else if (elevator.stopDir == DIRN_UP){
            elevator.motorDir = DIRN_DOWN;
        }

    }

    if (floorSensor != -1){
        elevator.currentFloor = floorSensor;
    }
        
    elevio_motorDirection(elevator.motorDir);
}

void state_doorOpen() {
    if (elevator.currentFloor == -1) {  //Aldri åpne dør utenfor etasje
        elevator.state = IDLE;
        return;
    }

    elevio_motorDirection(DIRN_STOP); 
    elevio_doorOpenLamp(1);
    waitThreeSeconds();

    elevio_doorOpenLamp(0);
    removeFloorOrders(elevio_floorSensor());
    elevator.state = IDLE;
}





void state_stop() {       //Stanser heisen øyeblikkelig
    printf("Nødstopp");
    elevator.stopDir = elevator.motorDir;
    elevio_motorDirection(DIRN_STOP);
    elevator.motorDir=DIRN_STOP;
    clearAllOrders(); 
    int floor = elevio_floorSensor();
    while (elevio_stopButton()) { //Så lenge stoppknappen er trykket inn, skal heisen ikke kunne bevege seg
        elevio_stopLamp(1);
        if (floor != -1) {
            elevio_doorOpenLamp(1); 
        }
    }
    elevio_stopLamp(0);
    if (floor != -1) {
        waitThreeSeconds();
    }
        elevio_doorOpenLamp(0);
        elevator.state = IDLE; 
}

void waitThreeSeconds() {
    struct timespec start, current;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double elapsed = 0;
    double wait_time = 3.0;  // Wait time in seconds

    while (elapsed < wait_time) {
        clock_gettime(CLOCK_MONOTONIC, &current);
        elapsed = current.tv_sec - start.tv_sec + (current.tv_nsec - start.tv_nsec) / 1e9;

        // Call panelSignals() to check for button presses
        panelSignals();

        // Check for obstruction
        if (elevio_obstruction()) {
            clock_gettime(CLOCK_MONOTONIC, &start);  // Reset the timer if obstruction is detected
        }
    }
}