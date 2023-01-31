#include "AES.cpp"
#include <iostream>

bool firstTest128()
{
    unsigned char input[4][4] = {
        {0x32, 0x88, 0x31, 0xe0},
        {0x43, 0x5a, 0x31, 0x37},
        {0xf6, 0x30, 0x98, 0x07},
        {0xa8, 0x8d, 0xa2, 0x34}};
    unsigned char cipherKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char expected[4][4] = {
        {0x39, 0x02, 0xdc, 0x19},
        {0x25, 0xdc, 0x11, 0x6a},
        {0x84, 0x09, 0x85, 0x0b},
        {0x1d, 0xfb, 0x97, 0x32}};

    AES128(input, cipherKey);


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (input[i][j] != expected[i][j])
            {
                cout << "Problem at" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }
    return true;
}

bool secondTest128()
{
    unsigned char input[4][4] = {
        {0x00, 0x44, 0x88, 0xcc},
        {0x11, 0x55, 0x99, 0xdd},
        {0x22, 0x66, 0xaa, 0xee},
        {0x33, 0x77, 0xbb, 0xff}};

    unsigned char cipherKey[4][4] = {
        {0x00,0x04,0x08,0x0c},
        {0x01,0x05,0x09,0x0d},
        {0x02,0x06,0x0a,0x0e},
        {0x03,0x07,0x0b,0x0f}}; 
    unsigned char expected[4][4] = {
        {0x69, 0x6a, 0xd8, 0x70},
        {0xc4, 0x7b, 0xcd, 0xb4},
        {0xe0, 0x04, 0xb7, 0xc5},
        {0xd8, 0x30, 0x80, 0x5a}};

    AES128(input, cipherKey);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (input[i][j] != expected[i][j])
            {
                cout << "Problem at" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }
    return true;
}


bool firstTest192()
{
    unsigned char input[4][4] = {
        {0x00, 0x44, 0x88, 0xcc},
        {0x11, 0x55, 0x99, 0xdd},
        {0x22, 0x66, 0xaa, 0xee},
        {0x33, 0x77, 0xbb, 0xff}};

    unsigned char key[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    // dda97ca4864cdfe06eaf70a0ec0d7191

    unsigned char expected[4][4] = {
        {0xdd, 0x86, 0x6e, 0xec},
        {0xa9, 0x4c, 0xaf, 0x0d},
        {0x7c, 0xdf, 0x70, 0x71},
        {0xa4, 0xe0, 0xa0, 0x91}};

    AES192(input, key);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (input[i][j] != expected[i][j])
            {
                cout << "Problem at" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }
    return true;
}

bool firstTest256()
{
    unsigned char input[4][4] = {
        {0x00, 0x44, 0x88, 0xcc},
        {0x11, 0x55, 0x99, 0xdd},
        {0x22, 0x66, 0xaa, 0xee},
        {0x33, 0x77, 0xbb, 0xff}};

    unsigned char key[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char expected[4][4] = {
        {0x8e, 0x51, 0xea, 0x4b},
        {0xa2, 0x67, 0xfc, 0x49},
        {0xb7, 0x45, 0x49, 0x60},
        {0xca, 0xbf, 0x90, 0x89}};

    AES256(input, key);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (input[i][j] != expected[i][j])
            {
                cout << "Problem at" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }
    return true;
}


int main()
{
    if (firstTest128())
    {
        cout << "Test 128 passed" << endl;
    }
    else
    {
        cout << "Test 128 failed" << endl;
    }
    if (secondTest128())
    {
        cout << "Test 128 passed" << endl;
    }
    else
    {
        cout << "Test 128 failed" << endl;
    }
    if (firstTest192())
    {
        cout << "Test 192 passed" << endl;
    }
    else
    {
        cout << "Test 192 failed" << endl;
    }
    if (firstTest256())
    {
        cout << "Test 256 passed" << endl;
    }
    else
    {
        cout << "Test 256 failed" << endl;
    }


}