#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to create an empty stack
void createEmptyStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->items[stack->top--];
}

// Function to get the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->items[stack->top];
}

// Structure for the queue using two stacks
struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

// Function to create an empty queue
void createEmptyQueue(struct Queue* queue) {
    createEmptyStack(&queue->stack1);
    createEmptyStack(&queue->stack2);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    push(&queue->stack1, data);
    printf("%d enqueued into the queue.\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue underflow\n");
        return -1; // Return -1 to indicate an error
    }

    // If stack2 is empty, move elements from stack1 to stack2
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    // Pop from stack2 which gives the front of the queue
    return pop(&queue->stack2);
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return isEmpty(&queue->stack1) && isEmpty(&queue->stack2);
}

// Function to get the number of elements in the queue
int countQueue(struct Queue* queue) {
    return queue->stack1.top + 1 + queue->stack2.top + 1;
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue queue;
    createEmptyQueue(&queue);

    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if queue is empty\n");
        printf("4. Count elements in queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("%d dequeued from the queue.\n", data);
                }
                break;
            case 3:
                if (isQueueEmpty(&queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                printf("Number of elements in the queue: %d\n", countQueue(&queue));
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}