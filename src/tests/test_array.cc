#include "test_main.h"

TEST(array, constructor) {
  s21::array<int, 3> arr;
  std::array<int, 3> arr2;
  ASSERT_EQ(arr.size(), arr2.size());
}

TEST(array, constructor_init) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  for (size_t i = 0; i < arr.size(); ++i) {
    ASSERT_EQ(arr[i], arr2[i]);
  }
}

TEST(array, constructor_copy) {
  s21::array<int, 3> arr = {2, 1, 3};
  s21::array<int, 3> arr2(arr);
  for (size_t i = 0; i < arr.size(); ++i) {
    ASSERT_EQ(arr[i], arr2[i]);
  }
}

TEST(array, constructor_move) {
  s21::array<int, 3> arr = {2, 1, 3};
  s21::array<int, 3> arr2(std::move(arr));
  ASSERT_EQ(arr2[0], 2);
  ASSERT_EQ(arr2[1], 1);
  ASSERT_EQ(arr2[2], 3);
}

TEST(array, operator_assignment_move) {
  s21::array<int, 3> arr = {2, 1, 3};
  s21::array<int, 3> arr2 = {3, 2, 2};
  arr = std::move(arr2);
  ASSERT_EQ(arr[0], 3);
  ASSERT_EQ(arr[1], 2);
  ASSERT_EQ(arr[2], 2);
}
TEST(array, front) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  int num = arr.front();
  int num2 = arr2.front();
  ASSERT_EQ(num, num2);
}

TEST(array, back) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  int num = arr.back();
  int num2 = arr2.back();
  ASSERT_EQ(num, num2);
}

TEST(array, data) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  int* num = arr.data();
  int* num2 = arr2.data();
  ASSERT_EQ(*num, *num2);
}

TEST(array, Data_ValidArray) {
  s21::array<int, 5> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  ASSERT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  ASSERT_EQ(v[0], 10);
}

TEST(array, begin) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  s21::array<int, 3>::iterator it;
  std::array<int, 3>::iterator it2;
  it = arr.begin();
  it2 = arr2.begin();
  ASSERT_EQ(*it, *it2);
}

TEST(array, end) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr2 = {2, 1, 3};
  s21::array<int, 3>::iterator it;
  std::array<int, 3>::iterator it2;
  it = arr.end() - 1;
  it2 = arr2.end() - 1;
  ASSERT_EQ(*it, *it2);
}

TEST(array, empty) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr_orig = {2, 1, 3};
  ASSERT_FALSE(arr.empty());
  ASSERT_FALSE(arr_orig.empty());
  s21::array<int, 0> arr2;
  std::array<int, 0> arr2_orig;
  ASSERT_TRUE(arr2_orig.empty());
  ASSERT_TRUE(arr2.empty());
}

TEST(array, max_size) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr_orig = {2, 1, 3};
  ASSERT_EQ(arr.max_size(), arr_orig.max_size());
}

TEST(array, swap) {
  s21::array<int, 3> arr = {3, 2, 2};
  s21::array<int, 3> arr1 = {2, 1, 3};
  std::array<int, 3> arr_orig = {3, 2, 2};
  std::array<int, 3> arr1_orig = {2, 1, 3};
  arr.swap(arr1);
  arr_orig.swap(arr1_orig);
  for (size_t i = 0; i < arr.size(); i++) {
    ASSERT_EQ(arr[i], arr_orig[i]);
  }
  ASSERT_EQ(arr.size(), arr_orig.size());
}

TEST(array, fill) {
  s21::array<int, 3> arr = {3, 2, 2};
  std::array<int, 3> arr_orig = {3, 2, 2};
  arr.fill(1);
  arr_orig.fill(1);
  for (size_t i = 0; i < arr.size(); i++) {
    ASSERT_EQ(arr[i], arr_orig[i]);
  }
}

TEST(array, fill_2) {
  s21::array<int, 3> arr;
  std::array<int, 3> arr_orig;
  arr.fill(1);
  arr_orig.fill(1);
  for (size_t i = 0; i < arr.size(); i++) {
    ASSERT_EQ(arr[i], arr_orig[i]);
  }
}

TEST(array, at) {
  s21::array<int, 3> arr = {2, 1, 3};
  std::array<int, 3> arr_orig = {2, 1, 3};
  int r1 = arr.at(2);
  int r2 = arr_orig.at(2);
  ASSERT_EQ(r1, r2);
}

TEST(array, operator_access) {
  s21::array<int, 3> arr = {2, 1, 3};
  ASSERT_EQ(arr[0], 2);
}
