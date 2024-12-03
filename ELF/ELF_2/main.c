#include <openssl/aes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char ciphertext[] = {
        0xa5, 0x12, 0x28, 0x65, 0x47, 0xa3, 0xf8, 0x7b,
        0x52, 0x57, 0xc8, 0x94, 0x8a, 0x77, 0x86, 0xf2
};

void handleErrors(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void stg2() {
    unsigned char key[16] = "flydragonsaeskey"; 
    unsigned char iv[16] = "aaaaaaaaaaaaaaaa";

    int ciphertext_len = sizeof(ciphertext);

    unsigned char decryptedtext[ciphertext_len + 1]; 
    memset(decryptedtext, 0, sizeof(decryptedtext));

    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, 128, &decryptKey) < 0) {
        handleErrors("Failed to set decryption key");
    }

    AES_cbc_encrypt(ciphertext, decryptedtext, ciphertext_len, &decryptKey, iv, AES_DECRYPT);
}

bool stg1(char *flag) {
    if( flag[1] * flag[4] * flag[3] == 1368252 &&
        flag[8] + flag[8] * flag[2] == 11956 &&
        flag[4] - flag[1] - flag[3] == -88 &&
        flag[0] + flag[3] + flag[4] == 328 &&
        flag[10] + flag[4] - flag[5] == 66 &&
        flag[3] * flag[9] + flag[4] == 5376 &&
        flag[1] + flag[7] * flag[2] == 4279 &&
        flag[2] * flag[10] * flag[3] == 379658 &&
        flag[2] * flag[1] * flag[6] == 995220 &&
        flag[4] + flag[8] + flag[10] == 283 &&
        flag[1] * flag[7] - flag[7] == 4601 &&
        flag[5] - flag[8] - flag[8] == -149 &&
        flag[10] * flag[9] * flag[10] == 73644 &&
        flag[4] - flag[2] - flag[2] == -71 &&
        flag[9] - flag[0] + flag[2] == 46 &&
        flag[9] - flag[10] * flag[10] == -1393 &&
        flag[0] * flag[3] - flag[8] == 10384 &&
        flag[10] - flag[4] * flag[4] == -15091 &&
        flag[4] * flag[4] * flag[9] == 771579 &&
        flag[1] * flag[7] * flag[6] == 441180) 
        return true;
    else
        return false;
}

int main() {
    //char flag[] = "flag{__+z3&Dyn4mic+__}";
    printf("Welcome to the Mystery Game!\n");
    printf("In this game, you will need to pass 2 stages to get flag.\n\n");
    printf("Stage 1 - Enter first 11 characters of the flag:\n");
    char input[12];
    scanf("%11s", input);

    if(stg1(input)) {
        printf("You are the chosen one!\n");
        printf("Stage 2 - Find the second part of the flag.\n");
        stg2();
    } else {
        printf("You are not the chosen one!\n");
        return 1;
    }
    return 0;
}
