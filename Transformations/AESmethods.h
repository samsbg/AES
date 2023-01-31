#ifndef AESMETHODS_H
#define AESMETHODS_H



// These methods are meant to be private and used for the subByte and key transformations methods
unsigned char sBSubstitution(unsigned char initial);
unsigned char invSBSubstitution(unsigned char initial); 

// XOR of state and key
void addRoundKey(unsigned char state[4][4], unsigned char key[4][4]);

// Uses subbyte substitution method
// Adjusted to work on 128, 192 or 256 set up in the second parameter
// Should technically work with other size, but since 256 has special rules, should be on the lookout for that
// Should later on restrict it to AES 128, 192, 256
void keyTransformation(unsigned char keys[][4][4], int sizeSelected);

// Does Galois Field multiplication of 8 bit characters a and b
// This code is taken from Wikipedia
unsigned char multiply(unsigned char a, unsigned char b);

// Mixes the columns of the state matrix
void mixColumns(unsigned char state[4][4]);

// Inverse mix columns
void invMixColumns(unsigned char state[4][4]);

// Description: Inverse shift rows
// Parameters: state - the state matrix
// Returns: Nothing
// Notes: This is a private method
void invShiftRows(unsigned char state[4][4]);

// Description: Shifts the rows of the state matrix
// Parameters: state - the state matrix
// Returns: Nothing
// Notes: This is a private method
void shiftRows(unsigned char state[4][4]);

// Description: Substitutes the bytes of the state matrix
// Parameters: state - the state matrix
// Returns: Nothing
// Notes: This is a private method
void subBytes(unsigned char state[4][4]);

// Description: Inverse substitutes the bytes of the state matrix
// Parameters: state - the state matrix
// Returns: Nothing
// Notes: This is a private method
void invSubBytes(unsigned char state[4][4]);


#endif