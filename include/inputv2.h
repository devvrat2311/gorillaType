//this is to be preferred more than the original one for taking
//non canonical inputs

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int getch(void);//emulates the getch() function from the conio.h library in windows
int getche(void);//does the same, with echo
void setNonCanonicalMode(bool);

