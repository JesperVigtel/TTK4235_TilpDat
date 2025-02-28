#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"

//Egne kilder
#pragma once
#include "OrderManager.h"
#include "States.h"


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
    MotorDirection motorDir;
    ElevatorState state;         
} Elevator;

extern Elevator elevator;

//Medlemsfunksjoner
void initialize();
void moveToFloor(int targetFloor);
void updateStatus();

#endif