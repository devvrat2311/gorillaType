#include "./db_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new database (empty file)
void createDB(const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    perror("Failed to create databse");
    return;
  }
  fclose(file);
}

void addUser(const char *filename, User record) {
  FILE *file = fopen(filename, "ab");
  if (!file) {
    perror("Failed to open database for writing");
    return;
  }
  fwrite(&record, sizeof(User), 1, file);
  fclose(file);
}

void readDB(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("Failed to open database for reading");
    return;
  }
  User user;
  while (fread(&user, sizeof(User), 1, file)) {
    printf("ID: %d, Name: %s\n", user.id, user.username);
  }
  fclose(file);
}

User findRecordById(const char *filename, int id) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("Failed to open a database for reading");
    exit(EXIT_FAILURE);
  }
  User user;
  while (fread(&user, sizeof(User), 1, file)) {
    if (user.id == id) {
      fclose(file);
      return user;
    }
  }
  fclose(file);
  return (User){0};
}
