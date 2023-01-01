#include "keyTransformation.cpp"
#include <iostream>
using namespace std;

//First key generated
bool keyTransformationTest1(unsigned char results[11][4][4]) {
    unsigned char expected[4][4] = {
        {0xa0, 0x88, 0x23, 0x2a},
        {0xfa, 0x54, 0xa3, 0x6c},
        {0xfe, 0x2c, 0x39, 0x76},
        {0x17, 0xb1, 0x39, 0x05}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(results[1][j][i] != expected[j][i]) {
                cout << "Key transformation T1 failed" << endl 
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

//Middle of the keys generated
bool keyTransformationTest2(unsigned char results[11][4][4]) {
    unsigned char expected[4][4] = {
        {0xd4, 0x7c, 0xca, 0x11},
        {0xd1, 0x83, 0xf2, 0xf9},
        {0xc6, 0x9d, 0xb8, 0x15},
        {0xf8, 0x87, 0xbc, 0xbc}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(results[5][j][i] != expected[j][i]) {
                cout << "Key transformation T2 failed" << endl 
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

//Last key generated
bool keyTransformationTest3(unsigned char results[11][4][4]) {
    unsigned char expected[4][4] = {
        {0xd0, 0xc9, 0xe1, 0xb6},
        {0x14, 0xee, 0x3f, 0x63},
        {0xf9, 0x25, 0x0c, 0x0c},
        {0xa8, 0x89, 0xc8, 0xa6}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(results[10][j][i] != expected[j][i]) {
                cout << "Key transformation T3 failed" << endl 
                     << "AI: " << i << "," << j << endl;
                return false;
            }
        }
    }

    return true;
}

int main() {

    unsigned char initialKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}
    };

    unsigned char keys[11][4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            keys[0][i][j] = initialKey[i][j];
        }
    }

    keyTransformation128(keys);

    int tests = 0;
    
    if (keyTransformationTest1(keys)) tests++;
    if (keyTransformationTest2(keys)) tests++;
    if (keyTransformationTest3(keys)) tests++;

    cout << "Key transformation test " << tests << "/3: " << ((tests == 3) ? "Success" : "Failed") << endl;

        return 0;
}

