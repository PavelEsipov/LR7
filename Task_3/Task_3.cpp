#include <iostream>
#include "Header.h"

int main() // g++ funcs.cpp input.cpp Task_3.cpp -o Task_3
{
    std::cout << "Выберите систему отсчета (от 2 до 62): ";
    long long syst = llIncorrectInput();

    if (syst < 2 || syst > 62)
    {
        std::cout << "Неправильный ввод.\n";
        return 0;
    }

    std::cout << "Введите первое число: ";
    long long a1 = llIncorrectInput();

    if (a1 == -777)
    {
        std::cout << "Неправильный ввод.\n";
        return 0;
    }

    std::cout << "Введите второе число: ";
    long long a2 = llIncorrectInput();

    if (a2 == -777)
    {
        std::cout << "Неправильный ввод.\n";
        return 0;
    }

    long long b1 = abs(a1);
    int count1 = 0;
    while (b1) // O(log syst (b1))
    {
        b1 /= syst;
        count1++;
    }

    long long b2 = abs(a2);
    int count2 = 0;
    while (b2) // O(log syst (b1))
    {
        b2 /= syst;
        count2++;
    }

    char *str1 = perevod(syst, a1, count1);
    char *str2 = perevod(syst, a2, count2);
    

    if (a1 < 0)
    {
        std::cout << "Первое число после перевода: -" << str1 << "\n";
    }
    else
    {
        std::cout << "Первое число после перевода: " << str1 << "\n";
    }

    if (a2 < 0)
    {
        std::cout << "Второе число после перевода: -" << str2 << "\n";
    }
    else
    {
        std::cout << "Второе число после перевода: " << str2 << "\n";
    }

    int *id1 = ids(syst, a1, count1);
    int *id2 = ids(syst, a2, count2);

    int count3 = sopast(str1, str2, count1, count2, id1, id2);

    if (a1 < 0 && a2 < 0 && a1 < a2)
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << "-" << summa << "\n";

        char *di = diff(syst, str1, str2, count3, id1, id2, true);
        std::cout << "Разность: " << di << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 < 0 && a2 < 0 && a1 > a2)
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << "-" << summa << "\n";

        char *di = diff(syst, str2, str1, count3, id2, id1, false);
        std::cout << "Разность: " << di << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 < 0 && a2 > 0 && abs(a1) < abs(a2))
    {
        char *di = diff(syst, str2, str1, count3, id2, id1, false);
        std::cout << "Сумма: " << di << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << "-" << summa << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 < 0 && a2 > 0 && abs(a1) == abs(a2))
    {
        std::cout << "Сумма: 0" << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << "-" << summa << "\n";
        delete[] summa;
    }

    else if (a1 < 0 && a2 > 0 && abs(a1) > abs(a2))
    {
        char *di = diff(syst, str1, str2, count3, id1, id2, true);
        std::cout << "Сумма: " << di << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << "-" << summa << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 > 0 && a2 < 0 && abs(a1) > abs(a2))
    {
        char *di = diff(syst, str1, str2, count3, id1, id2, false);
        std::cout << "Сумма: " << di << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << summa << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 > 0 && a2 < 0 && abs(a1) < abs(a2))
    {
        char *di = diff(syst, str1, str2, count3, id1, id2, true);
        std::cout << "Сумма: " << di << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << summa << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 > 0 && a2 < 0 && abs(a1) == abs(a2))
    {
        std::cout << "Сумма: 0" << "\n";

        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Разность: " << summa << "\n";
        delete[] summa;
    }

    else if (a1 > 0 && a2 > 0 && a1 > a2)
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << summa << "\n";

        char *di = diff(syst, str1, str2, count3, id1, id2, false);
        std::cout << "Разность: " << di << "\n";
        delete[] summa;
        delete[] di;
    }

    else if (a1 > 0 && a2 > 0 && a1 < a2)
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << summa << "\n";

        char *di = diff(syst, str2, str1, count3, id2, id1, false);
        std::cout << "Разность: -" << di << "\n";
        delete[] summa;
        delete[] di;
    }
    else if (a1 == 0 && a2 == 0)
    {
        std::cout << "Сумма: 0" << "\n";
        std::cout << "Разность: 0" << "\n";
    }
    else if ((a1 == 0 && a2 < 0) || (a2 == 0 && a1 > 0))
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << "-" << summa << "\n";

        std::cout << "Разность: " << summa << "\n";
        delete[] summa;
    }
    else if ((a1 == 0 && a2 > 0) || (a2 == 0 && a1 < 0))
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << summa << "\n";

        std::cout << "Разность: -" << summa << "\n";
        delete[] summa;
    }
    else if (a1 == a2)
    {
        char *summa = sum(syst, str1, str2, count3, id1, id2);
        std::cout << "Сумма: " << summa << "\n";

        std::cout << "Разность: 0" << "\n";
        delete[] summa;
    }

    //std::cout << id1[0] << " " << id2[0] << count1 << count2;

    delete[] str1;
    delete[] str2;
    delete[] id1;
    delete[] id2;

    return 0;
}