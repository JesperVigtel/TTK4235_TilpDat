#include "OrderManager.h"

bool queue[N_FLOORS][N_BUTTONS] = {{false}};

void addOrder(int floor, int button) {
    if ((floor >= 0 && floor < N_FLOORS) && (button >= 0 && button < N_BUTTONS)) {
        if (queue[floor][button] == 1) {      // check if an order already exists, not necessary with duplicate
            return;
        }
        queue[floor][button] = 1;
        elevio_buttonLamp(floor, button, 1); //Turn on button Lamp
    }
}

void removeFloorOrders(int floor){
    if (floor >= 0 && floor < N_FLOORS)  {
        for (int j = 0; j < N_BUTTONS; j++) {
            queue[floor][j] = 0;
            elevio_buttonLamp(floor, j, 0); //Turn off button Lamp
        }
    }
}
void clearAllOrders() {
    for (int i = 0; i < N_FLOORS; i++) {
        for (int j = 0; j < N_BUTTONS; j++) {
            queue[i][j] = 0; // clear all orders
            elevio_buttonLamp(i, j, 0); // Turn off Button Lamp
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
    if (floor || elevator.currentFloor >= N_FLOORS) {
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
// int nextOrder() {
//     if (elevator.currentFloor < 0 || elevator.currentFloor >= N_FLOORS) {
//         printf("Ugyldig etasje registrert\n");
//         return -1;
//     }


//     if (elevator.motorDir == DIRN_STOP) {
//         for (int j = 0; j < N_BUTTONS; j++) {
//             if (queue[elevator.currentFloor][j]) {
//                 removeFloorOrders(elevator.currentFloor);
//                 return elevator.currentFloor;
//             }
//         }
//     }

//     if (elevator.motorDir == DIRN_UP) {
//         for (int i = elevator.currentFloor; i < N_FLOORS; i++) { 
//             if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB] || (i == N_FLOORS - 1 && queue[i][BUTTON_HALL_DOWN])) {
//                 // if (i == elevator.currentFloor && elevio_floorSensor() != -1) { 
//                 //     removeFloorOrders(i);
//                 // }
//                 return i;
//             }
//         }
//     }

//     if (elevator.motorDir == DIRN_DOWN) {
//         for (int i = elevator.currentFloor; i >= 0; i--) {
//             if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB] || (i == 0 && queue[i][BUTTON_HALL_UP])) {
//                 // if (i == elevator.currentFloor && elevio_floorSensor() != -1) { 
//                 //     removeFloorOrders(i);
//                 // }
                
//                 return i;
//             }
//         }
//     }

//     if (elevator.motorDir == DIRN_STOP) {
//         for (int i = 0; i < N_FLOORS; i++) { 
//             if (queue[i][BUTTON_HALL_UP] || queue[i][BUTTON_CAB]) {
//                 if (i == elevator.currentFloor && elevio_floorSensor() != -1) {
//                     removeFloorOrders(i);
//                 }
//                 return i;
//             }
//         }
//         for (int i = N_FLOORS-1; i >= 0; i--) { 
//             if (queue[i][BUTTON_HALL_DOWN] || queue[i][BUTTON_CAB]) {
//                 if (i == elevator.currentFloor && elevio_floorSensor() != -1) {
//                     removeFloorOrders(i);
//                 }

//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// fiks at heisen ikke automatisk fikser bestilling i etasjen du tidligere var i
// åpne døren om den er i en etasje og det er en ordre i den etasjen når den trykkes
// fiks stoppknapp og at den får tatt alle ordre i motsatt kjøreretning




