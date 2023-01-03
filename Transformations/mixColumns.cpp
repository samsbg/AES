#include <algorithm>
using namespace std;

// Does Galois Field multiplication of 8 bit characters a and b
// This code is taken from Wikipedia
unsigned char multiply(unsigned char a, unsigned char b) 
{
    unsigned char p = 0; /* accumulator for the product of the multiplication */
    while (a != 0 && b != 0)
    {
        if (b & 1)  /* if the polynomial for b has a constant term, add the corresponding a to p */
            p ^= a; /* addition in GF(2^m) is an XOR of the polynomial coefficients */

        if (a & 0x80)             /* GF modulo: if a has a nonzero term x^7, then must be reduced when it becomes x^8 */
            a = (a << 1) ^ 0x11b; /* subtract (XOR) the primitive polynomial x^8 + x^4 + x^3 + x + 1 (0b1_0001_1011) – you can change it but it must be irreducible */
        else
            a <<= 1; /* equivalent to a*x */
        b >>= 1;
    }
    return p;
}

// Mixes the columns of the state matrix
void mixColumns(unsigned char state[4][4])
{
    unsigned char temp1, temp2, temp3, temp4; // Temporary variables

    for (int i = 0; i < 4; i++) // For each column
    {
        // Copy the column 
        temp1 = state[0][i]; 
        temp2 = state[1][i];
        temp3 = state[2][i];
        temp4 = state[3][i];

        // Mix the column
        state[0][i] = multiply(0x02, temp1) ^ multiply(0x03, temp2) ^ temp3 ^ temp4;
        state[1][i] = temp1 ^ multiply(0x02, temp2) ^ multiply(0x03, temp3) ^ temp4;
        state[2][i] = temp1 ^ temp2 ^ multiply(0x02, temp3) ^ multiply(0x03, temp4);
        state[3][i] = multiply(0x03, temp1) ^ temp2 ^ temp3 ^ multiply(0x02, temp4);
    }
}


// Inverse mix columns
void invMixColumns(unsigned char state[4][4])
{
    unsigned char temp1, temp2, temp3, temp4; // Temporary variables

    // For each column
    for (int i = 0; i < 4; i++)
    {
        // Copy the column
        temp1 = state[0][i];
        temp2 = state[1][i];
        temp3 = state[2][i];
        temp4 = state[3][i];

        // Inverse mix the column 
        state[0][i] = multiply(0x0e, temp1) ^ multiply(0x0b, temp2) ^ multiply(0x0d,temp3) ^ multiply(0x09,temp4);
        state[1][i] = multiply(0x09,temp1) ^ multiply(0x0e, temp2) ^ multiply(0x0b, temp3) ^ multiply(0x0d,temp4);
        state[2][i] = multiply(0x0d,temp1) ^ multiply(0x09,temp2) ^ multiply(0x0e, temp3) ^ multiply(0x0b, temp4);
        state[3][i] = multiply(0x0b, temp1) ^ multiply(0x0d,temp2) ^ multiply(0x09,temp3) ^ multiply(0x0e, temp4);
    }
}