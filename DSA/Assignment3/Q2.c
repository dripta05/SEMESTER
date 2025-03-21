#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular linked list
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

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (temp->data == data) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }
    while (temp->next != *head && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == *head) {
        printf("Node not found\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Function to solve the Josephus problem
int josephus(int n, int k) {
    struct Node* head = NULL;
    for (int i = 1; i <= n; i++) {
        insertAtEnd(&head, i);
    }
    struct Node* temp = head;
    while (temp->next != temp) {
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        printf("%d ", temp->next->data);
        deleteNode(&head, temp->next->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    return temp->data;
}

int main() {
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    josephus(n, k);
    return 0;
}
