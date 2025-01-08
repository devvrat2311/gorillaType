#pragma once

typedef struct {
  int id;
  char name[50];
  float avg;
} Record;

void createDB(const char *filename);
void addRecord(const char *filename, Record record);
void readDB(const char *filename);
Record findRecordById(const char *filename, int id);
