#include <stdio.h>
#include <stdlib.h>

// Definition of the structure of a node in the BST
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int key);
Node* insert(Node* root, int key);
Node* deleteNode(Node* root, int key);
Node* search(Node* root, int key);
Node* findMin(Node* root);
Node* findMax(Node* root);
Node* inOrderPredecessor(Node* root, int key);
Node* inOrderSuccessor(Node* root, int key);
void inorderTraversal(Node* root);
void freeTree(Node* root);

// Main function
int main() {
    Node* root = NULL;
    int choice, key;
    Node* temp;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create a BST\n");
        printf("2. Search a key\n");
        printf("3. Find in-order predecessor and successor\n");
        printf("4. Insert a key\n");
        printf("5. Delete a key\n");
        printf("6. Display BST (In-order)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the root key: ");
                scanf("%d", &key);
                root = createNode(key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp != NULL)
                    printf("Key %d found in the BST.\n", key);
                else
                    printf("Key %d not found in the BST.\n", key);
                break;

            case 3:
                printf("Enter the key to find predecessor and successor: ");
                scanf("%d", &key);
                temp = inOrderPredecessor(root, key);
                if (temp != NULL)
                    printf("In-order Predecessor: %d\n", temp->key);
                else
                    printf("No in-order predecessor found.\n");
                temp = inOrderSuccessor(root, key);
                if (temp != NULL)
                    printf("In-order Successor: %d\n", temp->key);
                else
                    printf("No in-order successor found.\n");
                break;

            case 4:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted.\n", key);
                break;

            case 5:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted (if it existed).\n", key);
                break;

            case 6:
                printf("In-order Traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 7:
                freeTree(root);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a key into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

// Find the minimum key in the BST
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Find the maximum key in the BST
Node* findMax(Node* root) {
    while (root->right != NULL) root = root->right;
    return root;
}

// Find in-order predecessor
Node* inOrderPredecessor(Node* root, int key) {
    Node* current = search(root, key);
    if (current == NULL) return NULL;

    if (current->left != NULL) return findMax(current->left);

    Node* ancestor = root;
    Node* predecessor = NULL;
    while (ancestor != current) {
        if (current->key > ancestor->key) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// Find in-order successor
Node* inOrderSuccessor(Node* root, int key) {
    Node* current = search(root, key);
    if (current == NULL) return NULL;

    if (current->right != NULL) return findMin(current->right);

    Node* ancestor = root;
    Node* successor = NULL;
    while (ancestor != current) {
        if (current->key < ancestor->key) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// In-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Free the memory of the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
