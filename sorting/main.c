#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "test.h"
#include "sort.h"

#define MAX_TESTS 100

// gcc -Wall main.c test.c sort.c

int main(void)
{
    srand(time(NULL));
    int numTests = rand() % MAX_TESTS + 1;

    printf("Running %d Insertion Sort tests\n", numTests);
    runTests(insertionSort, numTests);

    printf("\nRunning %d Selection Sort tests\n", numTests);
    runTests(selectionSort, numTests);
    return 0;
}