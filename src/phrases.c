#include "phrases.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DICTIONARY_SIZE 10
#define MAX_WORD_LENGTH 20

char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH] = {
    "hello ",
    "world ",
    "programming ",
    "challenge ",
    "keyboard ",
    "typing ",
    "speed ",
    "accuracy ",
    "practice ",
    "test ",
};

char* getRandomWord() {
    int index = rand() % DICTIONARY_SIZE; //Random index
    return dictionary[index];
}

void newPhrase(char **testString) {
  size_t size = 1000 * sizeof(char);
  if(*testString != NULL) {
    free(*testString);
  }
  *testString = (char *)malloc(size);
  if(*testString == NULL) {
    printf("Memory Allocation Failed");
    return;
  }
  memset(*testString, 0, size);
  srand(time(NULL));
  for(int i = 0; i < 5; ++i) {
      strcat(*testString, getRandomWord());
  }
  // int n = strlen(*testString);
  // *testString = substr(*testString,0,strlen(*testString) - 1);
  // strcpy(*testString, "apple banana chair window clock elephant giraffe table ocean river mountain cloud music picture garden computer keyboard mouse screen bottle phone");
}
