#ifndef STACK_H
#define STACK_H

typedef struct node {
        int val;
        struct node *next;
} Node;

typedef struct {
        Node *head;
} Stack;

Stack* stackInit();
void push(Stack *s, int val);
int pop(Stack *s);
unsigned char isStackEmpty(Stack *s);
void deleteStack(Stack *s);

#endif
