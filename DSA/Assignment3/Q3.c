#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from a specified position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to print the linked list in reverse order
void reversePrint(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    // Move to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Print in reverse
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev; // Swap next and prev
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }
    if (temp != NULL) {
        *head = temp->prev; // Update head to the new front
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate the doubly linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 1);
    insertAtPosition(&head, 40, 3);
    printf("Doubly Linked List: ");
    printList(head);

    // Count nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Print reverse
    printf("Reverse Print: ");
    reversePrint(head);

    // Reverse the linked list
    reverseList(&head);
    printf("Reversed Doubly Linked List: ");
    printList(head);

    // Delete a node
    deleteAtPosition(&head, 1);
    printf("After Deleting at position 1: ");
    printList(head);

    return 0;
}