#include <stdio.h>

#define SIZE_OF(T) ((unsigned long long)((char*)((T*)0 + 1) - (char*)0))

int main(void)
{
    printf("char               = %llu байт\n", SIZE_OF(char));
    printf("short int          = %llu байт\n", SIZE_OF(short int));
    printf("unsigned short int = %llu байт\n", SIZE_OF(unsigned short int));
    printf("int                = %llu байт\n", SIZE_OF(int));
    printf("unsigned char      = %llu байт\n", SIZE_OF(unsigned char));
    printf("wchar_t            = %llu байт\n", SIZE_OF(wchar_t));
    printf("long long int      = %llu байт\n", SIZE_OF(long long int));
    printf("size_t             = %llu байт\n", SIZE_OF(size_t));
    printf("float              = %llu байт\n", SIZE_OF(float));
    printf("double             = %llu байт\n", SIZE_OF(double));
    printf("signed int         = %llu байт\n", SIZE_OF(signed int));
    printf("long double        = %llu байт\n", SIZE_OF(long double));
    return 0;
}
