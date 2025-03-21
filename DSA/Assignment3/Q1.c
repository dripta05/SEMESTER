#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
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
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
    reversePrint(head->next);
    printf("%d ", head->data);
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Update head to the new front
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 1);
    insertAtPosition(&head, 40, 3);
    printf("Linked List: ");
    printList(head);

    // Count nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Print reverse
    printf("Reverse Print: ");
    reversePrint(head);
    printf("\n");

    // Reverse the linked list
    reverseList(&head);
    printf("Reversed Linked List: ");
    printList(head);

    // Delete a node
    deleteAtPosition(&head, 1);
    printf("After Deleting at position 1: ");
    printList(head);

    return 0;
}
