#include <iostream>
#include "Header.h"
#include <cmath>

char *str3_func(bool drob, int count)
{
    int s = 0;

    if (drob == true)
    {
        s = 20;
    }

    char *str = new char[count + 3 + s];

    for (int i = 0; i < count + 3 + s; i++) // O(count + 3 +s)
    {
        str[i] = '0';
    }

    if (drob == true)
    {
        str[count + 2] = '.';
    }

    str[count + 2 + s] = '\0';
    str[count + 1 + s] = '1';

    return str;
}

char *perevod(long double a, int count, bool drob)
{
    int s = 0;

    if (drob == true)
    {
        s = 20;
    }

    char *str = new char[count + 3 + s];

    if (a < 0)
    {
        str[0] = '1';
    }

    else
    {
        str[0] = '0';
    }

    long long b = fabsl((long long)a);

    for (int i = count + 1; i >= 1; i--) // O(count)
    {
        if (b % 2 == 1)
        {
            str[i] = '1';
        }
        else
        {
            str[i] = '0';
        }

        b /= 2;
    }

    long double c = fabsl(a - (long long)a);

    for (int i = count + 3; i < count + 2 + s; i++) // O(s-1)
    {
        c *= 2.0;
        if (c >= 1.0)
        {
            str[i] = '1';
            c -= 1.0;
        }
        else
        {
            str[i] = '0';
        }
    }

    str[count + 2 + s] = '\0';

    if (drob == true)
    {
        str[count + 2] = '.';
    }

    if (str[0] == '1')
    {
        for (int i = 1; i < count + 3 + s; i++) // O(count +2 +s)
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

    return str;
}

char *sum(char *str1, char *str2, char *str3, int count, bool drob)
{
    int s = 0;

    if (drob == true)
    {
        s = 20;
    }

    char *result = new char[count + 3 + s];

    if (drob == true)
    {
        result[count + 2] = '.';
    }

    result[count + 2 + s] = '\0';

    bool one = false;

    for (int i = count + s + 1; i >= 0; i--) // O(count +s+1)
    {
        if (str1[i] == '0')
        {
            if (str2[i] == '0' && one == false)
            {
                result[i] = '0';
                one = false;
            }
            else if (str2[i] == '0' && one == true)
            {
                result[i] = '1';
                one = false;
            }
            else if (str2[i] == '1' && one == false)
            {
                result[i] = '1';
                one = false;
            }
            else if (str2[i] == '1' && one == true)
            {
                result[i] = '0';
                one = true;
            }
        }

        else if (str1[i] == '1')
        {
            if (str2[i] == '0' && one == false)
            {
                result[i] = '1';
                one = false;
            }
            else if (str2[i] == '0' && one == true)
            {
                result[i] = '0';
                one = true;
            }
            else if (str2[i] == '1' && one == false)
            {
                result[i] = '0';
                one = true;
            }
            else if (str2[i] == '1' && one == true)
            {
                result[i] = '1';
                one = true;
            }
        }
    }

    if (one == true)
    {
        one = false;
        for (int i = count + 1 + s; i >= 0; i--) //O(count + 1 + s)
        {
            if (str3[i] == '0')
            {
                if (result[i] == '0' && one == false)
                {
                    result[i] = '0';
                    one = false;
                }
                else if (result[i] == '0' && one == true)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '1' && one == false)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '1' && one == true)
                {
                    result[i] = '0';
                    one = true;
                }
            }

            else if (str3[i] == '1')
            {
                if (result[i] == '0' && one == false)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '0' && one == true)
                {
                    result[i] = '0';
                    one = true;
                }
                else if (result[i] == '1' && one == false)
                {
                    result[i] = '0';
                    one = true;
                }
                else if (result[i] == '1' && one == true)
                {
                    result[i] = '1';
                    one = true;
                }
            }
        }
    }

    std::cout << "Результат сложения в обратном коде: " << result << "\n";

    if (result[0] == '1')
    {
        int f = 0;
        if (drob == true)
        {
            f = 20;
        }

        for (int i = count + 1 + f; i >= 0; i--) //O(count + 1 + f)
        {
            if (str3[i] == '0')
            {
                if (result[i] == '0' && one == false)
                {
                    result[i] = '0';
                    one = false;
                }
                else if (result[i] == '0' && one == true)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '1' && one == false)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '1' && one == true)
                {
                    result[i] = '0';
                    one = true;
                }
            }

            else if (str3[i] == '1')
            {
                if (result[i] == '0' && one == false)
                {
                    result[i] = '1';
                    one = false;
                }
                else if (result[i] == '0' && one == true)
                {
                    result[i] = '0';
                    one = true;
                }
                else if (result[i] == '1' && one == false)
                {
                    result[i] = '0';
                    one = true;
                }
                else if (result[i] == '1' && one == true)
                {
                    result[i] = '1';
                    one = true;
                }
            }
        }
    }

    return result;
}
