#pragma once
#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <stdio.h>
#pragma once
#include "elevio.h"

typedef enum {
    DIRN_DOWN, DIRN_UP, DIRN_STOP
} MotorDirection;   //Retning til heisen


typedef struct {
    float powerLevel;               //Spenningsnivå til heisen i Volt
    MotorDirection motorDir;        //Motorretning
} MotorController;

//Medlemsfunksjoner
//void elevio_motorDirection(motorDirection dirn);
void setDirection(MotorDirection motorDir);
void emergencyStop();
void motorController_init();

extern MotorController mc;

#endif