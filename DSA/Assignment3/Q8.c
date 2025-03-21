#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

typedef struct {
    int front, rear, size;
    int array[MAX];
} CircularQueue;

// Function prototypes
void initQueue(CircularQueue *q);
int isQueueEmpty(CircularQueue *q);
int isQueueFull(CircularQueue *q);
void enqueue(CircularQueue *q, int item);
int dequeue(CircularQueue *q);
int getQueueSize(CircularQueue *q);
void displayQueue(CircularQueue *q);

// Menu-driven program
void queueMenu() {
    CircularQueue queue;
    initQueue(&queue);

    int choice, item;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Check Number of Elements\n");
        printf("5. Check Overflow/Underflow\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Number of elements: %d\n", getQueueSize(&queue));
                break;
            case 5:
                if (isQueueFull(&queue)) {
                    printf("Queue is full (Overflow).\n");
                } else if (isQueueEmpty(&queue)) {
                    printf("Queue is empty (Underflow).\n");
                } else {
                    printf("Queue is neither full nor empty.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Function to initialize the queue
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isQueueEmpty(CircularQueue *q) {
    return q->size == 0;
}

// Check if the queue is full
int isQueueFull(CircularQueue *q) {
    return q->size == MAX;
}

// Enqueue an element to the queue
void enqueue(CircularQueue *q, int item) {
    if (isQueueFull(q)) {
        printf("Queue is full, cannot enqueue.\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->array[q->rear] = item;
        q->size++;
    }
}

// Dequeue an element from the queue
int dequeue(CircularQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        int item = q->array[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return item;
    }
}

// Get the number of elements in the queue
int getQueueSize(CircularQueue *q) {
    return q->size;
}

// Display all elements of the queue
void displayQueue(CircularQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i = q->front;
        int count = q->size;
        while (count > 0) {
            printf("%d ", q->array[i]);
            i = (i + 1) % MAX;
            count--;
        }
        printf("\n");
    }
}

// Main function
int main() {
    queueMenu();
    return 0;
}
