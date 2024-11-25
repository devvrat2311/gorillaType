// #include "./include/gorilla.h"
#include "./input.h"
#include "./stopwatch.h"
#include "./phrases.h"
#include "./display.h"
// #include <ctime>
#include <bits/types/struct_timeval.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ESCAPE_KEY '\x1b'
#define MAXLINE 1000

// Macros for the state variable, which conveys the state the program is in
// #define MENU 0
// #define TYPING 1
// #define RESULT 2

enum { MENU, TYPING, RESULT };

// functions and variables
void displayMain(char*);
int handleTyping(char, char **);
int matchStrings(char *s1, char *s2);
void resetString(char *string);
char *subString(char *, int pos, int len);
void printFace();
int state = 0;
bool startedTyping = false;
char *testString;
char displayString[MAXLINE];
int time_seconds = 0;

int main() {

  struct StopWatch timer;
  reset(&timer);

  char *p = &displayString[0];//this pointer handles the typing for the entire main routine of this program
  newPhrase(&testString);
  testString = subString(testString, 0, strlen(testString) - 1);
  displayMain(p);
  // char *newTestString = subString(testString, 0, strlen(testString) - 1);
  // printf("\n%s\n", newTestString);
  char ch;

  //MAIN LOOP
  while (1) {
    ch = getch();
    time_seconds = getElapsedTime(&timer);
    if (state == MENU) {
      if (ch == '\n') {
        state = TYPING;
        play(&timer);
      }
    } else if (state == TYPING) {
      handleTyping(ch, &p);
      if (matchStrings(testString, displayString)) {
        state = RESULT;
        time_seconds = getElapsedTime(&timer);
        reset(&timer);
      }
    } else if (state == RESULT) {
      startedTyping = false;
      resetString(displayString);
      resetString(testString);
      newPhrase(&testString);
      testString = subString(testString, 0, strlen(testString) - 1);
      p = &displayString[0];
      if (ch == '\n')
        state = MENU;
    }
    if (ch == ESCAPE_KEY)
      break;
    displayMain(p);
  }
  free(testString);
  // free(newTestString);
  return 0;
}

void displayMain(char*cursor) {

  system("clear");

  printf("press Escape to quit the program\n");
  if (state == MENU) {
    printFace();
    printf(ANSI_COLOR_YELLOW "\n\t\t\tWELCOME TO GORILLA TYPE\n\n\t\t\tPress enter to start the test\n" ANSI_COLOR_RESET);
  } else if (state == TYPING) {

    // printf(ANSI_COLOR_RED "\n\n \t\t\t%s\n" ANSI_COLOR_RESET, testString);
    // printf(ANSI_COLOR_CYAN "\n\n \t\t\t%s\n" ANSI_COLOR_RESET, displayString);
    // printModded(testString, 40, 1);
    // putchar('\n');
    // printModded(displayString, 40, 2);
    // putchar('\n');
    printBoth(testString, displayString, cursor);

    if (!startedTyping)
        printModded("\n\n\t\t\tPress any key(alphabet or spacebar) to start typing\n", 40, 3);
        // printf(ANSI_COLOR_GREEN "\n\n\t\t\tPress any key(alphabet or spacebar) to start typing\n");

  } else if (state == RESULT) {
    printf(ANSI_COLOR_RED "\n\n \t\t\t%s\n" ANSI_COLOR_RESET, testString);
    printf(ANSI_COLOR_CYAN "\n\n \t\t\t%s\n" ANSI_COLOR_RESET, displayString);
    printf(ANSI_COLOR_GREEN "\nSuccess!\nPress enter to go back to main screen\nAnalysis:\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\t\t\ttime taken: %d seconds\n" ANSI_COLOR_RESET, time_seconds);
  }
  printf("\n\n\n");
}

int handleTyping( char ch, char **p) {

  startedTyping = true;

  if (isalpha(ch) || ch == ' ' || ch == '\b' || ch == 127) {
    if (ch == '\b' || ch == 127) {      //handle backspace
      if (*p != &displayString[0]) {
        **p = '\0';
        --(*p);
        **p = '|';
      }
    } else {
      **p = ch;
      (*p)++;
      **p = '|';
    }
  }

  return (*p - &displayString[0]);
}

char * subString(char *oldString, int pos, int len) {
  char *newString = (char *)malloc(len + 1);
  if(newString == NULL) {
    return NULL;
  }
  for(int i = 0; i < len; ++i) {
    newString[i] = oldString[pos + i];
  }
  //NULL terminate the new String
  newString[len] = '\0';

  return newString;
}

void resetString(char *string) {
  int i = 0;
  while (string[i] != '\0') {
    string[i++] = ' ';
  }
}

int matchStrings(char *s1, char *s2) {

  return (strcmp(s1, subString(s2,0,strlen(s2) - 1)) == 0);
}

void printFace() {
  // Print smiley face ASCII art
  printf(ANSI_COLOR_YELLOW "\t\t\t");
  printf("   _____\n\t\t\t");
  printf("  /     \\\n\t\t\t");
  printf(" | () () |\n\t\t\t");
  printf("  \\  ^  /\n\t\t\t");
  printf("   |---|\n\t\t\t");
  printf("   |||||\n\t\t\t");
  printf(ANSI_COLOR_RESET);
}
