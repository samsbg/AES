
// Add Round Key method -------------------------------------------------------------------------------

void addRoundKey(unsigned char state[4][4], unsigned char key[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= key[i][j];
        }
    }
}

// Sub Byte Substitution method -------------------------------------------------------------------------------

// These methods are meant to be private and used for the subByte and key transformations methods
// When moved to the transformation methods file, the sBox could become global variables
// In the case of the top, even though the method is quite small, I do believe it is still useful as a separate function

unsigned char sBSubstitution(unsigned char initial)
{

    // Predetermined s-box for Rjindael
    unsigned char sBox[16][16] = {
        {(unsigned char)0x63, (unsigned char)0x7c, (unsigned char)0x77, (unsigned char)0x7b, (unsigned char)0xf2, (unsigned char)0x6b, (unsigned char)0x6f, (unsigned char)0xc5, (unsigned char)0x30, (unsigned char)0x01, (unsigned char)0x67, (unsigned char)0x2b, (unsigned char)0xfe, (unsigned char)0xd7, (unsigned char)0xab, (unsigned char)0x76},
        {(unsigned char)0xca, (unsigned char)0x82, (unsigned char)0xc9, (unsigned char)0x7d, (unsigned char)0xfa, (unsigned char)0x59, (unsigned char)0x47, (unsigned char)0xf0, (unsigned char)0xad, (unsigned char)0xd4, (unsigned char)0xa2, (unsigned char)0xaf, (unsigned char)0x9c, (unsigned char)0xa4, (unsigned char)0x72, (unsigned char)0xc0},
        {(unsigned char)0xb7, (unsigned char)0xfd, (unsigned char)0x93, (unsigned char)0x26, (unsigned char)0x36, (unsigned char)0x3f, (unsigned char)0xf7, (unsigned char)0xcc, (unsigned char)0x34, (unsigned char)0xa5, (unsigned char)0xe5, (unsigned char)0xf1, (unsigned char)0x71, (unsigned char)0xd8, (unsigned char)0x31, (unsigned char)0x15},
        {(unsigned char)0x04, (unsigned char)0xc7, (unsigned char)0x23, (unsigned char)0xc3, (unsigned char)0x18, (unsigned char)0x96, (unsigned char)0x05, (unsigned char)0x9a, (unsigned char)0x07, (unsigned char)0x12, (unsigned char)0x80, (unsigned char)0xe2, (unsigned char)0xeb, (unsigned char)0x27, (unsigned char)0xb2, (unsigned char)0x75},
        {(unsigned char)0x09, (unsigned char)0x83, (unsigned char)0x2c, (unsigned char)0x1a, (unsigned char)0x1b, (unsigned char)0x6e, (unsigned char)0x5a, (unsigned char)0xa0, (unsigned char)0x52, (unsigned char)0x3b, (unsigned char)0xd6, (unsigned char)0xb3, (unsigned char)0x29, (unsigned char)0xe3, (unsigned char)0x2f, (unsigned char)0x84},
        {(unsigned char)0x53, (unsigned char)0xd1, (unsigned char)0x00, (unsigned char)0xed, (unsigned char)0x20, (unsigned char)0xfc, (unsigned char)0xb1, (unsigned char)0x5b, (unsigned char)0x6a, (unsigned char)0xcb, (unsigned char)0xbe, (unsigned char)0x39, (unsigned char)0x4a, (unsigned char)0x4c, (unsigned char)0x58, (unsigned char)0xcf},
        {(unsigned char)0xd0, (unsigned char)0xef, (unsigned char)0xaa, (unsigned char)0xfb, (unsigned char)0x43, (unsigned char)0x4d, (unsigned char)0x33, (unsigned char)0x85, (unsigned char)0x45, (unsigned char)0xf9, (unsigned char)0x02, (unsigned char)0x7f, (unsigned char)0x50, (unsigned char)0x3c, (unsigned char)0x9f, (unsigned char)0xa8},
        {(unsigned char)0x51, (unsigned char)0xa3, (unsigned char)0x40, (unsigned char)0x8f, (unsigned char)0x92, (unsigned char)0x9d, (unsigned char)0x38, (unsigned char)0xf5, (unsigned char)0xbc, (unsigned char)0xb6, (unsigned char)0xda, (unsigned char)0x21, (unsigned char)0x10, (unsigned char)0xff, (unsigned char)0xf3, (unsigned char)0xd2},
        {(unsigned char)0xcd, (unsigned char)0x0c, (unsigned char)0x13, (unsigned char)0xec, (unsigned char)0x5f, (unsigned char)0x97, (unsigned char)0x44, (unsigned char)0x17, (unsigned char)0xc4, (unsigned char)0xa7, (unsigned char)0x7e, (unsigned char)0x3d, (unsigned char)0x64, (unsigned char)0x5d, (unsigned char)0x19, (unsigned char)0x73},
        {(unsigned char)0x60, (unsigned char)0x81, (unsigned char)0x4f, (unsigned char)0xdc, (unsigned char)0x22, (unsigned char)0x2a, (unsigned char)0x90, (unsigned char)0x88, (unsigned char)0x46, (unsigned char)0xee, (unsigned char)0xb8, (unsigned char)0x14, (unsigned char)0xde, (unsigned char)0x5e, (unsigned char)0x0b, (unsigned char)0xdb},
        {(unsigned char)0xe0, (unsigned char)0x32, (unsigned char)0x3a, (unsigned char)0x0a, (unsigned char)0x49, (unsigned char)0x06, (unsigned char)0x24, (unsigned char)0x5c, (unsigned char)0xc2, (unsigned char)0xd3, (unsigned char)0xac, (unsigned char)0x62, (unsigned char)0x91, (unsigned char)0x95, (unsigned char)0xe4, (unsigned char)0x79},
        {(unsigned char)0xe7, (unsigned char)0xc8, (unsigned char)0x37, (unsigned char)0x6d, (unsigned char)0x8d, (unsigned char)0xd5, (unsigned char)0x4e, (unsigned char)0xa9, (unsigned char)0x6c, (unsigned char)0x56, (unsigned char)0xf4, (unsigned char)0xea, (unsigned char)0x65, (unsigned char)0x7a, (unsigned char)0xae, (unsigned char)0x08},
        {(unsigned char)0xba, (unsigned char)0x78, (unsigned char)0x25, (unsigned char)0x2e, (unsigned char)0x1c, (unsigned char)0xa6, (unsigned char)0xb4, (unsigned char)0xc6, (unsigned char)0xe8, (unsigned char)0xdd, (unsigned char)0x74, (unsigned char)0x1f, (unsigned char)0x4b, (unsigned char)0xbd, (unsigned char)0x8b, (unsigned char)0x8a},
        {(unsigned char)0x70, (unsigned char)0x3e, (unsigned char)0xb5, (unsigned char)0x66, (unsigned char)0x48, (unsigned char)0x03, (unsigned char)0xf6, (unsigned char)0x0e, (unsigned char)0x61, (unsigned char)0x35, (unsigned char)0x57, (unsigned char)0xb9, (unsigned char)0x86, (unsigned char)0xc1, (unsigned char)0x1d, (unsigned char)0x9e},
        {(unsigned char)0xe1, (unsigned char)0xf8, (unsigned char)0x98, (unsigned char)0x11, (unsigned char)0x69, (unsigned char)0xd9, (unsigned char)0x8e, (unsigned char)0x94, (unsigned char)0x9b, (unsigned char)0x1e, (unsigned char)0x87, (unsigned char)0xe9, (unsigned char)0xce, (unsigned char)0x55, (unsigned char)0x28, (unsigned char)0xdf},
        {(unsigned char)0x8c, (unsigned char)0xa1, (unsigned char)0x89, (unsigned char)0x0d, (unsigned char)0xbf, (unsigned char)0xe6, (unsigned char)0x42, (unsigned char)0x68, (unsigned char)0x41, (unsigned char)0x99, (unsigned char)0x2d, (unsigned char)0x0f, (unsigned char)0xb0, (unsigned char)0x54, (unsigned char)0xbb, (unsigned char)0x16}};

    // Which value to substitute with is determined by the value itself
    // (first 4-bits y value) (last 4-bits x value)
    int row = initial / 16;
    int column = initial % 16;

    unsigned char subsitution = sBox[row][column];

    return subsitution;
}

