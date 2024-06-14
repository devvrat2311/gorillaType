// #include "./include/gorilla.h"
#include "./include/inputv2.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ESCAPE_KEY '\x1b'
#define MAXLINE 1000

// Macros for the state variable, which conveys the state the program is in
#define MENU 0
#define TYPING 1
#define RESULT 2

// functions and variables
void display();
int handleTyping(char, char **); // returns the current length of the string that user is typing
int characterControl(char);
int matchStrings(char *s1, char *s2, int position);
void resetString(char *string);
void printFace();
int state = 0;
bool startedTyping = false;
char testString[MAXLINE] = "the quick brown fox jumps over the lazy dog|";
char displayString[MAXLINE];

int main() {
  system("clear");
  display();

  char ch;

  char *p = &displayString[0]; // to be noted here that p is still just a
                               // character pointer but the way we
  // pass it in handletyping function is by pointer to a pointer

  // MAIN LOOP
  while ((ch = getch()) != ESCAPE_KEY) {
    if (state == 0) {
      if (ch == '\n') {
        state = 1;
      }
    } else if (state == 1) {
      int position = handleTyping(ch, &p);
      if (matchStrings(testString, displayString, position)) {
        state = 2;
      }
    } else if (state == 2) {
      startedTyping = false;
      resetString(displayString);
      p = &displayString[0];
      if (ch == '\n')
        state = 0;
    }
    display();
  }

  return 0;
}

void display() {
  system("clear");
  printf("press Escape to quit the program\n");
  int len = strlen(testString);
  if (state == 0) {
    printFace();
    printf(ANSI_COLOR_YELLOW "\n\t\t\tWELCOME TO GORILLA TYPE\n\n\t\t\tPress "
                             "enter to start the test\n" ANSI_COLOR_RESET);
  } else if (state == 1) {
    printf(ANSI_COLOR_RED "\n\n \t\t\t%.*s\n" ANSI_COLOR_RESET, len - 1,
           testString);
    printf(ANSI_COLOR_CYAN "\n\n \t\t\t%s\n" ANSI_COLOR_RESET, displayString);

    if (!startedTyping)
      printf(ANSI_COLOR_GREEN
             "\n\n\t\t\tPress any key(alphabet or spacebar) to start typing\n");

  } else if (state == 2) {
    printf(ANSI_COLOR_RED "\n\n \t\t\t%.*s\n" ANSI_COLOR_RESET, len - 1,
           testString);
    printf(ANSI_COLOR_CYAN "\n\n \t\t\t%.*s\n" ANSI_COLOR_RESET, len - 1,
           displayString);
    printf(ANSI_COLOR_GREEN "\nSuccess!\nPress enter to go back to main "
                            "screen\nAnalysis:\n" ANSI_COLOR_RESET);
  }
  printf("\n\n\n");
}

int characterControl(char ch) {
  if (isalpha(ch) || ch == ' ' || ch == '\b' || ch == 127)
    return 1;
  else
    return 0;
}

int handleTyping(
    char ch, char **p) { // in this function p is a pointer to the pointer which
                         // points to the carets position in the string

  startedTyping = true;
  if (characterControl(ch)) {
    if (ch == '\b' || ch == 127) { // to handle backspace i.e. to delete the
                                   // most recent char from displayString
      // displayString[--i] = ' ';
      if (*p != &displayString[0]) {
        **p = ' ';
        --(*p);
        **p = '|';
      }
    } else {
      // displayString[i++] = ch;
      **p = ch;
      (*p)++;
      **p = '|';
    }
  }

  return (*p - &displayString[0]);
}

void resetString(char *string) {
  int i = 0;
  while (string[i] != '\0') {
    string[i++] = ' ';
  }
}

int matchStrings(char *s1, char *s2, int position) {
  // char s3[position];
  // strcpy(s3, s2);
  return (strcmp(s1, s2) == 0);
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
