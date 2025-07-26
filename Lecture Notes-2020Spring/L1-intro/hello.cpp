// =============  C++ Way =============
#include <iostream>

int hello_cpp() {
  std::cout << "Hello world" << std::endl;
  return 0;
}

// =============  C Way =============
#include "stdio.h"
#include "stdlib.h"
int hello_c() {
  printf("%s", "Hello world\n");
  return EXIT_SUCCESS;
}

// =============  Main Function =============

int main() {
  hello_cpp();
  hello_c();
  return 0;
}


