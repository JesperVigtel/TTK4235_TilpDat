#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <stdio.h>

typedef enum {
    DIRN_DOWN, DIRN_UP, DIRN_STOP
} MotorDirection;   //Retning til heisen


struct MotorController = {
//Medlemsvariabler
    int powerLevel;     //Spenningsnivå til heisen i Volt
    MotorDirection motorDir;

//Medlemsfunksjoner
    //void elevio_motorDirection(motorDirection dirn);
    void setDirection(MotorDirection motorDir);
    void emergencyStop()
}

#endif