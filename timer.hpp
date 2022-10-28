#ifndef TIMER_HPP
#define TIMER_HPP

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: Timer.hpp
 *   Assignment number: Project 3
 *
 *   Other comments regarding the file - simple timer class, provided by TA.
 *
 ***************************************************************/

class Timer {
  private:
    double timeStart;
    double timeStop;

  public:
    static double now ();

    double start ();
    double stop ();
    double elapsed ();
};

#endif
