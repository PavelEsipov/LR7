#include <iostream>
#include "Header.h"

const char signs[62] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
                        'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
                        'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char *perevod(long long s, long long a, int count)
{
    char *str = new char[40];

    long long b = abs(a);
    for (int i = count - 1;; i--) // O(log s (b))
    {
        if (b == 0)
        {
            break;
        }
        str[i] = signs[b % s];
        b /= s;
    }

    return str;
}

int *ids(long long s, long long a, int count)
{
    int *id = new int[40];

    long long b = abs(a);
    for (int i = count - 1;; i--) // O(log s (b))
    {
        if (b == 0)
        {
            break;
        }
        id[i] = b % s;
        b /= s;
    }

    return id;
}

int sopast(char *str1, char *str2, int count1, int count2, int *id1, int *id2)
{
    int count3 = count1;

    if (count1 > count2)
    {
        for (int i = count2 - 1; i >= 0; i--) // O(count2 - 1)
        {
            str2[i + count1 - count2] = str2[i];
            id2[i + count1 - count2] = id2[i];
        }

        for (int i = 0; i < count1 - count2; i++) // O(count1 - count2)
        {
            str2[i] = '0';
            id2[i] = 0;
        }

        count3 = count1;
    }

    if (count1 < count2)
    {
        for (int i = count1 - 1; i >= 0; i--) // O(count1 - 1)
        {
            str1[i + count2 - count1] = str1[i];
            id1[i + count2 - count1] = id1[i];
        }

        for (int i = 0; i < count2 - count1; i++) // O(count2 - count1)
        {
            str1[i] = '0';
            id1[i] = 0;
        }

        count3 = count2;
    }

    return count3;
}

char *sum(long long s, char *str1, char *str2, int count3, int *id1, int *id2)
{

    char *output = new char[count3 + 2];
    output[count3 + 1] = '\0';
    output[0] = ' ';

    bool one = false;
    int k = 0;
    for (int i = count3; i >= 1; i--) // O(count3 - 1)
    {
        if (id1[i - 1] + id2[i - 1] >= s)
        {
            if (one == true)
            {
                k = 1;
            }
            output[i] = signs[id1[i - 1] + id2[i - 1] - s + k];
            k = 0;
            one = true;
        }
        else
        {
            if (one == true && id1[i - 1] + id2[i - 1] + 1 >= s)
            {
                k = 1 - s;
                one = true;
            }

            else if (one == true && id1[i - 1] + id2[i - 1] + 1 < s)
            {
                k = 1;
                one = false;
            }

            output[i] = signs[id1[i - 1] + id2[i - 1] + k];
            k = 0;
        }
    }

    if (one == true)
    {
        output[0] = '1';
    }

    if (output[0] == ' ')
    {
        for (int i = 0; i < count3 + 1; i++)
        {
            output[i] = output[i + 1];
        }
    }

    if (output[0] == '0')
    {
        for (int i = 0; i < count3 + 1; i++)
        {
            output[i] = output[i + 1];
        }
    }

    return output;
}

char *diff(long long s, char *str1, char *str2, int count3, int *id1, int *id2, bool otr)
{
    char *output = new char[count3 + 2];
    output[count3 + 1] = '\0';
    output[0] = ' ';

    if (otr == true)
    {
        output[0] = '-';
    }

    bool one = false;
    int k = 0;
    for (int i = count3; i >= 1; i--) // O(count3 - 1)
    {
        if (id1[i - 1] < id2[i - 1])
        {
            if (one == true)
            {
                k = 1;
            }
            output[i] = signs[id1[i - 1] - id2[i - 1] + s - k];
            k = 0;
            one = true;
        }

        else if (id1[i - 1] > id2[i - 1])
        {
            if (one == true)
            {
                k = 1;
            }
            output[i] = signs[id1[i - 1] - id2[i - 1] - k];
            one = false;
            k = 0;
        }
        else if (id1[i - 1] == id2[i - 1])
        {
            if (one == true)
            {
                output[i] = signs[-1 + s];
                one = true;
            }

            else
            {
                output[i] = signs[0];
                one = false;
            }
        }
    }

    if (output[0] == ' ')
    {
        for (int i = 0; i < count3 + 1; i++)
        {
            output[i] = output[i + 1];
        }
    }

    for (int i = 0; i < count3; i++)
    {
        if (output[0] == '0')
        {
            for (int i = 0; i < count3 + 1; i++)
            {
                output[i] = output[i + 1];
            }
        }
    }

    for (int i = 0; i < count3; i++)
    {
        if (output[1] == '0' && output[0] == '-')
        {
            for (int i = 1; i < count3 + 1; i++)
            {
                output[i] = output[i + 1];
            }
        }
    }

    return output;
}