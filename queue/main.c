#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {

        Queue *q = queueInit();
        Train *t1 = createTrain(0, HIGH, EAST, 10, 43);
        Train *t2 = createTrain(1, LOW, WEST, 24, 63);
        Train *t3 = createTrain(2, LOW, WEST, 23, 72);
        
        enqueue(q, t1);
        enqueue(q, t2);
        enqueue(q, t3);

        Train *t;
        while (!isQueueEmpty(q)) {
                printTrain(t = dequeue(q));
                free(t);
        }
        deleteQueue(q);
        
        return 0;
}
