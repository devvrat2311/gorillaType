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

void addRecord(const char *filename, Record record) {
  FILE *file = fopen(filename, "ab");
  if (!file) {
    perror("Failed to open database for writing");
    return;
  }
  fwrite(&record, sizeof(Record), 1, file);
  fclose(file);
}

void readDB(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("Failed to open database for reading");
    return;
  }
  Record record;
  while (fread(&record, sizeof(Record), 1, file)) {
    printf("ID: %d, Name: %s, Value: %.2f\n", record.id, record.name,
           record.avg);
  }
  fclose(file);
}

Record findRecordById(const char *filename, int id) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("Failed to open a databasr for reading");
    exit(EXIT_FAILURE);
  }
  Record record;
  while (fread(&record, sizeof(Record), 1, file)) {
    if (record.id == id) {
      fclose(file);
      return record;
    }
  }
  fclose(file);
  return (Record){0};
}
