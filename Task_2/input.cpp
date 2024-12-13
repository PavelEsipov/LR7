#include <iostream>
# include "Header.h"

long double ldIncorrectInput()
{
    long double a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
        {
        }
        return 0.779;
    }

    return a;
}