#ifndef QUEUE_H
#define QUEUE_H

#include "train.h"

typedef struct node {
        Train *train;
        struct node *next;
} Node;

typedef struct q {
        Node *head;
        Node *tail;
} Queue;

Queue* queueInit();
void enqueue(Queue *, Train *);
Train* dequeue(Queue *);
unsigned int isQueueEmpty(Queue *);
void deleteQueue(Queue *);
#endif
