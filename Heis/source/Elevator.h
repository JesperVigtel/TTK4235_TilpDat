#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include "driver/elevio.h"

//Egne kilder
#include "MotorController.h"
#include "SensorSystem.h"



typedef enum {
    IDLE,   //Heisen er i ro
    MOVING, //I bevegelse
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
    void moveToFloor(int targetFloor);
    void updateStatus();
    void stop();
}


#endif