#include "test_main.h"

TEST(multiset, init) {
  s21::multiset<int> test = {52, 52, 45, 48, 53};
  std::multiset<int> test2 = {52, 52, 45, 48, 53};
  std::multiset<int>::iterator it;
  s21::multiset<int>::iterator it2 = test.begin();
  for (it = test2.begin(); it != test2.end(); it++) {
    ASSERT_EQ(*it, *it2);
    it2++;
  }
}

TEST(multiset, lower) {
  s21::multiset<int> test = {52, 54, 45, 48, 53};
  s21::multiset<int>::iterator it2;
  it2 = test.lower_bound(-2);
  std::multiset<int> test2 = {52, 54, 45, 48, 53};
  std::multiset<int>::iterator it3;
  it3 = test2.lower_bound(-2);
  EXPECT_EQ(*it2, *it3);
}

TEST(multiset, upper) {
  s21::multiset<int> test = {52, 54, 45, 48, 53};
  s21::multiset<int>::iterator it2;
  it2 = test.upper_bound(52);
  std::multiset<int> test2 = {52, 54, 45, 48, 53};
  std::multiset<int>::iterator it3;
  it3 = test2.upper_bound(52);
  EXPECT_EQ(*it2, *it3);
}

TEST(multiset, range) {
  s21::multiset<int> test = {52, 54, 45, 48, 53};
  std::multiset<int> test2 = {52, 54, 45, 48, 53};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> check =
      test.equal_range(2);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> check2 =
      test2.equal_range(2);
  EXPECT_EQ(*check.first, *check2.first);
  EXPECT_EQ(*check.second, *check2.second);
}