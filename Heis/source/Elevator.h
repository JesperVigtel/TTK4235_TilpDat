#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include "driver/elevio.h"
#include "MotorController.h"


typedef enum {
    IDLE,   //Heisen er i ro
    MOVING, //I bevegsle
    DOOR_OPEN,
    EMERGENCY_STOP 
} ElevatorState;    //Tilstanden til heisen

//Definerer elevator klassen
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