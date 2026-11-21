#include <stdio.h>
#include <stdbool.h>

/* Макрос: для типа T создаёт переменную x, инициализирует указатель,
   делает ++ и --, печатает адреса и величину шага. */
#define TEST_PTR(T, val)                                              
    do {                                                              
        T *p, x = (val);                                              
        p = &x;                                                       
        unsigned long a1 = (unsigned long)p;                          
        printf("%-18s sizeof=%-2zu  a1=%016lx",                       
               #T, sizeof(T), a1);                                    
        p++;                                                          
        unsigned long a2 = (unsigned long)p;                          
        printf("  a2=%016lx  шаг=%2lu", a2, a2 - a1);                 
        p--;                                                          
        unsigned long a3 = (unsigned long)p;                          
        printf("  возврат=%s\n", (a1 == a3) ? "OK" : "FAIL");         
    } while (0)

int main(void)
{
    printf("=== Арифметика указателей: шаг p++/p-- ===\n\n");

    TEST_PTR(char, 'A');
    TEST_PTR(int, 5);
    TEST_PTR(double, 2.5);
    TEST_PTR(long double, 3.14L);
    TEST_PTR(short unsigned int, 7);
    TEST_PTR(_Bool, 1);

    printf("\n=== Демонстрация на массиве (безопасно) ===\n");

    int arr[2] = { 5, 42 };
    int* p = arr;
    printf("*p     = %d (адрес %p)\n", *p, (void*)p);
    p++;
    printf("*p++   = %d (адрес %p), шаг = %ld байт\n",
        *p, (void*)p, (long)((char*)p - (char*)arr));
    p--;
    printf("*p--   = %d (вернулись)\n", *p);

    return 0;
}
