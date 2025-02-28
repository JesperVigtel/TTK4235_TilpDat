#include "OrderManager.h"
#include <stdio.h>


bool queue[N_FLOORS][N_BUTTONS] = {{false}};

void addOrder(int floor, int button) {
    if ((floor >= 0 && floor < N_FLOORS) && (button >= 0 && button < N_BUTTONS)) {
        queue[floor][button] = 1;
        elevio_buttonLamp(floor, button, 1); //Turn on button Lamp
    }
}

void removeOrder(int floor, int button){
    if ((floor >= 0 && floor < N_FLOORS) && (button >= 0 && button < N_BUTTONS)) {
        queue[floor][button] = 0;
        elevio_buttonLamp(floor, button, 0); //Turn off button Lamp
    }
}
void clearAllOrders() {
    for (int i = 0; i < N_FLOORS; i++) {
        for (int j = 0; j < N_BUTTONS; j++) {
            queue[i][j] = 0; // clear all orders
            elevio_buttonLamp(i, j, 0); // Turn off Button Lamp
        }
    }
}
void printQueue() {
    printf("\nHeis køsystem:\n");
    printf("    Opp  Ned  Cabin\n");
    for (int i = 0; i < N_FLOORS; i++) {
        printf("Etasje %d: ", i);
        for (int j = 0; j < N_BUTTONS; j++) {
            printf(" %d ", queue[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int nextOrder() {
    int floor = elevio_floorSensor();
    printQueue();
    if (elevator.motorDir == DIRN_UP) {
        for (int i = floor; i < N_FLOORS; i++) { // Corrected loop condition
            if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB]) {
                for (int j = 0; j < N_BUTTONS; j++) { // Corrected loop variable
                    removeOrder(i, j);
                }
                return i;
            }
        }
    }
    if (elevator.motorDir == DIRN_DOWN) {
        for (int i = floor; i >= 0; i--) { // Corrected loop condition
            if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB]) {
                for (int j = 0; j < N_BUTTONS; j++) { // Corrected loop variable
                    removeOrder(i, j);
                }
                return i;
            }
        }
    }
    if (elevator.motorDir == DIRN_STOP) {
        for (int i = floor; i < N_FLOORS; i++) { // Corrected loop condition
            if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB]) {
                for (int j = 0; j < N_BUTTONS; j++) { // Corrected loop variable
                    removeOrder(i, j);
                }
                return i;
            }
        }
        for (int i = floor; i >= 0; i--) { // Corrected loop condition
            if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB]) {
                for (int j = 0; j < N_BUTTONS; j++) { // Corrected loop variable
                    removeOrder(i, j);
                }
                return i;
            }
        }
    }
    return -1;
}



