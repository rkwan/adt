#include <stdio.h>
#include "stack.h"

int main() {
        Stack *s = stackInit();
        push(s, 4);
        push(s, 2);
        push(s, 6);
        push(s, 9);
        push(s, 7);
        while (!isStackEmpty(s)) {
                fprintf(stdout, "%d\n", pop(s));
        }
	deleteStack(s);

        return 0;
}
