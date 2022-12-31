#include <iostream>
#include "subByteSubstitution.cpp"
using namespace std;

// Test 1/2 for substitution
bool subByteSubstitutionTest1() {
    uint8_t result = sBSubstitution((uint8_t) 0xcf);
    uint8_t expected = 0x8a;

    if (result != expected) {
        cout << "SubByte substitution T1 failed" << endl
             << "AI: " << (int) result << "/" << (int) expected << endl;
        return false;
    }

    return true;
}

// Test 2/2 for substitution
bool subByteSubstitutionTest2() {
    uint8_t result = sBSubstitution((uint8_t)0x4f);
    uint8_t expected = 0x84;

    if (result != expected) {
        cout << "SubByte substitution T2 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

// Test 1/2 for inverse substitution
bool subByteSubstitutionTest3() {
    uint8_t result = invSBSubstitution((uint8_t)0xeb);
    uint8_t expected = 0x3c;

    if (result != expected) {
        cout << "SubByte substitution T3 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

// Test 2/2 for inverse substitution
bool subByteSubstitutionTest4() {
    uint8_t result = invSBSubstitution((uint8_t)0x01);
    uint8_t expected = 0x09;

    if (result != expected) {
        cout << "SubByte substitution T4 failed" << endl
             << "AI: " << (int)result << "/" << (int)expected << endl;
        return false;
    }

    return true;
}

int main() {

    int tests = 0;
    
    if (subByteSubstitutionTest1()) tests++;
    if (subByteSubstitutionTest2()) tests++;
    if (subByteSubstitutionTest3()) tests++;
    if (subByteSubstitutionTest4()) tests++;

    cout << "SubByte substitution test " << tests << "/4: " << ((tests == 4) ? "Success" : "Failed") << endl;

    return 0;
}