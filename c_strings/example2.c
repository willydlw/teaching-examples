#include <stdio.h>

int main()
{
    char* greeting = "Hello";
    printf("greeting: %s, sizeof(greeting): %zu\n", greeting, sizeof(greeting));
    return 0;
}