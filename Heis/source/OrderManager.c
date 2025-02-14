#include "OrderManager.h"
#include <stdlib.h>
#include <stdio.h>

// Global variabel
OrderManager orderManager;

// Initialiseringsfunksjon
void initOrderManager() {
    orderManager.orderQueue = NULL;
    orderManager.numOrders = 0;
}


void addOrder(int order) {
    if (order < 0 || order > 3) {
        printf("Feil: Ugyldig ordre!\n");
        return;
    }
    else {
    orderManager.orderQueue = realloc(orderManager.orderQueue, (orderManager.numOrders + 1) * sizeof(int));
    if (!orderManager.orderQueue) {
        printf("Feil: Klarte ikke å allokere minne!\n");
        return;
    }
    orderManager.orderQueue[orderManager.numOrders] = order;
    orderManager.numOrders++;
}
}


int getNextOrder() {
    if (orderManager.numOrders == 0) {
        return -1;  // Ingen ordrer
    }

    int order = orderManager.orderQueue[0]; // Henter første ordre

    // Flytter alle elementene én plass til venstre
    for (int i = 1; i < orderManager.numOrders; i++) {
        orderManager.orderQueue[i - 1] = orderManager.orderQueue[i];
    }

    orderManager.numOrders--;
    orderManager.orderQueue = realloc(orderManager.orderQueue, orderManager.numOrders * sizeof(int));

    return order;
}

void clearOrders() {
    free(OrderManager.orderQueue);
    OrderManager.orderQueue = NULL;
    OrderManager.numOrders = 0;
}

bool hasPendingOrders() {
    return orderManager.numOrders > 0;
}

