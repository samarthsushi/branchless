#include "branchless.h"

// check if a signed int x belongs in range [a,b]
// returns 1 if true, 0 if false
int check_in_range(int x, int a, int b) {
  // err is either -1 if a > b, or 0 if not
  // -1 indicates error
  int err = -(a > b);

  return (x - a >= 0) & (b - x >= 0) & ~err;
}

int absolute(int x) {
  int mask = x >> 31;
  return (x + mask) ^ mask;
}


// clamp values to a specified range
// if int x crosses bounds [a,b], they get clamped to the nearest bound
int clamp(int x, int a, int b) {
  return (x < a) * a + (x > b) * b + (x >= a && x <= b) * x;
}

int max(int a, int b) {
  return a ^ ((a ^ b) & -(a < b));
}

int min(int a, int b) {
  return b ^ ((a ^ b) & -(a < b));
}

int is_odd(int x) {
  return x & 1;
}

int is_power_of_two(int x) {
  return x > 0 && !(x & (x-1));
}
