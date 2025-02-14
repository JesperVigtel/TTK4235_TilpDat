#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include "driver/elevio.h"


typedef enum {
    DIRN_DOWN, DIRN_UP, DIRN_STOP
} MotorDirection;

typedef enum {
    IDLE,   //Standig still
    MOVING, //Mocvign
    DOOR_OPEN,
     EMERGENCY_STOPP 
} ElevatorState;

//Defining the elevator "class"
struct Elevator = {
    //Medlsemsvariabler
    int currentFloor;
    int targetFloor;
    MotorDirection motorDir;
    ElevatorState ElevState;

    //Medlemsfunksjoner
    void initialize();
    void moveToFlooe(int targetFloor);
    void updateStatus();
    void stop();
}


#endif