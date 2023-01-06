#ifndef AESMETHODS_H
#define AESMETHODS_H

#include "AESmethods.cpp"

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

#endif