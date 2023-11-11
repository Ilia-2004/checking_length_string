#include <iostream>

extern "C" int longStr(char* str)
{
    int length;
    _asm {
            mov ecx, 0
            mov al, str[ecx]
            mov bl, 0

            cikl:
            cmp al, 0
                je endd

                inc ecx
                mov al, str[ecx]
                inc bl

                jmp cikl

                endd :
            mov length, ecx
    }
    return length;
}

int main()
{
    char str[100];

    std::cout << "Введите строку: ";
    std::cin >> str;

    int length = longStr(str);

    std::cout << "Длина строки: " << length;
    return 0;
}