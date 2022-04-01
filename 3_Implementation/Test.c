#include "unity.h"
#include"functions.h"
#define PROJECT_NAME "ATM"
void test_1(void);
void test_2(void);
void test_3(void);
void test_4(void);
void setUp(){}
void tearDown(){}
int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_1);
  RUN_TEST(test_2);
  RUN_TEST(test_3);
  RUN_TEST(test_4);
  return UNITY_END();
}
void test_1(void) {
  TEST_ASSERT_EQUAL(1,Menu()); 
}
void test_2(void) {
  TEST_ASSERT_EQUAL(15000.00,checkBalance(15000.00));
}
void test_3(void) {
  TEST_ASSERT_EQUAL(1,Exit());
}
void test_4(void) {
  TEST_ASSERT_EQUAL(1,invalid());

}

