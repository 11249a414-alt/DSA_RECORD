#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}
