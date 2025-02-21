#include "DoorController.h"

void openDoor() {
    elevio_doorOpenLamp(1);
}

void closeDoor(){
    elevio_doorOpenLamp(0);
}
