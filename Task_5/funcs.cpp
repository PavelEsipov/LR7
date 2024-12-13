#include "Header.h"

int countOnes(int x)
{
    int bitCount = 0;
    while (x) //O(log x)
    {
        if (x & 1)
        {
            bitCount++;
        }
        x >>= 1;
    }
    return bitCount;
}

void feelgr(int divisions[])
{
    divisions[0] = 0;
    divisions[1] = 32;

    for (int i = 1; i <= 29; ++i) //O(29)
    {
        int bitCount = countOnes(i);
        int step = 0;

        if (bitCount == 1)
        {
            step = 16;
        }
        else if (bitCount == 2)
        {
            step = 8;
        }
        else if (bitCount == 3)
        {
            step = 4;
        }
        else if (bitCount == 4)
        {
            step = 2;
        }

        divisions[i + 1] = divisions[i] + step;
    }
}

void getOneBit(int x, int positions[], int &total)
{ 
    total = 0;
    int idx = 0;
    while (x > 0) //O(log x)
    {
        if (x & 1)
        {
            positions[total++] = idx;
        }
        x >>= 1;
        idx++;
    }
}

void findgr(const int divisions[], bool testers[], const bool containers[])
{ 
    for (int i = 0; i < 29; ++i) //O(29)
    {
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount);

        for (int j = 0; j < bitCount; ++j) //O(bitCount)
        {
            for (int k = divisions[i]; k < divisions[i + 1]; ++k)
            {
                if (!testers[bits[j]])
                {
                    testers[bits[j]] = containers[k];
                }
            }
        }
    }
}

int numgrbar(const bool testers[])
{ 
    int index = 0;
    int multiplier = 1;
    for (int i = 0; i < 5; ++i) //O(5)
    {
        index += testers[i] * multiplier;
        multiplier *= 2;
    }
    return index;
}

void killedslaves(bool testers[])
{ 
    for (int i = 0; i < 5; ++i) //O(5)
    {
        testers[i] = false;
    }
}

void findbar(int index, const int divisions[], bool testers[], const bool containers[])
{ 
    for (int k = divisions[index], i = 0; k < divisions[index + 1]; ++k, ++i) //O(divisions[index+1] - divisions[index])
    {
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount);

        for (int j = 0; j < bitCount; ++j) //O(bitCount)
        {
            if (!testers[bits[j]])
            {
                testers[bits[j]] = containers[k];
            }
        }
    }
}

int Input()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
        {
        }
        return 0;
    }

    return a;
}