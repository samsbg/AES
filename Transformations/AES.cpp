#include "AESmethods.cpp"
#include <iostream>

using namespace std;

void AES128(unsigned char input[4][4], unsigned char key[4][4])
{
    // Generate al necessary keys for AES128

    unsigned char Keys[11][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Keys[0][i][j] = key[i][j];
        }
    }

    keyTransformation(Keys, 128);

    addRoundKey(input, Keys[0]);

    for (int i = 0; i < 9; i++)
    {
        subBytes(input);
        shiftRows(input);
        mixColumns(input);
        addRoundKey(input, Keys[i + 1]);
    }

    subBytes(input);
    shiftRows(input);
    addRoundKey(input, Keys[10]);
}

void AES192(unsigned char input[4][4],  unsigned char key[2][8][4])
{
    unsigned char results[13][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = key[k][i][j];
            }
        }
    }
    keyTransformation(results, 192);

    addRoundKey(input, results[0]);

    for (int i = 0; i < 11; i++)
    {
        subBytes(input);
        shiftRows(input);
        mixColumns(input);
        addRoundKey(input, results[i + 1]);
    }

    subBytes(input);
    shiftRows(input);
    addRoundKey(input, results[12]);
}

void AES256(unsigned char input[4][4], unsigned char key[2][8][4])
{
    unsigned char results[15][4][4];

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                results[k][i][j] = key[k][i][j];
            }
        }
    }

    keyTransformation(results, 256);

    addRoundKey(input, results[0]);

    for (int i = 0; i < 13; i++)
    {
        subBytes(input);
        shiftRows(input);
        mixColumns(input);
        addRoundKey(input, results[i + 1]);
    }

    subBytes(input);
    shiftRows(input);
    addRoundKey(input, results[14]);
}
