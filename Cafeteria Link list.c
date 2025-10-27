#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 32


// ===== Order (Student) structure =====
typedef struct {
    int id;                     // Order or student number
    char customer[NAME_LEN];    // Student name
} Order;


// ===== Node structure =====
typedef struct Node {
    Order data;
    struct Node* next;
} Node;


// ===== Queue structure =====
typedef struct {
    Node* head;  // Front (first student)
    Node* tail;  // Rear (last student)
    int length;
} Queue;


// ===== Initialize queue =====
void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
}


// ===== Check if queue is empty =====
int isEmpty(Queue* q) {
    return q->length == 0;
}


// ===== Enqueue: add student at end =====
int enqueue(Queue* q, Order order) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return 0; // memory allocation failed
    newNode->data = order;
    newNode->next = NULL;


    if (isEmpty(q)) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->length++;
    printf("%s joined the cafeteria line.\n", order.customer);
    return 1;
}


// ===== Dequeue: remove student from front =====
int dequeue(Queue* q, Order* order, char server[]) {
    if (isEmpty(q)) return 0;


    Node* temp = q->head;
    *order = temp->data;
    printf("%s served food to %s.\n", server, order->customer);


    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;


    free(temp);
    q->length--;
    return 1;
}


// ===== Peek front student =====
int peek(Queue* q, Order* order) {
    if (isEmpty(q)) return 0;
    *order = q->head->data;
    return 1;
}


// ===== Display the queue =====
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nCafeteria line: ");
    Node* cur = q->head;
    while (cur) {
        printf("%s ", cur->data.customer);
        cur = cur->next;
    }
    printf("\n");
}


// ===== Main function =====
int main() {
    Queue cafeteria;
    initQueue(&cafeteria);
    char server[] = "Sokha"; // Cafeteria staff name


    // Students waiting in line
    Order s1 = {1, "Rany"};
    Order s2 = {2, "Moly"};
    Order s3 = {3, "Kim"};
    Order s4 = {4, "Nita"};
    Order s5 = {5, "Chhialy"};


    enqueue(&cafeteria, s1);
    enqueue(&cafeteria, s2);
    enqueue(&cafeteria, s3);
    enqueue(&cafeteria, s4);
    enqueue(&cafeteria, s5);


    displayQueue(&cafeteria);


    printf("\nNext to be served: %s\n", cafeteria.head->data.customer);
    printf("\nServing begins:\n");


    Order served;
    dequeue(&cafeteria, &served, server);
    dequeue(&cafeteria, &served, server);
    displayQueue(&cafeteria);


    dequeue(&cafeteria, &served, server);
    dequeue(&cafeteria, &served, server);
    dequeue(&cafeteria, &served, server);


    printf("\nAll students have been served. Queue is now empty.\n");


    return 0;
}

