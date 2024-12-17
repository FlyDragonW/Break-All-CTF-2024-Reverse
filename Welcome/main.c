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
    printf("\033[36mIn this CTF game, you need to solve challenges with some basic Reverse skill.\n");
    printf("I hope that you will learn something after this game :)\n");
    printf("Flag format: flag{.*}\n");
    printf("\n");
    printf("\033[31mBelow are the categories of the challenges:\n");
    printf("\033[36mNote that the first challenge in each categories supposed to be very easy and can be solved without prior knowledge, highly recommend to check out every category!\n");
    printf("If you Break ALL challenge, feel free to contact me for a special prize! (only the first one)\n");
    printf("\n");
    printf("\033[32mELF\n");
    printf("\033[36mQuite straight forward, reverse ELF file.\n");
    printf("\n");
    printf("\033[32mUnity Game Hacking\n");
    printf("\033[36mGeneral game hacking skill and something specific for unity games.\n");
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
    printf("\033[31mThat's it! Good Luck and Happy Reversing!\n");
    printf("\n");
    printf("\033[0mHere is your flag: ");
    flag();
    return 0;
}
