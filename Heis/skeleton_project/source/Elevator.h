#ifndef ELEVATOR_H
#define ELEVATOR_H


#include "driver/elevio.h"
#include <stdio.h>

//Egne kilder
#include "OrderManager.h"
#include "States.h"
#include "Panel.h"


typedef enum {
    IDLE,           //Heisen er i ro
    MOVING,         //I bevegelse
    DOOR_OPEN,
    EMERGENCY_STOP 
} ElevatorState;    //Tilstanden til heisen

//Definerer elevator klassen
typedef struct {
    int currentFloor;
    int targetFloor;
    int previousFloor;
    MotorDirection motorDir;
    ElevatorState state;         
} Elevator;

extern Elevator elevator;

//Medlemsfunksjoner
void initialize();
void moveToFloor(int targetFloor);
void updateStatus();

#endif