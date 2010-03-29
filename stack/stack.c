#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* stackInit() {
	Stack *stack = malloc(sizeof(Stack));
	if (stack == NULL) {
		fprintf(stderr, "Error: stackInit(): failed to malloc");
		exit(1);
	}
	stack->head = NULL;
	return stack;
}

void push(Stack *s, int val) {
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL) {
		fprintf(stderr, "Error: push(): failed to malloc");
		exit(1);
	}
	newNode->val = val;
	if (s->head == NULL) {
		s->head = newNode;
	}else {
		newNode->next = s->head;
		s->head = newNode;
	}
}

int pop(Stack *s) {
	if (s->head == NULL) {
		fprintf(stderr, "Error: pop(): stack underflow.\n");
		exit(1);
	}
	int ret = s->head->val;
	Node *tmp = s->head;
	s->head = s->head->next;
	tmp->next = NULL;
	free(tmp);
	return ret;
}

unsigned char isStackEmpty(Stack *s) {
	if (s->head == NULL)
		return 1;
	else 
		return 0;
}

void deleteStack(Stack *s) {
	while (!isStackEmpty(s))
		pop(s);
	free(s);
}

