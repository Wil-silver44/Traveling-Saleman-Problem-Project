#ifndef TIMER_HPP
#define TIMER_HPP

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