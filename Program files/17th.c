#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    printf("LEADING Sets:\n");
    printf("-------------------------\n");

    printf("LEADING(E) = { (, id }\n");
    printf("LEADING(T) = { (, id }\n");
    printf("LEADING(F) = { (, id }\n");

    return 0;
}