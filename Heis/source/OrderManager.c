
#include "OrderManager.h"

/*
For dynamic array for orderManager
#include "OrderManager.h"

void initOrderManager(struct OrderManager* om, int maxOrders) {
    om->orderQueue = (int*)malloc(maxOrders * sizeof(int));
    om->numOrders = 0;
}

void freeOrderManager(struct OrderManager* om) {
    free(om->orderQueue);
    om->orderQueue = NULL;
    om->numOrders = 0;
}
*/

void addOrder(struct OrderManager* om, int order) {
    om -> orderQueue = realloc(om -> orderQueue, (om -> numOrders + 1) * sizeof(int));
    om -> orderQueue[om -> OrderManager] = order;
    om -> numOrders++;
}


int getNextOrder(struct OrderManager* om) {
    if (om -> numOrders == 0) {
        return -1;  // No orders
    }
    else {
        int order = om -> orderQueue [0]; //Get the first order
        for (int i = 1; i < om -> numOrders; i++) {
            om -> orderQueue[i -1] = om -> orderQueue[i]; //shift all orders to the left
        }
    }
}