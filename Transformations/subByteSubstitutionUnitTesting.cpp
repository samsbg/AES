#include "AESmethods.h"
#include <iostream>
using namespace std;

// Test 1/2 for substitution
bool subByteSubstitutionTest1()
{
    unsigned char result = sBSubstitution((unsigned char)0xcf);
    unsigned char expected = 0x8a;

    if (result != expected)
    {
        cout << "SubByte substitution T1 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

// Test 2/2 for substitution
bool subByteSubstitutionTest2()
{
    unsigned char result = sBSubstitution((unsigned char)0x4f);
    unsigned char expected = 0x84;

    if (result != expected)
    {
        cout << "SubByte substitution T2 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

// Test 1/2 for inverse substitution
bool subByteSubstitutionTest3()
{
    unsigned char result = invSBSubstitution((unsigned char)0xeb);
    unsigned char expected = 0x3c;

    if (result != expected)
    {
        cout << "SubByte substitution T3 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

// Test 2/2 for inverse substitution
bool subByteSubstitutionTest4()
{
    unsigned char result = invSBSubstitution((unsigned char)0x01);
    unsigned char expected = 0x09;

    if (result != expected)
    {
        cout << "SubByte substitution T4 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}
