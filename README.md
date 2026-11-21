# Домашняя работа
# Описание программы
Задание 3. 
Домашнее задание ***
Напишите программу, которая вычисляет размер основных типов данных в байтах:

1) char

2) short int

3) unsigned short int

4) int

5) unsigned char

6) wchar_t

7) long long int

8) size_t

9) float

10) double

11) signed int

12) 

!НЕЛЬЗЯ ПОЛЬЗОВАТЬСЯ sizeof  и КОНСТАНТАМИ ИЗ limits.h и float.h

# Алгоритм и блок-схема

Постановка задачи
Вычислить и вывести на экран размеры базовых типов данных (в байтах). Запрещено использовать оператор sizeof, а также константы из <limits.h> и <float.h>.

Идея решения
В языке C арифметика указателей устроена так, что прибавление 1 к указателю типа T* сдвигает адрес ровно на sizeof(T) байт. Если взять «нулевой» указатель (T*)0, прибавить к нему 1 и вычесть из результата исходный (T*)0, приведя оба к char* (байтовому типу), мы получим размер типа T в байтах.

Словесный алгоритм
Шаг 1. Определение макроса SIZE_OF(T).

Взять нулевой указатель типа T*: p = (T*)0.

Прибавить к нему 1: p_next = p + 1 (сдвиг на один элемент типа T).

Привести оба указателя к char* (указатель на байт).

Вычислить разность: size = (char*)p_next - (char*)p.

Привести результат к unsigned long long и вернуть его.

Шаг 2. Начало выполнения main().
Вывести заголовок программы.

Шаг 3. Вычисление размеров типов.
Для каждого типа из списка:

char

short int

unsigned short int

int

unsigned char

wchar_t

long long int

size_t

float

double

signed int

long double

выполнить:

Вычислить SIZE_OF(T).

Вывести на экран строку <имя типа> = <размер> байт.

Шаг 4. Завершение работы.
Вернуть 0 и завершить программу.

<img width="549" height="838" alt="{BDB235A8-91E2-4EF9-9C27-C06249EA5DE3}" src="https://github.com/user-attachments/assets/9730eb22-7d96-4f07-afcd-62058851696b" />


# Реализация программы

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

# Информация о разработчике
Попова Елена, БТИИ 262
