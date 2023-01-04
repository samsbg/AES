#include "subByteSubstitution.cpp"


// Uses subbyte substitution method
// Adjusted to work on 128, 192 or 256 set up in the second parameter
// Should technically work with other size, but since 256 has special rules, should be on the lookout for that
// Should later on restrict it to AES 128, 192, 256

void keyTransformation(unsigned char keys[][4][4], int sizeSelected) {
    int rcon = 1;
    sizeSelected /= 32;

    for (int count = 0; count < (28 + sizeSelected * 3); count++) {

        int currentKey = (count + sizeSelected) / 4;
        int currentColumn = (count + (sizeSelected % 4)) % 4;

        int sixBeforeKey = count / 4;
        int sixBeforeColumn = count % 4;

        int lastColumnKey = (count + sizeSelected - 1) / 4;
        int lastColumn = (count + ((sizeSelected - 1) % 4)) % 4;

        for (int j = 0; j < 4; j++) {
            // First column
            if(!(count % sizeSelected)) {
                keys[currentKey][j][currentColumn] = keys[lastColumnKey][(j + 1) % 4][lastColumn]; // Rotation
                keys[currentKey][j][currentColumn] = sBSubstitution(keys[currentKey][j][currentColumn]); // Substitution
                keys[currentKey][j][currentColumn] ^= keys[sixBeforeKey][j][sixBeforeColumn] ^ (!j ? rcon : 0); // XOR operation

                if(!j){
                    rcon *= 2;
                    if(rcon >= 256) {
                        rcon ^= 283;
                    }
                }
            // Rest of the columns
            } else {
                // Size 256 has special rules
                if(sizeSelected == 8 && count % 8 == 4) {
                    keys[currentKey][j][currentColumn] = keys[lastColumnKey][j][lastColumn]; // Rotation
                    keys[currentKey][j][currentColumn] = sBSubstitution(keys[currentKey][j][currentColumn]); // Substitution
                    keys[currentKey][j][currentColumn] ^= keys[sixBeforeKey][j][sixBeforeColumn]; // XOR operation
                } else {
                    keys[currentKey][j][currentColumn] = keys[lastColumnKey][j][lastColumn] ^ keys[sixBeforeKey][j][sixBeforeColumn]; // XOR operation
                }
            }
        }
    }
    
}