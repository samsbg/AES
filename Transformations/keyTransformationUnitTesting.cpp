#include "AESmethods.h"
#include <iostream>
using namespace std;

// 128: Round key 0
bool keyTransformationTest1()
{

    unsigned char initialKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char results[11][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            results[0][i][j] = initialKey[i][j];
        }
    }

    keyTransformation(results, 128);

    unsigned char expected[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[0][j][i] != expected[j][i])
            {
                cout << "Key transformation T1 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 128: Round key 1
bool keyTransformationTest2()
{

    unsigned char initialKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char results[11][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            results[0][i][j] = initialKey[i][j];
        }
    }

    keyTransformation(results, 128);

    unsigned char expected[4][4] = {
        {0xa0, 0x88, 0x23, 0x2a},
        {0xfa, 0x54, 0xa3, 0x6c},
        {0xfe, 0x2c, 0x39, 0x76},
        {0x17, 0xb1, 0x39, 0x05}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[1][j][i] != expected[j][i])
            {
                cout << "Key transformation T2 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 128: Round key 5
bool keyTransformationTest3()
{

    unsigned char initialKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char results[11][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            results[0][i][j] = initialKey[i][j];
        }
    }

    keyTransformation(results, 128);

    unsigned char expected[4][4] = {
        {0xd4, 0x7c, 0xca, 0x11},
        {0xd1, 0x83, 0xf2, 0xf9},
        {0xc6, 0x9d, 0xb8, 0x15},
        {0xf8, 0x87, 0xbc, 0xbc}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[5][j][i] != expected[j][i])
            {
                cout << "Key transformation T3 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 128: Round key 10
bool keyTransformationTest4()
{
    unsigned char initialKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}};

    unsigned char results[11][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            results[0][i][j] = initialKey[i][j];
        }
    }

    keyTransformation(results, 128);

    unsigned char expected[4][4] = {
        {0xd0, 0xc9, 0xe1, 0xb6},
        {0x14, 0xee, 0x3f, 0x63},
        {0xf9, 0x25, 0x0c, 0x0c},
        {0xa8, 0x89, 0xc8, 0xa6}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[10][j][i] != expected[j][i])
            {
                cout << "Key transformation T4 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 0
bool keyTransformationTest5()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0x00, 0x04, 0x08, 0x0c},
        {0x01, 0x05, 0x09, 0x0d},
        {0x02, 0x06, 0x0a, 0x0e},
        {0x03, 0x07, 0x0b, 0x0f}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[0][j][i] != expected[j][i])
            {
                cout << "Key transformation T5 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 1
bool keyTransformationTest6()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0x10, 0x14, 0x58, 0x5c},
        {0x11, 0x15, 0x46, 0x43},
        {0x12, 0x16, 0xf2, 0xf4},
        {0x13, 0x17, 0xf9, 0xfe}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[1][j][i] != expected[j][i])
            {
                cout << "Key transformation T6 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 2
bool keyTransformationTest7()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0x54, 0x58, 0x48, 0x5c},
        {0x4a, 0x47, 0x56, 0x43},
        {0xfe, 0xf0, 0xe2, 0xf4},
        {0xf5, 0xfa, 0xe9, 0xfe}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[2][j][i] != expected[j][i])
            {
                cout << "Key transformation T7 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 3
bool keyTransformationTest8()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0x40, 0x1c, 0x48, 0x10},
        {0xf9, 0xba, 0xf0, 0xb7},
        {0x49, 0xbd, 0x43, 0xb3},
        {0xb3, 0x4d, 0xb8, 0x42}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[3][j][i] != expected[j][i])
            {
                cout << "Key transformation T8 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 4
bool keyTransformationTest9()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0x58, 0x04, 0x7e, 0x62},
        {0xe1, 0xa2, 0xff, 0x45},
        {0x51, 0xa5, 0xb5, 0x08},
        {0xab, 0x55, 0x41, 0x0c}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[4][j][i] != expected[j][i])
            {
                cout << "Key transformation T9 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 192: Round key 12
bool keyTransformationTest10()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x08, 0x0c},
                                          {0x11, 0x15, 0x09, 0x0d},
                                          {0x12, 0x16, 0x0a, 0x0e},
                                          {0x13, 0x17, 0x0b, 0x0f}}};

    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 192);

    unsigned char expected[4][4] = {
        {0xa4, 0x1a, 0xc4, 0xe3},
        {0x97, 0x78, 0x18, 0xa4},
        {0x0a, 0xdc, 0xc2, 0x1d},
        {0x33, 0x09, 0x71, 0x5d}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[12][j][i] != expected[j][i])
            {
                cout << "Key transformation T10 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 256: Round key 0
bool keyTransformationTest11()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    unsigned char expected[4][4] = {
        {0x00, 0x04, 0x08, 0x0c},
        {0x01, 0x05, 0x09, 0x0d},
        {0x02, 0x06, 0x0a, 0x0e},
        {0x03, 0x07, 0x0b, 0x0f}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[0][j][i] != expected[j][i])
            {
                cout << "Key transformation T11 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 256: Round key 1
bool keyTransformationTest12()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    unsigned char expected[4][4] = {
        {0x10, 0x14, 0x18, 0x1c},
        {0x11, 0x15, 0x19, 0x1d},
        {0x12, 0x16, 0x1a, 0x1e},
        {0x13, 0x17, 0x1b, 0x1f}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[1][j][i] != expected[j][i])
            {
                cout << "Key transformation T12 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 256: Round key 2
bool keyTransformationTest13()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    unsigned char expected[4][4] = {
        {0xa5, 0xa1, 0xa9, 0xa5},
        {0x73, 0x76, 0x7f, 0x72},
        {0xc2, 0xc4, 0xce, 0xc0},
        {0x9f, 0x98, 0x93, 0x9c}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[2][j][i] != expected[j][i])
            {
                cout << "Key transformation T13 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 256: Round key 3
bool keyTransformationTest14()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    unsigned char expected[4][4] = {
        {0x16, 0x02, 0x1a, 0x06},
        {0x51, 0x44, 0x5d, 0x40},
        {0xa8, 0xbe, 0xa4, 0xba},
        {0xcd, 0xda, 0xc1, 0xde}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[3][j][i] != expected[j][i])
            {
                cout << "Key transformation T14 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

// 256: Round key 14
bool keyTransformationTest15()
{
    unsigned char initialKey[2][8][4] = {{{0x00, 0x04, 0x08, 0x0c},
                                          {0x01, 0x05, 0x09, 0x0d},
                                          {0x02, 0x06, 0x0a, 0x0e},
                                          {0x03, 0x07, 0x0b, 0x0f}},
                                         {{0x10, 0x14, 0x18, 0x1c},
                                          {0x11, 0x15, 0x19, 0x1d},
                                          {0x12, 0x16, 0x1a, 0x1e},
                                          {0x13, 0x17, 0x1b, 0x1f}}};

    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = initialKey[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    unsigned char expected[4][4] = {
        {0x24, 0xbf, 0x37, 0x6d},
        {0xfc, 0x09, 0x1a, 0x68},
        {0x79, 0x79, 0xc2, 0xde},
        {0xcc, 0xe9, 0x3c, 0x36}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (results[14][j][i] != expected[j][i])
            {
                cout << "Key transformation T15 failed" << endl
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}
