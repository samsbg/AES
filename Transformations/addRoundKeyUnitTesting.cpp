#include "AESmethods.h"
#include <iostream>
using namespace std;

// Test 1/2 for add round key
bool addRoundKeyTest1()
{
    unsigned char state[4][4] = {
        {0x32, 0x88, 0x31, 0xe0},
        {0x43, 0x5a, 0x31, 0x37},
        {0xf6, 0x30, 0x98, 0x07},
        {0xa8, 0x8d, 0xa2, 0x34}};

    unsigned char key[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char expected[4][4] = {
        {0x19, 0xa0, 0x9a, 0xe9},
        {0x3d, 0xf4, 0xc6, 0xf8},
        {0xe3, 0xe2, 0x8d, 0x48},
        {0xbe, 0x2b, 0x2a, 0x08}};

    addRoundKey(state, key);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[i][j] != expected[i][j])
            {
                cout << "Add round key T1 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// Test 2/2 for add round key
bool addRoundKeyTest2()
{
    unsigned char state[4][4] = {
        {0xe9, 0xcb, 0x3d, 0xaf},
        {0x31, 0x32, 0x2e, 0x09},
        {0x7d, 0x2c, 0x89, 0x07},
        {0xb5, 0x72, 0x5f, 0x94}};

    unsigned char key[4][4] = {
        {0xd0, 0xc9, 0xe1, 0xb6},
        {0x14, 0xee, 0x3f, 0x63},
        {0xf9, 0x25, 0x0c, 0x0c},
        {0xa8, 0x89, 0xc8, 0xa6}};

    unsigned char expected[4][4] = {
        {0x39, 0x02, 0xdc, 0x19},
        {0x25, 0xdc, 0x11, 0x6a},
        {0x84, 0x09, 0x85, 0x0b},
        {0x1d, 0xfb, 0x97, 0x32}};

    addRoundKey(state, key);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[i][j] != expected[i][j])
            {
                cout << "Add round key T2 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}
