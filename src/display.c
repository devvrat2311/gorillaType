#include "./display.h"
// #include "stopwatch.h"
#include <stdio.h>

void printModded(char *string, int width, int color) {
    int i = 0;
    int j = 1;
    switch(color) {
        case 0:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 1:
            printf(ANSI_COLOR_RED);
            break;
        case 2:
            printf(ANSI_COLOR_BLUE);
            break;
        case 3:
            printf(ANSI_COLOR_CYAN);
            break;
        case 4:
            printf(ANSI_COLOR_GREEN);
            break;
        case 5:
            printf(ANSI_COLOR_MAGENTA);
            break;
        default:
            printf(ANSI_COLOR_RESET);
    }
    while(string[i] != '\0') { //basic version, just to test things out
        if(i >= width*j && string[i] == ' ') {
            putchar('\n');
            ++j;
        }
        putchar(string[i++]);
    }
    printf(ANSI_COLOR_RESET);
}

void printBoth(char *testString, char *displayString, char *cursor) {
    for(int i = 0; testString[i] != '\0'; ++i) {
        // putchar(displayString[i]);
        if(&displayString[i] < cursor) {
            // printModded(testString, 40, 1);
            if(displayString[i] == testString[i]){
              printf(ANSI_COLOR_GREEN);
            } else {
              printf(ANSI_COLOR_RED);
            }
            putchar(displayString[i]);
            printf(ANSI_COLOR_RESET);
        } else {
            // printModded(displayString, 40, 2);
            printf(ANSI_COLOR_BLUE);
            putchar(testString[i]);
            printf(ANSI_COLOR_RESET);
        }
    }
}
