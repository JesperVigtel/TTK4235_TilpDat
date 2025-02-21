#pragma once
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "elevio.h"
#include <stdbool.h> // Trengs for bool
#include <stdlib.h>  // Trengs for malloc/realloc/free


typedef enum order {
    order_none = -1,
    order_up = BUTTON_HALL_UP,
    order_down = BUTTON_HALL_DOWN,
    order_internal = BUTTON_CAB
} order_t;

typedef struct {
    order_t order;
    int floor;
} Order;

typedef struct {
    Order *orders;
    int numOrders;
} OrderManager;





