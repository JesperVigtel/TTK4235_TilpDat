#include "Panel.h"

void panelSignals(){
    for (int floor = 0; floor < N_FLOORS; floor++) {
        for (int button = 0; button < N_BUTTONS; button++) {
            if (elevio_callButton(floor, button)) {
                addOrder(floor, button);
                printQueue();
            }
        }
    }
}

void floorLight(){
    elevio_floorIndicator(elevator.currentFloor);
}

void panelInit() {
    for (int floor = 0; floor < N_FLOORS; floor++) {
        removeFloorOrders(floor);
    }
}
