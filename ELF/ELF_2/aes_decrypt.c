#include <openssl/aes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handleErrors(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    // 提供的密鑰和 IV
    unsigned char key[16] = "flydragonsaeskey"; // 128-bit 密鑰
    unsigned char iv[16] = "aaaaaaaaaaaaaaaa"; // 初始化向量 (IV)

    // 提供的密文（轉換為字節數組）
    unsigned char ciphertext[] = {
        0xa5, 0x12, 0x28, 0x65, 0x47, 0xa3, 0xf8, 0x7b,
        0x52, 0x57, 0xc8, 0x94, 0x8a, 0x77, 0x86, 0xf2
    };

    int ciphertext_len = sizeof(ciphertext);

    // 解密後的明文緩衝區
    unsigned char decryptedtext[ciphertext_len + 1]; // 多留 1 字節存放 NULL 結尾
    memset(decryptedtext, 0, sizeof(decryptedtext));

    // 初始化解密上下文
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, 128, &decryptKey) < 0) {
        handleErrors("Failed to set decryption key");
    }

    // 解密操作
    AES_cbc_encrypt(ciphertext, decryptedtext, ciphertext_len, &decryptKey, iv, AES_DECRYPT);

    // 輸出解密後的明文
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
