#pragma once
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "driver/elevio.h"
#include <stdbool.h> // Trengs for bool
#include <stdlib.h>  // Trengs for malloc/realloc/free
#include "elevator.h"
#include "elevio.h"

bool queue[N_FLOORS][N_BUTTONS] = { ,{false}}; // 2D array for orders

void addOrder(int floor, int button);
void removeOrder(int floor, int button);
void clearAllOrders();
void printQueue();
int nextOrder(int current_floor, motorDirection dir, int *next_floor, motorDirection *next_dir);


