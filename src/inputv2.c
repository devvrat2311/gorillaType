#include "../include/inputv2.h"
#include <fcntl.h>

int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

int getche(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

void setNonCanonicalMode(bool enable) {
    static struct termios oldt;
    struct termios newt;
    if(enable) {
        tcgetattr(STDIN_FILENO, &oldt); // save old settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new settings
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // make getchar non-blocking
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
    }
}
