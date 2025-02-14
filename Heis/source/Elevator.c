#include "Elevator.h"
#include "MotorController.h"
#include "SensorSystem.h"
#include "OrderManager.h"

struct MotorController mc;

void initialize() { //For å initialisere heisen
    elevio_init();

    orderManager_init();
    motorController_init();
    doorController_init();
    sensorSystem_init();

    mc.currentFloor = elevio_floorSensor();
    while (floor == -1) {
        // Flytt heisen nedover for å finne en definert etasje
        elevio_motorDirection(DIRN_DOWN);
        nanosleep(&(struct timespec){0, 50 * 1000 * 1000}, NULL);
        mc.currentFloor = elevio_floorSensor();
    }
    // Når en gyldig etasje er funnet, stopp motoren
    elevio_motorDirection(DIRN_STOP);
    elevio_floorIndicator(floor);

}

void moveToFloor(int targetFloor) { //Flytter heisen til ønsket etasje

}

void updateStatus() {   //oppdaterer statusent til heisen kontinuerlig

}

void stop() {       //Stanser heisen øyeblikkelig

}
