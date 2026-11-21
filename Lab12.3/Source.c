#include <stdio.h>

int main(void)
{
    /* Инициализация массива на 10 элементов */
    float array[10] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
                       6.6f, 7.7f, 8.8f, 9.9f, 10.10f };

    float* ptr_a;

    /* ---------- 4.1 Имя массива — это адрес ---------- */
    printf("=== 4.1: Имя массива и адреса ===\n");
    printf("array      = %p\n", (void*)array);
    printf("&array[0]  = %p\n", (void*)&array[0]);
    printf("&array     = %p\n", (void*)&array);
    printf("array == &array[0] ? %s\n",
        (array == &array[0]) ? "да" : "нет");
    printf("\n");

    /* ---------- 4.2 Указатель на начало и операции ---------- */
    printf("=== 4.2: Операции с указателем ===\n");
    ptr_a = array;                    /* ptr_a указывает на array[0] */
    printf("ptr_a     = %p, *ptr_a = %.2f\n",
        (void*)ptr_a, *ptr_a);

    /* ptr_a++ — переход к следующему элементу (шаг = sizeof(float)) */
    ptr_a++;
    printf("ptr_a++   -> ptr_a = %p, *ptr_a = %.2f\n",
        (void*)ptr_a, *ptr_a);

    /* ptr_a + 4 — НЕ меняет ptr_a, только вычисляет выражение */
    printf("ptr_a+4   -> %p, *(ptr_a+4) = %.2f  (ptr_a не изменён: %p)\n",
        (void*)(ptr_a + 4), *(ptr_a + 4), (void*)ptr_a);

    /* ptr_a - 2 — тоже выражение, ptr_a не меняется */
    printf("ptr_a-2   -> %p, *(ptr_a-2) = %.2f  (ptr_a не изменён: %p)\n",
        (void*)(ptr_a - 2), *(ptr_a - 2), (void*)ptr_a);
    printf("\n");

    /* ---------- 4.3 Проход в прямом порядке с шагом 2 ---------- */
    printf("=== 4.3: Прямой проход с шагом 2 ===\n");
    ptr_a = array;                    /* снова на начало */
    while (ptr_a < array + 10) {
        printf("ptr_a = %p, *ptr_a = %.2f\n",
            (void*)ptr_a, *ptr_a);
        ptr_a += 2;                   /* шаг +2 элемента (8 байт) */
    }
    printf("\n");

    /* ---------- 4.4 Обратный проход с декрементом ---------- */
    printf("=== 4.4: Обратный проход ===\n");
    /* Указатель на конец массива: один за последним элементом */
    ptr_a = array + 10;               /* = &array[10], за границей */

    do {
        ptr_a--;                      /* шаг назад на 1 элемент */
        printf("ptr_a = %p, *ptr_a = %.2f\n",
            (void*)ptr_a, *ptr_a);
    } while (ptr_a > array);

    return 0;
}
