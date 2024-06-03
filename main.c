#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/gorilla.h"
#include "./include/inputv2.h"

#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define MAXLINE 1000

void display();
int handleTyping(char, char**);

char testString[MAXLINE] = "debabrata";
char displayString[MAXLINE];


int main() {

  system("clear");
  display();

  char ch;

  char *p = &displayString[0];
  while(ch != '\x1b'){
    ch = getch();
    system("clear");
    // printf("\n%d\n",handleTyping(ch, p));
    handleTyping(ch, &p);
    display();
  }
  return 0;
}

void display() {
  printf(ANSI_COLOR_RED"\nmain string:\n \t\t\t%s\n" ANSI_COLOR_RESET, testString);
  printf(ANSI_COLOR_CYAN "\ndisplay String:\n \t\t\t%s\n" ANSI_COLOR_RESET, displayString);
}

int characterControl(char ch) {
  if(isalpha(ch) || ch == ' ' || ch == '\b' || ch == 127)
    return 1;
  else
    return 0;
}

int handleTyping(char ch, char** p) {
  putchar('*');
  if(characterControl(ch)) {
    if(ch == '\b' || ch == 127) {//to handle backspace i.e. to delete the most recent char from displayString
      // displayString[--i] = ' ';
      if(*p != &displayString[0]){
        --(*p);
        **p = ' ';
      }
    }
    else {
      // displayString[i++] = ch;
      **p = ch; 
      (*p)++;
    }
  }

  // **p = '|';

  return (*p - &displayString[0]);
}