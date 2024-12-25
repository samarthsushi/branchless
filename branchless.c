#include "branchless.h"

// check if a signed int belongs in range [a,b]
// returns 1 if true, 0 if false
int fn1(int n, int a, int b) {
  // err is either -1 if a > b, or 0 if not
  // -1 indicates error
  int err = -(a > b);

  return (n - a >= 0) & (b - n >= 0) & ~err;
}
