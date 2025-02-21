#include "MotorController.h"

//Global variabel
MotorController mc;


void motorController_init(){
    mc.motorDir = DIRN_DOWN;
    elevio_motorDirection(mc.motorDir);
    mc.powerLevel = 2.5;
}

void setDirection(MotorDirection motorDir){
    elevio_motorDirection
}
void emergencyStop(){
    mc.motorDir = DIRN_STOP;
    mc.powerLevel = 0.0;
}
