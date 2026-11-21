#include <stdio.h>

/* ===== Универсальная функция побайтового вывода ===== */
void print_bytes(const char* name, const void* ptr, size_t size)
{
    const unsigned char* b = (const unsigned char*)ptr;
    printf("%-14s (%2zu байт): ", name, size);
    for (size_t i = 0; i < size; ++i)
        printf("%02x ", b[i]);
    printf("\n");
}

#define SHOW(var) print_bytes(#var, &(var), sizeof(var))

int main(void)
{
    /* ================= Пункт 1 =================
       Побайтовый вывод целого числа 0x12345678 */
    printf("=== Пункт 1: порядок байтов ===\n");
    int x = 0x12345678;
    unsigned char* a = (unsigned char*)&x;

    printf("x = 0x%08x\n", x);
    printf("a+0: %02x\n", a[0]);
    printf("a+1: %02x\n", a[1]);
    printf("a+2: %02x\n", a[2]);
    printf("a+3: %02x\n", a[3]);

    if (a[0] == 0x78)
        printf("-> little-endian (младший байт по младшему адресу)\n");
    else
        printf("-> big-endian (старший байт по младшему адресу)\n");
    printf("\n");

    /* ================= Пункт 2 =================
       Универсальный побайтовый вывод разных типов */
    printf("=== Пункт 2: вывод любого типа ===\n");
    int          i = 0x12345678;
    short        s = 0x1234;
    long long    ll = 0x123456789ABCDEF0LL;
    float        f = 1.0f;
    double       d = 1.0;
    char         c = 'A';

    SHOW(i);
    SHOW(s);
    SHOW(ll);
    SHOW(f);
    SHOW(d);
    SHOW(c);
    printf("\n");

    /* ================= Пункт 3 =================
       Сравнение 12345 в int / float / double */
    printf("=== Пункт 3: число 12345 в разных типах ===\n");
    int    vi = 12345;
    float  vf = 12345.0f;
    double vd = 12345.0;

    print_bytes("int 12345", &vi, sizeof(vi));
    print_bytes("float 12345", &vf, sizeof(vf));
    print_bytes("double 12345", &vd, sizeof(vd));

    printf("\nint    = %d\n", vi);
    printf("float  = %.1f\n", vf);
    printf("double = %.1f\n", vd);

    return 0;
}
