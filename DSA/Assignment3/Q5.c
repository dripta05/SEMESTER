#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // For isdigit() and isalpha()

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

// Function prototypes
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(const char *infix, char *postfix);

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    // Remove newline character if present
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to determine if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, k = 0;
    
    while (infix[i] != '\0') {
        if (isspace(infix[i])) {
            i++;
            continue;
        }

        if (isalnum(infix[i])) {  // If the character is an operand (number or letter)
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack);  // Remove the '(' from the stack
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    
    postfix[k] = '\0';  // Null-terminate the postfix expression
}
