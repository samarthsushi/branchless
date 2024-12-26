#include <stdio.h>
#include "branchless.h"

int failed_tests = 0;
int passed_tests = 0;

void assert_eq(const char* test_name, int result, int expected) {
  if(result != expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  } else {
    printf("test passed: %s\n", test_name);
    passed_tests++;
  }
}

void assert_neq(const char* test_name, int result, int expected) {
  if(result == expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  } else {
    printf("test passed: %s\n", test_name);
    passed_tests++;
  }
} 

void test_check_in_range() {
  printf("testing check_in_range:\n");
  assert_eq("check_in_range(5,3,10)", check_in_range(5,3,10), 1);
  assert_eq("check_in_range(15,10,5)", check_in_range(15,10,5), 0);
  assert_eq("check_in_range(-5,-10,-1)", check_in_range(-5,-10,-1), 1);
  assert_eq("check_in_range(7,7,7)", check_in_range(7,7,7), 1);
}

void test_clamp() {
  printf("testing clamp:\n");
  assert_eq("clamp(276, 0, 255)", clamp(276,0,255), 255);
  assert_eq("clamp(276, 0, 255)", clamp(-2,0,255), 0);
  assert_eq("clamp(276, 0, 255)", clamp(50,0,255), 50);
}

int main(int argc, char *argv[]) {
  test_check_in_range();
  test_clamp();

  printf("\n%d test(s) failed.\n%d test(s) passed.", failed_tests, passed_tests);

  return 0;
}
