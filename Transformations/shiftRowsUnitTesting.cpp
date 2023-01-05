#include <iostream>
#include "allMethods.cpp"
using namespace std;

bool shiftRowsTest1()
{
    unsigned char state[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0x27, 0xbf, 0xb4, 0x41},
        {0x11, 0x98, 0x5d, 0x52},
        {0xae, 0xf1, 0xe5, 0x30}};

    // Expected result
    unsigned char expected[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0xbf, 0xb4, 0x41, 0x27},
        {0x5d, 0x52, 0x11, 0x98},
        {0x30, 0xae, 0xf1, 0xe5}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    shiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool shiftRowsTest2()
{
    // Original State
    unsigned char state[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xde, 0xdb, 0x39, 0x02},
        {0xd2, 0x96, 0x87, 0x53},
        {0x89, 0xf1, 0x1a, 0x3b}};

    // Expected result
    unsigned char expected[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xdb, 0x39, 0x02, 0xde},
        {0x87, 0x53, 0xd2, 0x96},
        {0x3b, 0x89, 0xf1, 0x1a}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    shiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T2 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool shiftRowsTest3()
{
    // Original State
    unsigned char state[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0x73, 0xc1, 0xb5, 0x23},
        {0xcf, 0x11, 0xd6, 0x5a},
        {0x7b, 0xdf, 0xb5, 0xb8}};

    // Expected result
    unsigned char expected[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0xc1, 0xb5, 0x23, 0x73},
        {0xd6, 0x5a, 0xcf, 0x11},
        {0xb8, 0x7b, 0xdf, 0xb5}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    shiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T3 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool invShiftRowsTest1()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0x27, 0xbf, 0xb4, 0x41},
        {0x11, 0x98, 0x5d, 0x52},
        {0xae, 0xf1, 0xe5, 0x30}};

    // Original State
    unsigned char state[4][4] = {
        {0xd4, 0xe0, 0xb8, 0x1e},
        {0xbf, 0xb4, 0x41, 0x27},
        {0x5d, 0x52, 0x11, 0x98},
        {0x30, 0xae, 0xf1, 0xe5}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    invShiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T1 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool invShiftRowsTest2()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xde, 0xdb, 0x39, 0x02},
        {0xd2, 0x96, 0x87, 0x53},
        {0x89, 0xf1, 0x1a, 0x3b}};

    // Original State
    unsigned char state[4][4] = {
        {0x49, 0x45, 0x7f, 0x77},
        {0xdb, 0x39, 0x02, 0xde},
        {0x87, 0x53, 0xd2, 0x96},
        {0x3b, 0x89, 0xf1, 0x1a}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    invShiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T2 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

bool invShiftRowsTest3()
{
    // Expected State
    unsigned char expected[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0x73, 0xc1, 0xb5, 0x23},
        {0xcf, 0x11, 0xd6, 0x5a},
        {0x7b, 0xdf, 0xb5, 0xb8}};

    // Original state
    unsigned char state[4][4] = {
        {0xac, 0xef, 0x13, 0x45},
        {0xc1, 0xb5, 0x23, 0x73},
        {0xd6, 0x5a, 0xcf, 0x11},
        {0xb8, 0x7b, 0xdf, 0xb5}};

    // The method is called. It modifies the state variable in the method. There is no need to return it back.
    invShiftRows(state);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[j][i] != expected[j][i])
            {
                cout << "Shift rows T3 failed" << endl
                     << "AT: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int test{};
    cout << "Unit Testing For ShiftRows Methods" << endl;
    cout << "Number of tests: 3" << endl;

    if (shiftRowsTest1())
        test++;
    if (shiftRowsTest2())
        test++;
    if (shiftRowsTest3())
        test++;

    cout << "Number of test passed " << test << "/3" << endl;
    cout << "Number of test Failed " << 3 - test << endl;

    cout << ((test == 3) ? "Task Success " : "Task Failed") << endl;

    cout << endl;
    int invTest{};
    cout << "Unit Testing For InvShiftRows Methods" << endl;
    cout << "Number of tests: 3" << endl;

    if (invShiftRowsTest1())
        invTest++;
    if (invShiftRowsTest2())
        invTest++;
    if (invShiftRowsTest3())
        invTest++;

    cout << "Numbs of test passed " << invTest << "/3" << endl;
    cout << "Number of test Failed " << 3 - invTest << endl;

    cout << ((invTest == 3) ? "Task Success " : "Task Failed") << endl;
}