#include "AESmethods.h"
#include <iostream>
using namespace std;

bool subBytesTest1()
{
    unsigned char expected[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0x27, 0xbf, 0xb4, 0x41},
        {0x11, 0x98, 0x5d, 0x52},
        {0xae, 0xf1, 0xe5, 0x30}};

   
    unsigned char state[4][4] = {
        {0x19, 0xa0, 0x9a, 0xe9},
        {0x3d, 0xf4, 0xc6, 0xf8},
        {0xe3, 0xe2, 0x8d, 0x48},
        {0xbe, 0x2b, 0x2a, 0x08}};
    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    subBytes(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Sub Bytes T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool subBytesTest2()
{
    // Original State
    unsigned char expected[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xde, 0xdb, 0x39, 0x02},
        {0xd2, 0x96, 0x87, 0x53},
        {0x89, 0xf1, 0x1a, 0x3b}};

    // Expected result
    unsigned char state[4][4] = {
        {0xa4,0x68,0x6b,0x02},
        {0x9c,0x9f,0x5b,0x6a},
        {0x7f,0x35,0xea,0x50},
        {0xf2,0x2b,0x43,0x49}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    subBytes(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Sub Bytes T2 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}


bool invSubBytesTest1()
{
    unsigned char state[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0x27, 0xbf, 0xb4, 0x41},
        {0x11, 0x98, 0x5d, 0x52},
        {0xae, 0xf1, 0xe5, 0x30}};

       unsigned char expected[4][4] = {
        {0x19, 0xa0, 0x9a, 0xe9},
        {0x3d, 0xf4, 0xc6, 0xf8},
        {0xe3, 0xe2, 0x8d, 0x48},
        {0xbe, 0x2b, 0x2a, 0x08}};
    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    invSubBytes(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Inv Sub Bytes T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool invSubBytesTest2()
{
    // Original State
    unsigned char state[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xde, 0xdb, 0x39, 0x02},
        {0xd2, 0x96, 0x87, 0x53},
        {0x89, 0xf1, 0x1a, 0x3b}};

    // Expected result
    unsigned char expected[4][4] = {
        {0xa4, 0x68, 0x6b, 0x02},
        {0x9c, 0x9f, 0x5b, 0x6a},
        {0x7f, 0x35, 0xea, 0x50},
        {0xf2, 0x2b, 0x43, 0x49}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    invSubBytes(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Inv Sub Bytes T2 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

