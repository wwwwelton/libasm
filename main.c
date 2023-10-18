#define CTEST_MAIN

// uncomment lines below to enable/disable features.
#define CTEST_SEGFAULT
// #define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "src/header.h"
#include "test/ctest.h"

int main(int argc, const char *argv[]) {
  int result = ctest_main(argc, argv);

  printf("\nNOTE: some tests will fail, just to show how ctest works! ;)\n");
  return result;
}
