#include "./input.h"
#include <fcntl.h>
#include <sys/select.h>

int getch(void) {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

int kbhit(void) {
  struct timeval tv;
  fd_set read_fds;

  tv.tv_sec = 0;
  tv.tv_usec = 0; // No waiting time

  FD_ZERO(&read_fds);
  FD_SET(STDIN_FILENO, &read_fds);

  // Select STDIN
  if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &tv) == -1) {
    return 0;
  }

  return FD_ISSET(STDIN_FILENO, &read_fds);
}

// int getch(void) {
//   struct termios oldattr, newattr;
//   int ch;
//   tcgetattr(STDIN_FILENO, &oldattr);
//   newattr = oldattr;
//   newattr.c_lflag &= ~(ICANON | ECHO);
//   newattr.c_cc[VMIN] = 0;
//   newattr.c_cc[VTIME] = 0;
//   tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//   ch = getchar();
//   tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//   return ch;
// }

int getche(void) {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

void setNonCanonicalMode(bool enable) {
  static struct termios oldt;
  struct termios newt;
  if (enable) {
    tcgetattr(STDIN_FILENO, &oldt); // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // apply new settings
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // make getchar non-blocking
  } else {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
  }
}
