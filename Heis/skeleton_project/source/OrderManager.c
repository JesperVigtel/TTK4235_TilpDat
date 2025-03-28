#include "OrderManager.h"

bool queue[N_FLOORS][N_BUTTONS] = {{false}};

void addOrder(int floor, int button) {
    if ((floor >= 0 && floor < N_FLOORS) && (button >= 0 && button < N_BUTTONS)) {
        if (queue[floor][button] == 1) {      
            return;
        }
        queue[floor][button] = 1;
        elevio_buttonLamp(floor, button, 1); 
    }
}

void removeFloorOrders(int floor){
    if (floor >= 0 && floor < N_FLOORS)  {
        for (int j = 0; j < N_BUTTONS; j++) {
            queue[floor][j] = 0;
            elevio_buttonLamp(floor, j, 0); 
        }
    }
}
void clearAllOrders() {
    for (int i = 0; i < N_FLOORS; i++) {
        for (int j = 0; j < N_BUTTONS; j++) {
            queue[i][j] = 0; 
            elevio_buttonLamp(i, j, 0); 
        }
    }
    printf("Orde er tømt!");
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
    int floor = elevator.currentFloor;
    if (floor < 0 || elevator.currentFloor >= N_FLOORS) {
        printf("Ugyldig etasje registrert\n");
        return -1;
    }

    switch (elevator.motorDir) {
        case DIRN_UP:
            for (int i = floor; i < N_FLOORS; i++) {
                if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB] || (i == N_FLOORS - 1 && queue[i][BUTTON_HALL_DOWN])) {
                    return i;
                }
            }
            break;

        case DIRN_DOWN:
            for (int i = floor; i >= 0; i--) {
                if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB] || (i == 0 && queue[i][BUTTON_HALL_UP])) {
                    return i;
                }
            }
            break;

        case DIRN_STOP:
            for (int i = 0; i < N_FLOORS; i++) {
                if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB]) {

                    return i;
                }
            }
            for (int i = N_FLOORS - 1; i >= 0; i--) {
                if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB]) {

                    return i;
                }
            }
            break;

        default:
            printf("Ugyldig kjøreretning\n");
            return -1;
    }

    return -1;
}



