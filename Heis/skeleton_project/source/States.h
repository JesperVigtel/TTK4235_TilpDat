#ifndef STATES_H
#define STATES_H

#include "Elevator.h"
#include <time.h>

//Statesene til heisen ved kjøring av program
void state_stop();
void state_doorOpen();
void state_moving();
void state_idle();


#endif