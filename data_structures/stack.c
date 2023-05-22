#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1; // エラーコードとして-1を返す
    }
    
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No top element.\n");
        return -1; // エラーコードとして-1を返す
    }
    
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initializeStack(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    int poped = pop(&stack);
    printf("%d",poped);
    printf("\n");
    while(!isEmpty(&stack)){
        printf("%d",pop(&stack));
        printf("\n");
    }
    return 0;
}
