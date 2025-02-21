#pragma once
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "driver/elevio.h"
#include <stdbool.h> // Trengs for bool
#include <stdlib.h>  // Trengs for malloc/realloc/free
#include "elevator.h"

Elevator elevator;

/*typedef enum {
    order_none = -1,
    order_up = BUTTON_HALL_UP,
    order_down = BUTTON_HALL_DOWN,
    order_internal = BUTTON_CAB
} OrderType;

// enumen order_t er en type som kan ha verdiene order_none, order_up, order_down og order_internal og
// er en type som definerer hvilken type ordre det er snakk om.

typedef struct {
    OrderType order;
    int orderFloor;
} Order;

// structen Order definerer en ordre som består av en order_t og en etasje.

typedef struct {
    Order *orders;
    int numOrders;
} OrderManager;

extern OrderManager orderManager;

// structen OrderManager definerer en ordremanager som består av en peker til en array av Order og en int som
// holder styr på antall ordre.

void orderManager_init(OrderManager *orderManager);
void orderManager_addOrder(OrderManager *orderManager, OrderType order, int orderFloor);
void orderManager_removeOrder(OrderManager *orderManager, OrderType order, int orderFloor);
void stop_and_clear_all_orders(OrderManager *orderManager);
void priority_order(OrderManager *orderManager, motorDirection dir, int orderFloor);
void process_next_order(OrderManager *orderManager, motorDirection dir, int orderFloor);
bool has_pending_orders(OrderManager *orderManager);
int getNextOrder();*/




// ønsker en funksjon som henter neste etasje og bare det, blir det som kommer ut av hele OrderManageren
//fjern OrderManager *orderManager fra funksjonene
//er også mulig å bruke en matrise kontra stucts, er det lettere??


/*Lage en matrise med 4 * 3 kolonner, med type knapp, og etasje. vi har også en prioriteringsliste som går enten 0 (opp)
eller (1) ned. dette gjør at den skifter på rekkefølgen om den skal opp eller ned bare når cab kolonnen har 0 i seg, har den 1 fortsetter logikken.
cab får verdi 0 eller 1 avhengig av hvordan knappene inne i heisen er trykket. den bruker current floor og motorretning for å sjekke elementet i opp og ned og deretter avgjøre om den
skal stoppe på den etasjen eller kjøre videre. */


