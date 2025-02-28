#pragma once
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <stdbool.h> // Trengs for bool
#include <stdlib.h>  // Trengs for malloc/realloc/free
#include "Elevator.h"
#include "elevio.h" // Include only one elevio.h

extern bool queue[N_FLOORS][N_BUTTONS]; // 2D array for orders

void addOrder(int floor, int button);
void removeOrder(int floor, int button);
void clearAllOrders();
void printQueue();
int nextOrder();

#endif