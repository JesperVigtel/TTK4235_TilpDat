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
    MotorDirection motorDir;
    MotorDirection stopDir;
    ElevatorState state;         
} Elevator;

extern Elevator elevator;

//Medlemsfunksjoner
void elevator_initialize();     //Starter opp heisen tiø ønsket tilstand
void elevator_updateState();    //oppdaterer oppførsel til heisen kontinuerlig i henhold til tilstander
void waitThreeSeconds();        //Får heisen til å vente 3 sekunder 

#endif