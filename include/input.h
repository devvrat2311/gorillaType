#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

void enableRawMode();/*enables the terminal to disable
canonical mode and echo making it responsive to each
keystroke*/

int kbhit(void);/*checkes if a key has been pressed*/