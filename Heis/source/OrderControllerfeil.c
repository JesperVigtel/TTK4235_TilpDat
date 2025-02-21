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
