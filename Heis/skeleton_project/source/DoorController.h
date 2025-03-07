#ifndef DOORCONTROLLER_H
#define DOORCONTROLLER_H

#include "Elevator.h"

typedef enum {
    OPEN, CLOSE
} DoorStatus;

void openDoor();


void closeDoor();

#endif