#include <stdlib.h>
#include <time.h>
#include "test.h"

#define MAX_TESTS 100

// gcc -Wall main.c test.c sort.c

int main(void)
{
    srand(time(NULL));
    int numTests = rand() % MAX_TESTS + 1;
    runTests(numTests);
    return 0;
}