#include <stdio.h>
#include <string.h>

void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout); 
}

void flag_probably(){
    char enc[] = {0x32, 0x04, 0x10, 0x17, 0x52, 0x08, 0x14, 0x4f, 0x0f, 0x46, 0x0a, 0x18, 0x0f, 0x17, 0x41, 0x01, 0x03, 0x0f, 0x01, 0x4c, 0x15, 0x0b, 0x1e, 0x4d, 0x47, 0x1b, 0x1c, 0x1f, 0x4c, 0x0d, 0x0b, 0x52, 0x07, 0x0e, 0x01, 0x0a, 0x46, 0x18, 0x11, 0x01, 0x52, 0x12, 0x12, 0x1c, 0x1e, 0x0f, 0x0f, 0x10, 0x0b, 0x07, 0x12, 0x47, 0x09, 0x1b, 0x08, 0x0f, 0x0d, 0x0d, 0x1d, 0x0f};
    int enclen = sizeof(enc);
    char key[] = "flydragon";
    int keylen = strlen(key);

    for(int i=0;i < enclen;i++){
        key[i] = key[i % keylen];
        enc[i] = enc[i] ^ key[i];
        printf("%c", enc[i]);
    }
    printf("\n");
}

void sub_10C0(){
    char enc[] = {0x00, 0x00, 0x18, 0x03, 0x09, 0x31, 0x06, 0x1b, 0x0d, 0x0e, 0x53, 0x2b, 0x01, 0x04, 0x04, 0x15, 0x1c, 0x0b, 0x47, 0x11};
    int enclen = sizeof(enc);
    char key[enclen];
    strcpy(key, "flydragon");
    int keylen = strlen(key);

    for(int i=0;i < enclen;i++){
        key[i] = key[i % keylen];
        enc[i] = enc[i] ^ key[i];
        printf("%c", enc[i]);
    }
    printf("\n");
}


void draw_progress_bar(int progress, int total) {
    const int bar_width = 50;
    float percentage = (float)progress / total;
    int num_chars = percentage * bar_width;

    printf("Calculating Result [");
    for (int i = 0; i < bar_width; ++i) {
        if (i < num_chars) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\r", percentage * 100);
    fflush(stdout);
}

void miss(){
    printf("███╗   ███╗██╗███████╗███████╗\n");
    printf("████╗ ████║██║██╔════╝██╔════╝\n");
    printf("██╔████╔██║██║███████╗███████╗\n");
    printf("██║╚██╔╝██║██║╚════██║╚════██║\n");
    printf("██║ ╚═╝ ██║██║███████║███████║\n");
    printf("╚═╝     ╚═╝╚═╝╚══════╝╚══════╝\n");
    printf("Missed!! But did you win ?? \n");
    flag_probably();
}

void homerun(){
    printf("██╗  ██╗ ██████╗ ███╗   ███╗███████╗    ██████╗ ██╗   ██╗███╗   ██╗\n");
    printf("██║  ██║██╔═══██╗████╗ ████║██╔════╝    ██╔══██╗██║   ██║████╗  ██║\n");
    printf("███████║██║   ██║██╔████╔██║█████╗      ██████╔╝██║   ██║██╔██╗ ██║\n");
    printf("██╔══██║██║   ██║██║╚██╔╝██║██╔══╝      ██╔══██╗██║   ██║██║╚██╗██║\n");
    printf("██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗    ██║  ██║╚██████╔╝██║ ╚████║\n");
    printf("╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");
    printf("\n");
    printf("It's a homerun!! So u lose :( \n");
}

int main() {
    int is_ohtani = 1;
    char opponent[] = "Flydragon OwO";
    
    printf("===== Welcome to the baseball game! =====\n");
    if(is_ohtani)
        strcpy(opponent, "Ohtani Shohei");
    printf("You are the pitcher and your opponent is %s !\n", opponent);
    
    getchar();
    clear_screen();

    printf("========== Baseball Court ==========\n\n");
    printf("                 B▭\n");
    printf("                 /  \\\n");
    printf("                /    \\\n");
    printf("               /      \\\n");
    printf("              /   P    \\\n");
    printf("             ▬        ▬\n");
    printf("               ╲  ▬  ╱\n\n");
    printf("========== Baseball Court ==========\n\n");
    int choose = 0;
    printf("Please choose the pitch you want to throw\n");
    printf("(1) Fastball\n");
    printf("(2) Curveball\n");
    printf("(3) Slider\n");
    printf("(4) Changeup\n");
    scanf("%d", &choose);
    
    clear_screen();
    int total_steps = 1000000;
    for (int i = 0; i <= total_steps; ++i) {
        draw_progress_bar(i, total_steps);
    }
    clear_screen();

    if(strcmp(opponent, "Flydragon OuO") == 0 && choose == 0xdeadbeef)
        miss();
    else
        homerun();

    return 0;
}