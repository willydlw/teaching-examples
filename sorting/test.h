#ifndef TEST_H
#define TEST_H

#define MAX_ARRAY_LENGTH 100

void randomFill(int* arr, int n);

void testSort(void (*sortFunc)(int*, int), int* arr, int n);

void runTests(int numTests);

#endif 