#include <iostream>
#include <iomanip>
#include "Header.h"

int main() // g++ perevod.cpp Task_1.cpp -o Task_1
{
    char *str = new char[1000];

    std::cout << "Введите число в обратном коде: ";
    std::cin >> str;

    int count = 0;
    for (int i = 0;; i++) // O(длина строки)
    {
        if (str[i] == 0)
        {
            break;
        }
        count++;
    }

    long double output = perevod(str, count);

    if (output == 5)
    {
        std::cout << "Неверный ввод.\n\n";
        return 0;
    }

    if (str[0] == '1')
    {
        for (int i = 1; i < count; i++) // O(count-1)
        {
            if (str[i] == '1')
            {
                str[i] = '0';
            }

            else if (str[i] == '0')
            {
                str[i] = '1';
            }
        }
    }

    std::cout << "Число в естественной форме: " << std::setprecision(20) << output << "\n\n";

    delete[] str;

    return 0;
}