#pragma once
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <stdbool.h> // Trengs for bool
#include <stdlib.h>  // Trengs for malloc/realloc/free

// Definerer OrderManager-strukturen
typedef struct {
    int* orderQueue;
    int numOrders;
} OrderManager;

// Deklarerer en global OrderManager (defineres i OrderManager.c)
extern OrderManager orderManager;

// Funksjonsprototyper
void initOrderManager();
void addOrder(int order);
int getNextOrder();
void clearOrders();
bool hasPendingOrders();

#endif // ORDERMANAGER_H
