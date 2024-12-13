#include <iostream>
#include "Header.h"
#include <cmath>

int main() //g++ funcs.cpp input.cpp Task_4.cpp -o Task_4
{
    std::cout << "Введите число: ";
    long long a = llIncorrectInput();

    if (a == -5543)
    {
        std::cout << "Неправильный ввод.\n";
        return 0;
    }

    bool d29 = del(abs(a), 15, 29);
    bool d223 = del(abs(a), 112, 223);
    bool d5 = del(abs(a), 3, 5);

    if (d5 == 1)
    {
        std::cout << "Число делится на 5.\n";
    }
    else if (d5 == 0)
    {
        std::cout << "Число не делится на 5.\n";
    }

    if (d29 == 1)
    {
        std::cout << "Число делится на 29.\n";
    }
    else if (d29 == 0)
    {
        std::cout << "Число не делится на 29.\n";
    }

    if (d223 == 1)
    {
        std::cout << "Число делится на 223.\n";
    }
    else if (d223 == 0)
    {
        std::cout << "Число не делится на 223.\n";
    }

    return 0;
}