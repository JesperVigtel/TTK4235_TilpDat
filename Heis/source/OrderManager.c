
#include "OrderManager.h"



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
        om -> numOrders --;
        om -> orderQueue = realloc(om -> orderQueue, om -> numOrders * sizeof(int)); //resize the array
        int nextorder = om -> orderQueue[0];
        return nextorder;
    }
}

void clearOrders(struct OrderManager* om) {
    free(om -> orderQueue);
    om -> orderQueue = NULL;
    om -> numOrders = 0;
}

bool hasPendingOrders(struct OrderManager* om) {
    if(om -> numOrders ==0) {
        return false:
    }
    else {
        return true;
    }
}