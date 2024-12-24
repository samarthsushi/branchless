#include <stdio.h>
#include <stdlib.h>

// check if a signed int belongs in range [a,b]
int fn1(int n, int a, int b) {
  // err is either -1 if a > b, or 0 if not
  // -1 indicates error
  int err = -(a > b);

  return (n - a >= 0) & (b - n >= 0) & ~err;
}

int main(int argc, char *argv[]) {
  printf("%d\n", fn1(5, 3, 10));
  printf("%d\n", fn1(15, 10, 5));
  printf("%d\n", fn1(-5, -10, -1));
  printf("%d\n", fn1(7, 7, 7));

  return 0;
}
