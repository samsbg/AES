#include <iostream>
#include "allMethods.cpp"
using namespace std;

// Test case 1 for mixColumns
bool mixColumnsTest1()
{
    // Original State
    unsigned char state[4][4] = {
        {0x87, 0xf2, 0x4d, 0x97},
        {0x6e, 0x4c, 0x90, 0xec},
        {0x46, 0xe7, 0x4a, 0xc3},
        {0xa6, 0x8c, 0xd8, 0x95}};

    // Expected state
    unsigned char expected[4][4] = {
        {0x47, 0x40, 0xa3, 0x4c},
        {0x37, 0xd4, 0x70, 0x9f},
        {0x94, 0xe4, 0x3a, 0x42},
        {0xed, 0xa5, 0xa6, 0xbc}};

    mixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T1 failed" << endl
                     << "AT: " << j << "," << i << endl;

                return false;
            }
        }
    }

    return true;
}

// Test case 2 for mixColumns
bool mixColumnsTest2()
{
    // Original State
    unsigned char state[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xdb, 0x39, 0x02, 0xde},
        {0x87, 0x53, 0xd2, 0x96},
        {0x3b, 0x89, 0xf1, 0x1a}};

    // Expected state
    unsigned char expected[4][4] = {
        {0x58, 0x1b, 0xdb, 0x1b},
        {0x4d, 0x4b, 0xe7, 0x6b},
        {0xca, 0x5a, 0xca, 0xb0},
        {0xf1, 0xac, 0xa8, 0xe5}};

    mixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T2 failed" << endl
                     << "AT: " << j << "," << i << endl;
                return false;
            }
        }
    }

    return true;
}

// Test case 3 for mixColumns
bool mixColumnsTest3()
{
    // Original State
    unsigned char state[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0xc1, 0xb5, 0x23, 0x73},
        {0xd6, 0x5a, 0xcf, 0x11},
        {0xb8, 0x7b, 0xdf, 0xb5}};

    // Expected state
    unsigned char expected[4][4] = {
        {0x75, 0x20, 0x53, 0xbb},
        {0xec, 0x0b, 0xc0, 0x25},
        {0x09, 0x63, 0xcf, 0xd0},
        {0x93, 0x33, 0x7c, 0xdc}};

    mixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << state[j][i] << endl;
                cout << expected[j][i] << endl;
                cout << 0x53 << endl;
                cout << "Mix columns T3 failed" << endl
                     << "AT: " << j << "," << i << endl;
                return false;
            }
        }
    }

    return true;
}

// Test case 1 for invMixColumns
bool invMixColumnsTest1()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0x87, 0xf2, 0x4d, 0x97},
        {0x6e, 0x4c, 0x90, 0xec},
        {0x46, 0xe7, 0x4a, 0xc3},
        {0xa6, 0x8c, 0xd8, 0x95}};

    // Original state
    unsigned char state[4][4] = {
        {0x47, 0x40, 0xa3, 0x4c},
        {0x37, 0xd4, 0x70, 0x9f},
        {0x94, 0xe4, 0x3a, 0x42},
        {0xed, 0xa5, 0xa6, 0xbc}};

    invMixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T1 failed" << endl
                     << "AT: " << j << "," << i << endl;

                return false;
            }
        }
    }

    return true;
}

// Test case 2 for invMixColumns
bool invMixColumnsTest2()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xdb, 0x39, 0x02, 0xde},
        {0x87, 0x53, 0xd2, 0x96},
        {0x3b, 0x89, 0xf1, 0x1a}};

    // Original state
    unsigned char state[4][4] = {
        {0x58, 0x1b, 0xdb, 0x1b},
        {0x4d, 0x4b, 0xe7, 0x6b},
        {0xca, 0x5a, 0xca, 0xb0},
        {0xf1, 0xac, 0xa8, 0xe5}};

    invMixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Mix columns T2 failed" << endl
                     << "AT: " << j << "," << i << endl;
                return false;
            }
        }
    }

    return true;
}

// Test case 3 for invMixColumns
bool invMixColumnsTest3()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0xc1, 0xb5, 0x23, 0x73},
        {0xd6, 0x5a, 0xcf, 0x11},
        {0xb8, 0x7b, 0xdf, 0xb5}};

    // Original state
    unsigned char state[4][4] = {
        {0x75, 0x20, 0x53, 0xbb},
        {0xec, 0x0b, 0xc0, 0x25},
        {0x09, 0x63, 0xcf, 0xd0},
        {0x93, 0x33, 0x7c, 0xdc}};

    invMixColumns(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << state[j][i] << endl;
                cout << expected[j][i] << endl;
                cout << 0x53 << endl;
                cout << "Mix columns T3 failed" << endl
                     << "AT: " << j << "," << i << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{
    // Unit Testing for MixColumns
    int test{};
    cout << "Unit Testing For MixColumns Methods" << endl;
    cout << "Number of tests: 3" << endl;

    if (mixColumnsTest1())
        test++;
    if (mixColumnsTest2())
        test++;
    if (mixColumnsTest3())
        test++;

    cout << "Number of test passed " << test << "/3" << endl;
    cout << "Number of test Failed " << 3 - test << endl;

    cout << ((test == 3) ? "Task Success " : "Task Failed") << endl;

    //Unit testing for invMixColumns
    cout << endl;
    int invTest{};
    cout << "Unit Testing For InvShiftRows Methods" << endl;
    cout << "Number of tests: 3" << endl;

    if (invMixColumnsTest1())
        invTest++;
    if (invMixColumnsTest2())
        invTest++;
    if (invMixColumnsTest3())
        invTest++;

    cout << "Numbs of test passed " << invTest << "/3" << endl;
    cout << "Number of test Failed " << 3 - invTest << endl;

    cout << ((invTest == 3) ? "Task Success " : "Task Failed") << endl;
}