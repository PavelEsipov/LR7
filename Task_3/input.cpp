#include <iostream>
# include "Header.h"

long long llIncorrectInput()
{
    long long a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
        {
        }
        return -777;
    }

    return a;
}