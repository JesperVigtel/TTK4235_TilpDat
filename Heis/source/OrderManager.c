#include "OrderManager.h"
#include "elevio.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


void addOrder(int floor, int button) {
    if (floor >= 0 || floor < N_FLOORS && button >= 0 || button < N_BUTTONS) {
        queue[floor][button] = 1;
        elevio_buttonLamp(floor, button, 1); //Turn on button Lamp
    }
}

void removeOrder(int floor, int button){
    if (floor >= 0 || floor < N_FLOORS && button >= 0 || button < N_BUTTONS) {
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
    for (int i = 0; i < FLOORS; i++) {
        printf("Etasje %d: ", i);
        for (int j = 0; j < BUTTONS; j++) {
            printf(" %d ", queue[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nextOrder(int current_floor, ButtonType Button,) {
    int current_floor = elevio_floorSensor();
    
    
    return -1;
}



