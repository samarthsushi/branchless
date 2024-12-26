#include <stdio.h>
#include "branchless.h"

int failed_tests = 0;
int passed_tests = 0;

void assert_eq_util(const char* test_name, int result, int expected) {
  if(result != expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  } else {
    printf("test passed: %s\n", test_name);
    passed_tests++;
  }
}

#define assert_eq(expr, expected) assert_eq_util(#expr, (expr), (expected))

void assert_neq_util(const char* test_name, int result, int expected) {
  if(result == expected) {
    printf("test failed: %s (result: %d, expected: %d)\n", test_name, result, expected);
    failed_tests++;
  } else {
    printf("test passed: %s\n", test_name);
    passed_tests++;
  }
}

#define assert_neq(expr, expected) assert_neq_util(#expr, (expr), (expected))

void assert_util(const char* test_name, int expr) {
  if(expr) {
    printf("test failed: %s (expr: %d)\n", test_name, expr);
    failed_tests++;
  } else {
    printf("test passed: %s\n", test_name);
    passed_tests++;
  }
}

#define assert(expr) assert_util(#expr, (expr))

void test_check_in_range() {
  printf("testing check_in_range:\n");
  assert_eq(check_in_range(5,3,10), 1);
  assert_eq(check_in_range(15,10,5), 0);
  assert_eq(check_in_range(-5,-10,-1), 1);
  assert_eq(check_in_range(7,7,7), 1);
}

void test_clamp() {
  printf("testing clamp:\n");
  assert_eq(clamp(276,0,255), 255);
  assert_eq(clamp(-2,0,255), 0);
  assert_eq(clamp(50,0,255), 50);
}

void test_absolute() {
  printf("testing absolute:\n");
  assert_eq(absolute(-2), 2);
  assert_eq(absolute(2), 2);
}

void test_min() {
  printf("testing min:\n");
  assert_eq(min(2,3), 2);
  assert_eq(min(2,2), 2);
  assert_eq(min(-2,-5), -5);
  assert_eq(min(-2,2), -2);
}

void test_max() {
  printf("testing max:\n");
  assert_eq(max(2,3), 3);
  assert_eq(max(2,2), 2);
  assert_eq(max(-2,-5), -2);
  assert_eq(max(-2,2), 2);
}

void test_is_odd() {
  printf("testing is_odd:\n");
  assert_eq(is_odd(2), 0);
  assert_eq(is_odd(3), 1);
  assert_eq(is_odd(-2), 0);
  assert_eq(is_odd(-3), 1);
}

void test_is_power_of_two() {
  printf("testing is_power_of_two:\n");
  assert_eq(is_power_of_two(2), 1);
  assert_eq(is_power_of_two(1), 1);
  assert_eq(is_power_of_two(3), 0);
  assert_eq(is_power_of_two(-2), 0);
}

int main(int argc, char *argv[]) {
  test_check_in_range();
  test_clamp();
  test_absolute();
  test_min();
  test_max();
  test_is_odd();
  test_is_power_of_two();

  printf("\n%d test(s) failed.\n%d test(s) passed.", failed_tests, passed_tests);

  return 0;
}