unsigned char invSBSubstitution(unsigned char initial)
{

    // Predetermined inverse s-box for Rjindael
    unsigned char sBox[16][16] = {
        {(unsigned char)0x52, (unsigned char)0x09, (unsigned char)0x6a, (unsigned char)0xd5, (unsigned char)0x30, (unsigned char)0x36, (unsigned char)0xa5, (unsigned char)0x38, (unsigned char)0xbf, (unsigned char)0x40, (unsigned char)0xa3, (unsigned char)0x9e, (unsigned char)0x81, (unsigned char)0xf3, (unsigned char)0xd7, (unsigned char)0xfb},
        {(unsigned char)0x7c, (unsigned char)0xe3, (unsigned char)0x39, (unsigned char)0x82, (unsigned char)0x9b, (unsigned char)0x2f, (unsigned char)0xff, (unsigned char)0x87, (unsigned char)0x34, (unsigned char)0x8e, (unsigned char)0x43, (unsigned char)0x44, (unsigned char)0xc4, (unsigned char)0xde, (unsigned char)0xe9, (unsigned char)0xcb},
        {(unsigned char)0x54, (unsigned char)0x7b, (unsigned char)0x94, (unsigned char)0x32, (unsigned char)0xa6, (unsigned char)0xc2, (unsigned char)0x23, (unsigned char)0x3d, (unsigned char)0xee, (unsigned char)0x4c, (unsigned char)0x95, (unsigned char)0x0b, (unsigned char)0x42, (unsigned char)0xfa, (unsigned char)0xc3, (unsigned char)0x4e},
        {(unsigned char)0x08, (unsigned char)0x2e, (unsigned char)0xa1, (unsigned char)0x66, (unsigned char)0x28, (unsigned char)0xd9, (unsigned char)0x24, (unsigned char)0xb2, (unsigned char)0x76, (unsigned char)0x5b, (unsigned char)0xa2, (unsigned char)0x49, (unsigned char)0x6d, (unsigned char)0x8b, (unsigned char)0xd1, (unsigned char)0x25},
        {(unsigned char)0x72, (unsigned char)0xf8, (unsigned char)0xf6, (unsigned char)0x64, (unsigned char)0x86, (unsigned char)0x68, (unsigned char)0x98, (unsigned char)0x16, (unsigned char)0xd4, (unsigned char)0xa4, (unsigned char)0x5c, (unsigned char)0xcc, (unsigned char)0x5d, (unsigned char)0x65, (unsigned char)0xb6, (unsigned char)0x92},
        {(unsigned char)0x6c, (unsigned char)0x70, (unsigned char)0x48, (unsigned char)0x50, (unsigned char)0xfd, (unsigned char)0xed, (unsigned char)0xb9, (unsigned char)0xda, (unsigned char)0x5e, (unsigned char)0x15, (unsigned char)0x46, (unsigned char)0x57, (unsigned char)0xa7, (unsigned char)0x8d, (unsigned char)0x9d, (unsigned char)0x84},
        {(unsigned char)0x90, (unsigned char)0xd8, (unsigned char)0xab, (unsigned char)0x00, (unsigned char)0x8c, (unsigned char)0xbc, (unsigned char)0xd3, (unsigned char)0x0a, (unsigned char)0xf7, (unsigned char)0xe4, (unsigned char)0x58, (unsigned char)0x05, (unsigned char)0xb8, (unsigned char)0xb3, (unsigned char)0x45, (unsigned char)0x06},
        {(unsigned char)0xd0, (unsigned char)0x2c, (unsigned char)0x1e, (unsigned char)0x8f, (unsigned char)0xca, (unsigned char)0x3f, (unsigned char)0x0f, (unsigned char)0x02, (unsigned char)0xc1, (unsigned char)0xaf, (unsigned char)0xbd, (unsigned char)0x03, (unsigned char)0x01, (unsigned char)0x13, (unsigned char)0x8a, (unsigned char)0x6b},
        {(unsigned char)0x3a, (unsigned char)0x91, (unsigned char)0x11, (unsigned char)0x41, (unsigned char)0x4f, (unsigned char)0x67, (unsigned char)0xdc, (unsigned char)0xea, (unsigned char)0x97, (unsigned char)0xf2, (unsigned char)0xcf, (unsigned char)0xce, (unsigned char)0xf0, (unsigned char)0xb4, (unsigned char)0xe6, (unsigned char)0x73},
        {(unsigned char)0x96, (unsigned char)0xac, (unsigned char)0x74, (unsigned char)0x22, (unsigned char)0xe7, (unsigned char)0xad, (unsigned char)0x35, (unsigned char)0x85, (unsigned char)0xe2, (unsigned char)0xf9, (unsigned char)0x37, (unsigned char)0xe8, (unsigned char)0x1c, (unsigned char)0x75, (unsigned char)0xdf, (unsigned char)0x6e},
        {(unsigned char)0x47, (unsigned char)0xf1, (unsigned char)0x1a, (unsigned char)0x71, (unsigned char)0x1d, (unsigned char)0x29, (unsigned char)0xc5, (unsigned char)0x89, (unsigned char)0x6f, (unsigned char)0xb7, (unsigned char)0x62, (unsigned char)0x0e, (unsigned char)0xaa, (unsigned char)0x18, (unsigned char)0xbe, (unsigned char)0x1b},
        {(unsigned char)0xfc, (unsigned char)0x56, (unsigned char)0x3e, (unsigned char)0x4b, (unsigned char)0xc6, (unsigned char)0xd2, (unsigned char)0x79, (unsigned char)0x20, (unsigned char)0x9a, (unsigned char)0xdb, (unsigned char)0xc0, (unsigned char)0xfe, (unsigned char)0x78, (unsigned char)0xcd, (unsigned char)0x5a, (unsigned char)0xf4},
        {(unsigned char)0x1f, (unsigned char)0xdd, (unsigned char)0xa8, (unsigned char)0x33, (unsigned char)0x88, (unsigned char)0x07, (unsigned char)0xc7, (unsigned char)0x31, (unsigned char)0xb1, (unsigned char)0x12, (unsigned char)0x10, (unsigned char)0x59, (unsigned char)0x27, (unsigned char)0x80, (unsigned char)0xec, (unsigned char)0x5f},
        {(unsigned char)0x60, (unsigned char)0x51, (unsigned char)0x7f, (unsigned char)0xa9, (unsigned char)0x19, (unsigned char)0xb5, (unsigned char)0x4a, (unsigned char)0x0d, (unsigned char)0x2d, (unsigned char)0xe5, (unsigned char)0x7a, (unsigned char)0x9f, (unsigned char)0x93, (unsigned char)0xc9, (unsigned char)0x9c, (unsigned char)0xef},
        {(unsigned char)0xa0, (unsigned char)0xe0, (unsigned char)0x3b, (unsigned char)0x4d, (unsigned char)0xae, (unsigned char)0x2a, (unsigned char)0xf5, (unsigned char)0xb0, (unsigned char)0xc8, (unsigned char)0xeb, (unsigned char)0xbb, (unsigned char)0x3c, (unsigned char)0x83, (unsigned char)0x53, (unsigned char)0x99, (unsigned char)0x61},
        {(unsigned char)0x17, (unsigned char)0x2b, (unsigned char)0x04, (unsigned char)0x7e, (unsigned char)0xba, (unsigned char)0x77, (unsigned char)0xd6, (unsigned char)0x26, (unsigned char)0xe1, (unsigned char)0x69, (unsigned char)0x14, (unsigned char)0x63, (unsigned char)0x55, (unsigned char)0x21, (unsigned char)0x0c, (unsigned char)0x7d}};

    // Which value to substitute with is determined by the value itself
    // (first 4-bits y value) (last 4-bits x value)
    int row = initial / 16;
    int column = initial % 16;

    unsigned char subsitution = sBox[row][column];

    return subsitution;
}

