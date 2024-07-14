#include "./stopwatch.h"
#include <stdio.h>//inpoot outpoot
#include <unistd.h>//sleep function
#include <stdlib.h>//system commands

void play(struct StopWatch *sw) {
  if (!sw->running && !sw->isPaused) {
    clock_gettime(CLOCK_MONOTONIC, &sw->start_time);
    sw->running = true;
    sw->isPaused = false;
  } else if (!sw->running && sw->isPaused) {
    clock_gettime(CLOCK_MONOTONIC, &sw->leaked_time_end);
    sw->leakedTimeTotal +=
        ((sw->leaked_time_end.tv_sec + sw->leaked_time_end.tv_nsec / 1e9) -
         (sw->leaked_time_start.tv_sec + sw->leaked_time_start.tv_nsec / 1e9));
    sw->running = true;
    sw->isPaused = false;
  }
}

void stop(struct StopWatch *sw) {
  if (sw->running) {
    clock_gettime(CLOCK_MONOTONIC, &sw->end_time);
    clock_gettime(CLOCK_MONOTONIC, &sw->leaked_time_start);
    sw->isPaused = true;
    sw->running = false;
  } else {
    printf("\nERror\n");
    sleep(5);
  }
}

void reset(struct StopWatch *sw) {
  sw->running = false;
  sw->isPaused = false;
  sw->start_time.tv_sec = 0;
  sw->start_time.tv_nsec = 0;
  sw->end_time.tv_sec = 0;
  sw->end_time.tv_nsec = 0;
  sw->leaked_time_end.tv_sec = 0;
  sw->leaked_time_end.tv_nsec = 0;
  sw->leaked_time_start.tv_sec = 0;
  sw->leaked_time_start.tv_nsec = 0;
  sw->leakedTimeTotal = 0;
}

int getElapsedTime(struct StopWatch *sw) {
  struct timespec current_time;
  if (sw->running) {
    clock_gettime(CLOCK_MONOTONIC, &current_time);
  } else {
    current_time = sw->end_time;
  }

  double start_sec = sw->start_time.tv_sec + (sw->start_time.tv_nsec / 1e9);

  double end_sec;
  end_sec =
      current_time.tv_sec + (current_time.tv_nsec / 1e9) - sw->leakedTimeTotal;
  return end_sec - start_sec;
}

void display(struct StopWatch *sw) {
  printf("\t\tStopwatch\n");

  // declaring variables
  int seconds = 0, minutes = 0, hours = 0;
  struct timespec refresh_rate;
  refresh_rate.tv_sec = 0;
  refresh_rate.tv_nsec = 300000000L;

  int time = getElapsedTime(sw);

  // manage time logic
  seconds = time % 60;
  minutes = (time / 60) % 60;
  hours = time / 3600;

  // actual display code
  printf("\n\t\t%02d:%02d:%02d\n", hours, minutes, seconds);
  printf("\n\t\t%lf\n", sw->leakedTimeTotal);

  if (sw->running) {
    printf("play mode >");
  } else {
    printf("pause mode ||");
  }
  nanosleep(&refresh_rate, NULL);
  system("clear");
}