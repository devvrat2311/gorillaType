#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <stdbool.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct StopWatch {
  struct timespec start_time;
  struct timespec end_time;
  struct timespec leaked_time_start;
  struct timespec leaked_time_end;
  double leakedTimeTotal;
  bool running;
  bool isPaused;
};

void play(struct StopWatch *sw);
void stop(struct StopWatch *sw);
void reset(struct StopWatch *sw);
double getElapsedTime(struct StopWatch *sw);
void display(struct StopWatch *sw);

#endif