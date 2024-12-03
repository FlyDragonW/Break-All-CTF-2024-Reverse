#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handleErrors(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}


//gcc aes_encrypt.c -o aes_encrypt -lcrypto -lssl

int main() {
    // 初始化密鑰和 IV
    unsigned char key[AES_BLOCK_SIZE] = "flydragonsaeskey"; // 16 字節的密鑰 (AES-128)
    unsigned char iv[AES_BLOCK_SIZE]  = "aaaaaaaaaaaaaaaa";

    // 原始明文
    unsigned char plaintext[] = "Dyn4mic+__}";
    int plaintext_len = strlen((char *)plaintext);

    // 填充明文到 16 字節倍數
    int padded_len = ((plaintext_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char padded_plaintext[padded_len];
    memset(padded_plaintext, 0, padded_len);
    memcpy(padded_plaintext, plaintext, plaintext_len);

    // 加密輸出緩衝區
    unsigned char ciphertext[padded_len];

    // 設置加密密鑰
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);

    // AES CBC 加密
    AES_cbc_encrypt(padded_plaintext, ciphertext, padded_len, &encryptKey, iv, AES_ENCRYPT);

    // 輸出密文（十六進制格式）
    printf("Ciphertext (hex): ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // 輸出初始化向量（十六進制格式）
    printf("IV (hex): ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    return 0;
}
