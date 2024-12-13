#include <iostream>
#include "Header.h"

int main() //g++ funcs.cpp Task_5.cpp -o Task_5
{
    bool rabs[5] = {false};
    int gps[31];
    bool bar[240] = {false};

    feelgr(gps);

    std::cout << "Введите номер бочки: ";

    int n = Input();

    if (n < 1 || n > 240)
    {
        std::cout << "Неверный ввод.";
        return 0;
    }

    bar[n - 1] = true;

    findgr(gps, rabs, bar);

    int a = numgrbar(rabs);
    
    killedslaves(rabs);

    findbar(a, gps, rabs, bar);
    int b = numgrbar(rabs) + gps[a] + 1;
    std::cout << "Отравленная бочка: " << b << '\n';

    return 0;
}