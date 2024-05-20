#include "../include/gorilla.h"
#define TRUE 1
#define FALSE 0

int getlineCustom(char *line, int maxlen) {
  int i, c;

  for(i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if(c == '\n'){
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}

int getLineNoTrailingSpaces(char *line, int maxlen) {
  int i, c;
  int isSpace = FALSE; //state variable, i think
  
  i = 0;
  while(i < maxlen - 1 && (c =getchar()) != EOF && c != '\n') {
    //first you want to check the state we are currently in

    if(isSpace == TRUE) {
      if(c == ' ') {
        printf("1");//nothing to be done in this case
      }
      else{
        isSpace = FALSE;
        line[i++] = c;
        printf("2");
      }
    }
    else {
      printf("3");
      line[i++] = c;
      if(c == ' '){
        printf("4");
        isSpace = TRUE;
      }
    }
  }

  if(c == '\n') {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}


void copy(char *to, char *from) {
  int i = 0;

  while((to[i] = from[i]) != '\0') {
    ++i;
  }

  return; 
}

/*
 This function would be the entry point for todo list app
 The tasks at hand.
  1. Frontend, how the user would be able to interact with his todolist.
  2. Backend, other functions which would be called inside this one to handle the requests by the user to create, edit delete notes.
 */

void addTask() {
  
}


void todolist() {
  int isOn;
  isOn = TRUE;
  printf("%d", isOn);

  while(isOn) {
    char c; //event->only keystrokes possible as of yet
    switch(c = getchar()) {
      case 'q':
        isOn = FALSE;
        break;
      case 'a':
        printf("add task");//addTask function here
        break;
      default:
        break;
    }
  }
}


