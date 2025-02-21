#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h> //Input/output funcitons
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"

//Egne kilder
#pragma once
#include "MotorController.h"
#include "SensorSystem.h"
#include "OrderManager.h"
#include "DoorController.h"


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
    DoorStatus door;            //Funksjonalitet for å kun oppdatere dør_state        
} Elevator;

extern Elevator elevator;

//Medlemsfunksjoner
void initialize();
void moveToFloor(int targetFloor);
void updateStatus();
void stop();
void idle();

#endif