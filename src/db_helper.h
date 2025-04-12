#pragma once

typedef struct {
  int id;
  char username[50];
  char password[50];
} User;

void createDB(const char *filename);
void addUser(const char *filename, User user);
void readDB(const char *filename);
User findUserById(const char *filename, int id);
