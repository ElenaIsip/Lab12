#include <stdio.h>

int main(void)
{
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;

    printf("p1  = %p,  *p1 = %g\n", (void*)p1, *p1);
    printf("p2  = %p,  *p2 = %g\n", (void*)p2, *p2);
    printf("p1 (hex) = %lx\n", (unsigned long)p1);
    printf("p2 (hex) = %lx\n", (unsigned long)p2);
    printf("p1 == p2 ? %s\n", (p1 == p2) ? "да" : "нет");

    return 0;
}
