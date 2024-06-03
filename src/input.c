#include "../include/input.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void enableRawMode() {
  struct termios term;

  //get current terminal settings
  tcgetattr(STDIN_FILENO, &term);

  //modify the settings to disable canonical mode and echo
  term.c_lflag &= ~(ICANON | ECHO);

  //apply the settings
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int kbhit(void) {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if ( ch != EOF ) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}