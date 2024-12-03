#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flag(){
    char flag[] = {0x7d, 0x33, 0x6d, 0x30, 0x63, 0x6c, 0x33, 0x57, 0x7b, 0x67, 0x61, 0x6c, 0x66};
    for(int i=0;i < 20;i++){
        int randnum = rand() % 13;
        printf("%c", flag[randnum]);
    }
}

int main() {
    srand(time(NULL));
    printf("\033[31mWelcome to Break-All-CTF-Reverse!\n");
    printf("\033[36mIn this CTF game, you need to solve challenge with some basic Reverse skill.\n");
    printf("I hope that you will learn something after this game :)\n");
    printf("Flag format: flag{.*}\n");
    printf("\n");
    printf("\033[31mBelow is the categories of the challenges:\n");
    printf("\n");
    printf("\033[32mELF\n");
    printf("\033[36mQuite striaght forward, reverse ELF file.\n");
    printf("\n");
    printf("\033[32mGameHacking\n");
    printf("\033[36mUnity Game Rversing, genaral game hacking skill and something specific for unity games.\n");
    printf("\n");
    printf("\033[32mAndroid\n");
    printf("\033[36mFind out what a APK file does.\n");
    printf("\n");
    printf("\033[32mWindows\n");
    printf("\033[36mReverse, but on Windows.\n");
    printf("\n");
    printf("\033[32mPacker\n");
    printf("\033[36mMeet common packer and custom packer.\n");
    printf("\n");
    printf("\033[32mAnti-Debug\n");
    printf("\033[36mSome Basic Anti-Anti-Debug tech.\n");
    printf("\n");
    printf("\033[31mThat's it!, Good Luck and Happy Reversing!\n");
    printf("\n");
    printf("\033[0mHere is your flag: ");
    flag();
    return 0;
}