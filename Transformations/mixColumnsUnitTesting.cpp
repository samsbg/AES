#include <iostream>
using namespace std;

bool mixColumnsTest1()
{
    // Expected State
    unsigned char state[4][4] = {
        {0x87, 0xf2, 0x4d, 0x97},
        {0x6e, 0x4c, 0x90, 0xec},
        {0x46, 0xe7, 0x4a, 0xc3},
        {0xa6, 0x8c, 0xd8, 0x95}};

    // Original state
    unsigned char expected[4][4] = {
        {0x47, 0x40, 0xa3, 0x4c},
        {0x37, 0xd4, 0x70, 0x9f},
        {0x94, 0xe4, 0x3a, 0x42},
        {0xed, 0xa5, 0xa6, 0xbc}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool mixColumnsTest2()
{
    // Expected State
    unsigned char state[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xdb, 0x39, 0x02, 0xde},
        {0x87, 0x53, 0xd2, 0x96},
        {0x3b, 0x89, 0xf1, 0x1a}};

    // Original state
    unsigned char expected[4][4] = {
        {0x58, 0x1b, 0xdb, 0x1b},
        {0x4d, 0x4b, 0xe7, 0x6b},
        {0xca, 0x5a, 0xca, 0xb0},
        {0xf1, 0xac, 0xa8, 0xe5}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool mixColumnsTest3()
{
    // Expected State
    unsigned char state[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0xc1, 0xb5, 0x23, 0x73},
        {0xd6, 0x5a, 0xcf, 0x11},
        {0xb8, 0x7b, 0xdf, 0xb5}};

    // Original state
    unsigned char expected[4][4] = {
        {0x75, 0x20, 0x53, 0xbb},
        {0xec, 0x0b, 0xc0, 0x25},
        {0x09, 0x63, 0xcf, 0xd0},
        {0x93, 0x33, 0x7c, 0xdc}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{
}