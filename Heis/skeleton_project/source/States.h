#ifndef STATES_H
#define STATES_H

#include "Elevator.h"
#include <time.h>

//Statesene til heisen ved kjøring av program
void state_stop();       //Stanser heisen øyeblikkelig
void state_doorOpen();   //Dersom heisen skal åpne døra
void state_moving();     //Dersom heisen er i bevegelse
void state_idle();       //Dersom heisen er i ro


#endif