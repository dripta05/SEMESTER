#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the index of a given element in an array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct the binary tree from pre-order and in-order traversals
struct Node* buildTree(int preOrder[], int inOrder[], int start, int end) {
    static int preIndex = 0;

    if (start > end)
        return NULL;

    struct Node* root = createNode(preOrder[preIndex++]);

    if (start == end)
        return root;

    int inIndex = findIndex(inOrder, start, end, root->data);

    root->left = buildTree(preOrder, inOrder, start, inIndex - 1);
    root->right = buildTree(preOrder, inOrder, inIndex + 1, end);

    return root;
}

// Function for in-order traversal (for verification)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    int n = sizeof(preOrder) / sizeof(preOrder[0]);

    struct Node* root = buildTree(preOrder, inOrder, 0, n - 1);

    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}