using namespace std;

// XOR of state and key

void addRoundKey(unsigned char state[4][4], unsigned char key[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= key[i][j];
        }
    }
}