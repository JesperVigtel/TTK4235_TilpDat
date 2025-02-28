// Definerer OrderManager-strukturen
/*typedef struct 
    int floor;            // Etasje for ordren
    int direction;        // Retning for ordren
    struct Order *next;   // Peker til neste ordre i køen
} Order;

typedef struct {
    Order *orderQueue;    // Pekeren til første ordre i køen
    int numOrders;        // Antall ordrer i køen
} OrderManager;

// Deklarerer en global OrderManager (defineres i OrderManager.c)
extern OrderManager orderManagerUp;
extern OrderManager orderManagerDown;

// Funksjonsprototyper
void initOrderManager();
void addOrder(int order);
int getNextOrder();
void clearOrders();
bool hasPendingOrders();

#endif // ORDERMANAGER_H*/
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