// Key Transformation Method ----------------------------------------------------------------------------------

// Uses subbyte substitution method
// Adjusted to work on 128, 192 or 256 set up in the second parameter
// Should technically work with other size, but since 256 has special rules, should be on the lookout for that
// Should later on restrict it to AES 128, 192, 256

void keyTransformation(unsigned char keys[][4][4], int sizeSelected)
{
    int rcon = 1;
    sizeSelected /= 32;

    for (int count = 0; count < (28 + sizeSelected * 3); count++)
    {

        int currentKey = (count + sizeSelected) / 4;
        int currentColumn = (count + (sizeSelected % 4)) % 4;

        int sixBeforeKey = count / 4;
        int sixBeforeColumn = count % 4;

        int lastColumnKey = (count + sizeSelected - 1) / 4;
        int lastColumn = (count + ((sizeSelected - 1) % 4)) % 4;

        for (int j = 0; j < 4; j++)
        {
            // First column
            if (!(count % sizeSelected))
            {
                keys[currentKey][j][currentColumn] = keys[lastColumnKey][(j + 1) % 4][lastColumn];              // Rotation
                keys[currentKey][j][currentColumn] = sBSubstitution(keys[currentKey][j][currentColumn]);        // Substitution
                keys[currentKey][j][currentColumn] ^= keys[sixBeforeKey][j][sixBeforeColumn] ^ (!j ? rcon : 0); // XOR operation

                if (!j)
                {
                    rcon *= 2;
                    if (rcon >= 256)
                    {
                        rcon ^= 283;
                    }
                }
                // Rest of the columns
            }
            else
            {
                // Size 256 has special rules
                if (sizeSelected == 8 && count % 8 == 4)
                {
                    keys[currentKey][j][currentColumn] = keys[lastColumnKey][j][lastColumn];                 // Rotation
                    keys[currentKey][j][currentColumn] = sBSubstitution(keys[currentKey][j][currentColumn]); // Substitution
                    keys[currentKey][j][currentColumn] ^= keys[sixBeforeKey][j][sixBeforeColumn];            // XOR operation
                }
                else
                {
                    keys[currentKey][j][currentColumn] = keys[lastColumnKey][j][lastColumn] ^ keys[sixBeforeKey][j][sixBeforeColumn]; // XOR operation
                }
            }
        }
    }
}

