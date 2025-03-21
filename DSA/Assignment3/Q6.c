#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // For isdigit()

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
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

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

// Function prototypes
int evaluatePostfix(const char *postfix);

// Main function
int main() {
    char postfix[MAX];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    
    // Remove newline character if present
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

// Function to evaluate postfix expression
int evaluatePostfix(const char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {  // If the character is a digit
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&stack, num);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            int result;

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(1);
            }
            push(&stack, result);
            i++;
        } else {
            printf("Invalid character in expression: %c\n", postfix[i]);
            exit(1);
        }
    }

    return pop(&stack);
}
