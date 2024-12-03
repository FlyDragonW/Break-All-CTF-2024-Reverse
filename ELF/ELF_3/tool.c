#include <stdio.h>
#include <string.h>

void flag(){
    char enc[] = "flag{symb0lic_f1le}";
    int enclen = strlen(enc);

    for(int i=0;i < enclen;i++){
        //enc[i] = enc[i] ^ key[i] & enc[(i+key[i]) % enclen] >> 2;
        enc[i] = (((enc[i]^i) << ((i^3) & 2)) | ((enc[i]^1) >> (i ^ 9) & 3));
        printf("0x%02x, ", enc[i] & 0xff);
    }
    printf("\n");
}

int main() {    
    flag();
    return 0;
}
