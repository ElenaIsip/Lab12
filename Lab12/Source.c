#include <stdio.h>

int main() {
    char* pc;
    int* pi;
    double* pd;

    char   c = 'A';
    int    i = 5;
    double d = 2.5;

    pc = &c;
    pi = &i;
    pd = &d;

    printf("sizeof(char*)   = %lu байт\n", sizeof(pc));
    printf("sizeof(int*)    = %lu байт\n", sizeof(pi));
    printf("sizeof(double*) = %lu байт\n", sizeof(pd));

    printf("\nАдреса указывают на:\n");
    printf("*pc = %c\n", *pc);
    printf("*pi = %d\n", *pi);
    printf("*pd = %.2f\n", *pd);

    return 0;
}
