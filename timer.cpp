#include <sys/time.h>

#include "timer.hpp"


double Timer::now () {
  struct timeval time;
  gettimeofday(&time, nullptr);

  double useconds = time.tv_usec;
  double mseconds = (useconds / 1000);
  double seconds = time.tv_sec + (mseconds / 1000);

  return seconds;
}


double Timer::start () {
  this->timeStart = Timer::now();

  return this->timeStart;
}

double Timer::stop () {
  this->timeStop = Timer::now();

  return this->timeStop;
}

double Timer::elapsed () {
  return (this->timeStop - this->timeStart);
}
