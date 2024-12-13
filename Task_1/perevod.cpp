#include <iostream>
#include "Header.h"
#include <cmath>

long double perevod(char *str, int count)
{
    int dot_id = -1;
    int dots = 0;

    for (int i = 0; i < count; i++) // O(count)
    {
        if ((str[i] < 48 || str[i] > 49) && str[i] != 46)
        {
            return 5;
        }

        if (str[i] == 46)
        {
            dots++;
            dot_id = i;
        }

        if (dot_id == 0 || dot_id == count - 1)
        {
            return 5;
        }

        if (dots > 1)
        {
            return 5;
        }
    }

    if (str[0] == '1')
    {
        for (int i = 1; i < count; i++) // O(count -1)
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

    long double output = 0;

    if (str[0] == '1')
    {
        if (dot_id != -1)
        {
            for (int i = 1; i < dot_id; i++) // O(dot_id-1)
            {
                if (str[i] == '1')
                {
                    output -= pow(2, dot_id - i - 1);
                }
            }

            for (int i = dot_id + 1; i < count; i++) // O(dot_id - count + 1)
            {
                if (str[i] == '1')
                {
                    output -= pow(2, dot_id - i);
                }
            }
        }

        else
        {
            for (int i = 1; i < count; i++) // O(count-1)
            {
                if (str[i] == '1')
                {
                    output -= pow(2, count - i - 1);
                }
            }
        }
    }

    if (str[0] == '0')
    {
        if (dot_id != -1)
        {
            for (int i = 1; i < dot_id; i++)  // O(dot_id-1)
            {
                if (str[i] == '1')
                {
                    output += pow(2, dot_id - i - 1);
                }
            }

            for (int i = dot_id + 1; i < count; i++) // O(dot_id - count + 1)
            {
                if (str[i] == '1')
                {
                    output += pow(2, dot_id - i);
                }
            }
        }

        else
        {
            for (int i = 1; i < count; i++) // O(count-1)
            {
                if (str[i] == '1')
                {
                    output += pow(2, count - i - 1);
                }
            }
        }
    }

    return output;
}
