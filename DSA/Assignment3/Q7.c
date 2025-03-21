#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front, rear, size;
    int array[MAX];
} ArrayQueue;

// Function prototypes for array-based queue operations
void initArrayQueue(ArrayQueue *q);
int isArrayQueueEmpty(ArrayQueue *q);
int isArrayQueueFull(ArrayQueue *q);
void enqueueArray(ArrayQueue *q, int item);
int dequeueArray(ArrayQueue *q);
int getArrayQueueSize(ArrayQueue *q);
void displayArrayQueue(ArrayQueue *q);

// Menu-driven program for array-based queue
void arrayQueueMenu() {
    ArrayQueue queue;
    initArrayQueue(&queue);

    int choice, item;

    while (1) {
        printf("\nArray-based Queue Menu:\n");
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
                enqueueArray(&queue, item);
                break;
            case 2:
                item = dequeueArray(&queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                displayArrayQueue(&queue);
                break;
            case 4:
                printf("Number of elements: %d\n", getArrayQueueSize(&queue));
                break;
            case 5:
                if (isArrayQueueFull(&queue)) {
                    printf("Queue is full (Overflow).\n");
                } else if (isArrayQueueEmpty(&queue)) {
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

void initArrayQueue(ArrayQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isArrayQueueEmpty(ArrayQueue *q) {
    return q->size == 0;
}

int isArrayQueueFull(ArrayQueue *q) {
    return q->size == MAX;
}

void enqueueArray(ArrayQueue *q, int item) {
    if (isArrayQueueFull(q)) {
        printf("Queue is full, cannot enqueue.\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->array[q->rear] = item;
        q->size++;
    }
}

int dequeueArray(ArrayQueue *q) {
    if (isArrayQueueEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        int item = q->array[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return item;
    }
}

int getArrayQueueSize(ArrayQueue *q) {
    return q->size;
}

void displayArrayQueue(ArrayQueue *q) {
    if (isArrayQueueEmpty(q)) {
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
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *front, *rear;
    int size;
} LinkedListQueue;

// Function prototypes for linked list-based queue operations
void initLinkedListQueue(LinkedListQueue *q);
int isLinkedListQueueEmpty(LinkedListQueue *q);
void enqueueLinkedList(LinkedListQueue *q, int item);
int dequeueLinkedList(LinkedListQueue *q);
int getLinkedListQueueSize(LinkedListQueue *q);
void displayLinkedListQueue(LinkedListQueue *q);

// Menu-driven program for linked list-based queue
void linkedListQueueMenu() {
    LinkedListQueue queue;
    initLinkedListQueue(&queue);

    int choice, item;

    while (1) {
        printf("\nLinked List-based Queue Menu:\n");
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
                enqueueLinkedList(&queue, item);
                break;
            case 2:
                item = dequeueLinkedList(&queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                displayLinkedListQueue(&queue);
                break;
            case 4:
                printf("Number of elements: %d\n", getLinkedListQueueSize(&queue));
                break;
            case 5:
                if (isLinkedListQueueEmpty(&queue)) {
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

void initLinkedListQueue(LinkedListQueue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isLinkedListQueueEmpty(LinkedListQueue *q) {
    return q->size == 0;
}

void enqueueLinkedList(LinkedListQueue *q, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeueLinkedList(LinkedListQueue *q) {
    if (isLinkedListQueueEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        Node *temp = q->front;
        int item = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        q->size--;
        return item;
    }
}

int getLinkedListQueueSize(LinkedListQueue *q) {
    return q->size;
}

void displayLinkedListQueue(LinkedListQueue *q) {
    if (isLinkedListQueueEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        Node *current = q->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main() {
    int choice;

    while (1) {
        printf("\nQueue Implementation Menu:\n");
        printf("1. Array-based Queue\n");
        printf("2. Linked List-based Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayQueueMenu();
                break;
            case 2:
                linkedListQueueMenu();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
