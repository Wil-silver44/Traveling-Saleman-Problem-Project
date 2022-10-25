#include <unistd.h>
#include <iostream>

#include "../timer.hpp"


int main () {
  Timer t;

  t.start();
  sleep(10);
  t.stop();

  std::cout << t.elapsed() << std::endl;


  return 0;
}
