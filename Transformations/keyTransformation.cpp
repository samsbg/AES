#include "subByteSubstitution.cpp"


// Uses subbyte substitution method
// Only works for 128 key, would need new methods or adjusting for 192 and 256

void keyTransformation128(unsigned char keys[11][4][4]) {
    int rcon = 1, temp;

    for (int i = 1; i < 11; i++) {
        //First column of key
        for (int j = 0; j < 4; j++) {
            keys[i][j][0] = keys[i - 1][(j+1) % 4][3]; // Rotation
            keys[i][j][0] = sBSubstitution(keys[i][j][0]); // Substitution
            keys[i][j][0] = keys[i][j][0] ^ keys[i - 1][j][0] ^ (j == 0 ? rcon : 0); // XOR operation
        }
        //Rest of columns
        for (int j = 0; j < 4; j++) {
            for (int k = 1; k < 4; k++) {
                keys[i][j][k] = keys[i - 1][j][k] ^ keys[i][j][k-1]; //XOR operation
            } 
        }
        //Get next Rcon
        if(rcon >= 128) {
            rcon = (rcon*2) ^ 283;
        } else {
            rcon = rcon*2;
        }
    }
}