#include "./display.h"
#include "stopwatch.h"
// #include "stopwatch.h"
#include <stdio.h>
#include <string.h>

void printModded(char *string, int width, int color) {
  int i = 0;
  int j = 1;
  switch (color) {
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
  while (string[i] != '\0') { // basic version, just to test things out
    if (i >= width * j && string[i - 1] == ' ') {
      putchar('\n');
      ++j;
    }
    putchar(string[i++]);
  }
  printf(ANSI_COLOR_RESET);
}

void printBoth(char *testString, char *displayString, char *cursor, int width) {
  for (int i = 0, j = 1; testString[i] != '\0'; ++i) {
    if (testString[i - 1] == ' ' && i >= j * width) {
      putchar('\n');
      j++;
    }
    // putchar(displayString[i]);
    if (&displayString[i] <= cursor) {
      // printModded(testString, 40, 1);
      if (&displayString[i] == cursor) {
        printf(ANSI_COLOR_INVERT);
      }
      if (displayString[i] == ' ' || testString[i] == ' ') {
        if (displayString[i] == testString[i]) {
          printf(ANSI_COLOR_BLUE);
          putchar('_');
        } else {
          printf(ANSI_COLOR_RED);
          if (displayString[i] == ' ') {
            putchar(testString[i]);
          } else {
            putchar('_');
          }
        }
      } else {
        if (displayString[i] == testString[i]) {
          printf(ANSI_COLOR_BLUE);
          putchar(displayString[i]);
        } else {
          printf(ANSI_COLOR_RED);
          putchar(testString[i]);
        }
      }

      printf(ANSI_COLOR_RESET);
      // putchar('|');
    } else { // printModded(displayString, 40, 2);
      printf(ANSI_COLOR_CYAN);
      putchar(testString[i]);
      printf(ANSI_COLOR_RESET);
    }
  }
}
