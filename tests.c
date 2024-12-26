#include <stdio.h>
#include "branchless.h"

int failed_tests = 0;

void assert_eq(const char* test_name, int result, int expected) {
  if(result != expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  }
}

void assert_neq(const char* test_name, int result, int expected) {
  if(result == expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  }
} 

void test_check_in_range() {
  printf("testing fn1:\n");
  assert_eq("check_in_range(5,3,10)", check_in_range(5,3,10), 1);
  assert_eq("check_in_range(15,10,5)", check_in_range(15,10,5), 0);
  assert_eq("check_in_range(-5,-10,-1)", check_in_range(-5,-10,-1), 1);
  assert_eq("check_in_range(7,7,7)", check_in_range(7,7,7), 1);
}
int main(int argc, char *argv[]) {
  test_check_in_range();

  if(failed_tests > 0) {
    printf("\n%d test(s) failed.\n", failed_tests);
  } else {
    printf("\nall tests passed\n");
  }

  return 0;
}
