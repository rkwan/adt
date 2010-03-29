#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* queueInit() {
        Queue *q = malloc(sizeof(Queue));
        if (q == NULL) {
                fprintf(stderr, "Error: queueInit(): failed to malloc");
                exit(1);
        }
        q->head = NULL;
        q->tail = NULL;
        return q;
}

void enqueue(Queue *q, Train *t) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
                fprintf(stderr, 
                "Error: enqueue(Queue*, int): failed to malloc\n");
                exit(1);
        }
        newNode->train = t;
        newNode->next = NULL;
        if (q->head == NULL) {
                q->head = newNode;
                q->tail = newNode;
        }else {
                q->tail->next = newNode;
                q->tail = newNode;
        }
}

Train* dequeue(Queue *q) {
        if (q->head == NULL) {
                fprintf(stderr, "Error: dequeue(Queue): dequeuing of an empty");
                fprintf(stderr, " queue not possible\n");
                exit(1);
        }
        Train *ret = q->head->train;
        Node *tmp = q->head;
        q->head = q->head->next;
        tmp->next = NULL;
        free(tmp);
        return ret;
}

unsigned int isQueueEmpty(Queue *q) {
        if (q->head == NULL) 
                return 1;
        else 
                return 0;
}

void deleteQueue(Queue *q) {
        while(!isQueueEmpty(q)) {
                dequeue(q);
        }
        free(q);
}
