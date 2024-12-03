#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char enc[] = {
0x98, 0xb4, 0x63, 0x64, 0xfc, 0xd8, 0x7f, 0x6a, 0xa9, 0xe5, 0x67, 0x62, 0xbf, 0x49, 0x68, 0x3e, 0xf0, 0xd0, 0x6f
};

bool verify(char *flag) {
    int enclen = strlen(flag);
    char key[enclen];
    strcpy(key, "flydragon");
    int keylen = strlen(key);
    char temp[enclen];

    if (flag[0] != 'f' || flag[1] != 'l' || flag[2] != 'a' || flag[3] != 'g' || flag[4] != '{' || flag[18] != '}')
    {
        return false;
    }
    
    for(int i=0;i < enclen;i++){
        key[i] = key[i % keylen];
        //flag[i] = flag[i] ^ key[i] & flag[(i+key[i]) % enclen] >> 2 ^ key[(i*flag[1])%keylen];
        temp[i] = (((flag[i]^i) << ((i^3) & 2)) | ((flag[i]^1) >> (i ^ 9) & 3));
        temp[i] = temp[i] & 0xff;
        if(temp[i] != enc[i]){
            return false;
        }
    }
    return true;
}

int main() {
    //char flag[] = "flag{symb0lic_f1le}";
    FILE *fp = fopen("flag.txt", "rb"); 
    if (fp == NULL) {
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = (char *)malloc(filesize);
    if (buffer == NULL) {
        fclose(fp);
        return 1;
    }

    size_t read_size = fread(buffer, 1, filesize, fp);
    if (read_size != filesize) {
        free(buffer);
        fclose(fp);
        return 1;
    }

    if(filesize != 19){
        printf("Wrong Size\n");
        free(buffer);
        fclose(fp);
        return 1;
    }
    
    if(verify(buffer)){
        printf("Correct\n");
        free(buffer);
        fclose(fp);
        return 0;
    }else{
        printf("Wrong\n");
        free(buffer);
        fclose(fp);
        return 1;
    }  
     
}
