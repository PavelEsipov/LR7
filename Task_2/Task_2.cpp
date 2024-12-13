#include <iostream>
#include "Header.h"

int main() // g++ funcs.cpp input.cpp Task_2.cpp -o Task_2
{

    std::cout << "Введите первое слагаемое: ";
    long double a1 = ldIncorrectInput();

    if (a1 == 0.779)
    {
        std::cout << "Неверный ввод.\n\n";
        return 0;
    }

    std::cout << "Введите второе слагаемое: ";
    long double a2 = ldIncorrectInput();

    if (a2 == 0.779)
    {
        std::cout << "Неверный ввод.\n\n";
        return 0;
    }

    long long b1 = (long long)a1;
    int count1 = 0;

    while (b1) // O(log b1)
    {
        b1 /= 2;
        count1++;
    }

    long long b2 = (long long)a2;
    int count2 = 0;

    while (b2) // O(log b2)
    {
        b2 /= 2;
        count2++;
    }

    int count3;

    if (count1 > count2)
    {
        count3 = count1;
    }

    else
    {
        count3 = count2;
    }

    bool drob = true;

    if(a1 - (long long)a1 == 0 && a2 - (long long)a2 == 0){
        drob = false;
    }

    char *str1 = perevod(a1, count3, drob);
    char *str2 = perevod(a2, count3, drob);
    char *str3 = str3_func(drob, count3);
    
    std::cout << "Первое число в обратном коде: " << str1 << "\n";
    std::cout << "Второе число в обратном коде: " << str2 << "\n";

    char* result = sum(str1, str2, str3, count3, drob);

    std::cout << "Результат сложения в дополнительном коде: " << result << "\n";

    delete[] str1;
    delete[] str2;
    delete[] str3;
    delete[] result;

    return 0;
}