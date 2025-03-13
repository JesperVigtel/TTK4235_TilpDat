#include "States.h"
#include <time.h>
Elevator elevator;


void state_idle(){      //Dersom heisen er i ro
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




void state_moving() {       //Dersom heisen er i bevegelse
    int floorSensor = elevio_floorSensor();
    int no = nextOrder();
    if (no != -1) {
        elevator.targetFloor = no;
    }
    //Avgjør retningen til heisen basert på nåværende etasje og bestilling:
    if (elevator.targetFloor > elevator.currentFloor) {     
        elevator.motorDir = DIRN_UP;
    } else if (elevator.targetFloor < elevator.currentFloor) {
        elevator.motorDir = DIRN_DOWN;

    } else if (elevator.targetFloor == elevator.currentFloor && floorSensor != -1) {    //Oppdaterer status ved nådd ønsket etasje
        elevator.motorDir = DIRN_STOP;
        elevator.state = DOOR_OPEN;

    } else if (elevator.targetFloor == elevator.currentFloor){      //Spesialcase dersom stop-knapp trykkes mellom etasjer, og ny bestilling er forrige passerte etasje
        if (elevator.stopDir == DIRN_DOWN){
            elevator.motorDir = DIRN_UP;
        } else if (elevator.stopDir == DIRN_UP){
            elevator.motorDir = DIRN_DOWN;
        }

    }

    if (floorSensor != -1){     //Oppdaterer etasje ved passering av sensor
        elevator.currentFloor = floorSensor;
    }
        
    elevio_motorDirection(elevator.motorDir);
}

void state_doorOpen() {     //Dersom heisen skal åpne døra
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