// Mix Columns Method ----------------------------------------------------------------------------------------

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
        state[0][i] = multiply(0x0e, temp1) ^ multiply(0x0b, temp2) ^ multiply(0x0d, temp3) ^ multiply(0x09, temp4);
        state[1][i] = multiply(0x09, temp1) ^ multiply(0x0e, temp2) ^ multiply(0x0b, temp3) ^ multiply(0x0d, temp4);
        state[2][i] = multiply(0x0d, temp1) ^ multiply(0x09, temp2) ^ multiply(0x0e, temp3) ^ multiply(0x0b, temp4);
        state[3][i] = multiply(0x0b, temp1) ^ multiply(0x0d, temp2) ^ multiply(0x09, temp3) ^ multiply(0x0e, temp4);
    }
}

// shift rows method -----------------------------------------------------------------------------------------

void shiftRows(unsigned char state[4][4])
{
    unsigned char temp1, temp2;

    // second row
    temp1 = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp1;

    // third row
    temp1 = state[2][0];
    temp2 = state[2][1];
    state[2][0] = state[2][2];
    state[2][1] = state[2][3];
    state[2][2] = temp1;
    state[2][3] = temp2;

    // fourth row alt
    temp1 = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp1;
}

void invShiftRows(unsigned char state[4][4])
{
    unsigned char temp1, temp2;

    // second Row
    temp1 = state[1][3];
    state[1][3] = state[1][2];
    state[1][2] = state[1][1];
    state[1][1] = state[1][0];
    state[1][0] = temp1;

    // third row
    temp1 = state[2][0];
    temp2 = state[2][1];
    state[2][0] = state[2][2];
    state[2][1] = state[2][3];
    state[2][2] = temp1;
    state[2][3] = temp2;

    // fourth row

    temp1 = state[3][0];
    state[3][0] = state[3][1];
    state[3][1] = state[3][2];
    state[3][2] = state[3][3];
    state[3][3] = temp1;
}

// Key Transformation ----------------------------------------------------------------------------------------
// Uses subbyte substitution method
// Adjusted to work on 128, 192 or 256 set up in the second parameter
// Should technically work with other size, but since 256 has special rules, should be on the lookout for that
// Should later on restrict it to AES 128, 192, 256
