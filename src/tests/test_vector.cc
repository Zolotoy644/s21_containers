#include "test_main.h"

TEST(vector, check_init) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  for (size_t i = 0; i < vec1.size(); i++) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
}

TEST(vector, vector_n) {
  s21::vector<double> vec(3);
  std::vector<double> vec2(3);
  ASSERT_EQ(vec.size(), vec2.size());
}

TEST(vector, copy_constructors) {
  s21::vector<char> vec = {'a', 'b', 'c', 'd'};
  s21::vector<char> vec2(vec);
  for (size_t i = 0; i < vec.size(); ++i) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
}

TEST(vector, move_constructors) {
  s21::vector<char> vec = {'a', 'b', 'o', 'b', 'a'};
  s21::vector<char> vec2(std::move(vec));
  ASSERT_EQ(vec2[0], 'a');
  ASSERT_EQ(vec2[1], 'b');
  ASSERT_EQ(vec2[2], 'o');
  ASSERT_EQ(vec2[3], 'b');
  ASSERT_EQ(vec2[4], 'a');
}

TEST(vector, equal_operator) {
  s21::vector<int> vec = {2, 1, 3, 4};
  s21::vector<int> vec1 = {3, 2, 2, 2};
  vec = std::move(vec1);
  ASSERT_EQ(vec[0], 3);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 2);
  ASSERT_EQ(vec[3], 2);
}

TEST(vector, at) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  ASSERT_EQ(vec.at(3), vec1.at(3));
}

TEST(vector, at_throw) {
  try {
    s21::vector<int> vec = {2, 1, 3, 4};
    vec.at(4);
  } catch (std::exception &e) {
    ASSERT_STREQ(e.what(), "Number out of range container");
  }
}

TEST(vector, begin) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  std::vector<int>::iterator it1;
  s21::vector<int>::iterator it;
  it1 = vec1.begin();
  it = vec.begin();
  ASSERT_EQ(*it1, *it);
}

TEST(vector, end) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  std::vector<int>::iterator it1;
  s21::vector<int>::iterator it;
  it1 = vec1.end() - 1;
  it = vec.end() - 1;
  ASSERT_EQ(*it1, *it);
}

TEST(vector, push_back) {
  s21::vector<int> vec;
  std::vector<int> vec1;
  vec1.push_back(44);
  vec.push_back(44);
  ASSERT_EQ(vec1[0], vec[0]);
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(vec.capacity(), vec1.capacity());
}

TEST(vector, push_back2) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec1.push_back(44);
  vec.push_back(44);
  for (size_t i = 0; i < vec1.size(); i++) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(vec.capacity(), vec1.capacity());
}

TEST(vector, pop_back) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec1.push_back(44);
  vec.push_back(44);
  for (int i = 0; i < 4; i++) {
    vec1.pop_back();
    vec.pop_back();
  }
  for (size_t i = 0; i < vec1.size(); i++) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(vec.capacity(), vec1.capacity());
}

TEST(vector, pop_back2) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec1.push_back(44);
  vec.push_back(44);
  for (int i = 0; i < 5; i++) {
    vec1.pop_back();
    vec.pop_back();
  }
  std::vector<int>::iterator it1Beg;
  s21::vector<int>::iterator itBeg;
  std::vector<int>::iterator it1End;
  s21::vector<int>::iterator itEnd;
  it1Beg = vec1.begin();
  itBeg = vec.begin();
  it1End = vec1.end();
  itEnd = vec.end();
  ASSERT_EQ(*it1Beg, *itBeg);
  ASSERT_EQ(*it1End, *itEnd);
}

TEST(vector, pop_back3) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec1.push_back(44);
  vec.push_back(44);
  for (int i = 0; i < 4; i++) {
    vec1.pop_back();
    vec.pop_back();
  }
  vec1.push_back(44);
  vec.push_back(44);
  for (size_t i = 0; i < vec1.size(); i++) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
}

TEST(vector, empty) {
  s21::vector<int> vec;
  std::vector<int> vec1;

  ASSERT_TRUE(vec.empty());
  ASSERT_TRUE(vec1.empty());
}

TEST(vector, empty2) {
  s21::vector<int> vec = {2};
  std::vector<int> vec1 = {2};

  ASSERT_FALSE(vec.empty());
  ASSERT_FALSE(vec1.empty());
}

TEST(vector, shrint_to_fit) {
  s21::vector<int> vec = {2};
  std::vector<int> vec1 = {2};
  for (int i = 0; i < 2; i++) {
    vec1.push_back(44);
    vec.push_back(44);
  }
  vec1.shrink_to_fit();
  vec.shrink_to_fit();
  ASSERT_EQ(vec.capacity(), vec1.capacity());
}

TEST(vector, clear) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec.clear();
  vec1.clear();
  std::vector<int>::iterator it1;
  s21::vector<int>::iterator it;
  it1 = vec1.begin();
  it = vec.begin();
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(*it, *it1);
  it1 = vec1.end();
  it = vec.end();
  ASSERT_EQ(*it, *it1);
}

TEST(vector, clear2) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec.clear();
  vec1.clear();
  int *it1;
  int *it;
  it1 = vec1.data();
  it = vec.data();
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(*it, *it1);
}

TEST(vector, insert) {
  s21::vector<int> vec = {2, 1, 6};
  s21::vector<int>::iterator it;
  std::vector<int> vec2 = {2, 1, 6};
  std::vector<int>::iterator it2;
  it = vec.begin() + 1;
  it = vec.insert(it, 0);
  it2 = vec2.begin() + 1;
  it2 = vec2.insert(it2, 0);
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
  ASSERT_EQ(*it, *it2);
}

TEST(vector, insert2) {
  s21::vector<int> vec = {2, 1, 0, 4, 5};
  s21::vector<int>::iterator it;
  std::vector<int> vec2 = {2, 1, 0, 4, 5};
  std::vector<int>::iterator it2;
  it = vec.begin() + 2;
  it = vec.insert(it, 0);
  it2 = vec2.begin() + 2;
  it2 = vec2.insert(it2, 0);
  ASSERT_EQ(*it, *it2);
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
}

TEST(vector, insert3) {
  s21::vector<int> vec = {2, 1, 0, 4, 5};
  s21::vector<int>::iterator it;
  it = vec.begin() - 2;
  try {
    it = vec.insert(it, 0);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Pointer located behind border vector");
  }
}

TEST(vector, insert4) {
  s21::vector<int> vec = {2, 1, 6};
  s21::vector<int>::iterator it;
  std::vector<int> vec2 = {2, 1, 6};
  std::vector<int>::iterator it2;
  it = vec.begin() + 1;
  it = vec.insert(it, 0);
  it2 = vec2.begin() + 1;
  it2 = vec2.insert(it2, 0);
  ASSERT_EQ(*it, *it2);
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
  ASSERT_EQ(vec.size(), vec2.size());
  ASSERT_EQ(vec.capacity(), vec2.capacity());
}

TEST(vector, insert5) {
  s21::vector<int> vec = {2, 1, 6};
  s21::vector<int>::iterator it;
  std::vector<int> vec2 = {2, 1, 6};
  std::vector<int>::iterator it2;
  it = vec.begin();
  it = vec.insert(it, 0);
  it2 = vec2.begin();
  it2 = vec2.insert(it2, 0);
  ASSERT_EQ(*it, *it2);
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
  ASSERT_EQ(vec.size(), vec2.size());
  ASSERT_EQ(vec.capacity(), vec2.capacity());
}

TEST(vector, swap) {
  s21::vector<int> vec = {2, 1, 3, 4};
  s21::vector<int> vec1 = {2, 1, 3};
  std::vector<int> vec_orig = {2, 1, 3, 4};
  std::vector<int> vec1_orig = {2, 1, 3};
  vec.swap(vec1);
  vec_orig.swap(vec1_orig);
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], vec_orig[i]);
  }
  ASSERT_EQ(vec.size(), vec_orig.size());
  ASSERT_EQ(vec.capacity(), vec_orig.capacity());
}

TEST(vector, front) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  int num = vec.front();
  int num1 = vec1.front();
  ASSERT_EQ(num, num1);
}

TEST(vector, back) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  int num = vec.back();
  int num1 = vec1.back();
  ASSERT_EQ(num, num1);
}

TEST(vector, reserve) {
  s21::vector<int> vec = {2, 1, 3, 4};
  std::vector<int> vec1 = {2, 1, 3, 4};
  vec.reserve(6);
  vec1.reserve(6);
  for (size_t i = 0; i < vec1.size(); ++i) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
  ASSERT_EQ(vec.size(), vec1.size());
  ASSERT_EQ(vec.capacity(), vec1.capacity());
}

TEST(vector, erase) {
  s21::vector<int> vec = {2, 1, 6};
  std::vector<int> vec1 = {2, 1, 6};
  std::vector<int>::iterator it1;
  s21::vector<int>::iterator it;
  it = vec.begin() + 1;
  it1 = vec1.begin() + 1;
  it = vec.erase(it);
  it1 = vec1.erase(it1);
  ASSERT_EQ(*it, *it1);
  for (size_t i = 0; i < vec.size(); ++i) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
}

TEST(vector, erase2) {
  s21::vector<int> vec = {2, 1, 6, 3};
  std::vector<int> vec1 = {2, 1, 6, 3};
  std::vector<int>::iterator it1;
  s21::vector<int>::iterator it;
  it = vec.begin() + 2;
  it1 = vec1.begin() + 2;
  it = vec.erase(it);
  it1 = vec1.erase(it1);
  ASSERT_EQ(*it, *it1);
  for (size_t i = 0; i < vec.size(); ++i) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
}

TEST(vector, erase3) {
  s21::vector<int> vec = {2, 1, 6};
  std::vector<int> vec1 = {2, 1, 6};
  // std::vector<int>::iterator it1;
  // s21::vector<int>::iterator it;
  auto it = vec.end() - 1;
  auto it1 = vec1.end() - 1;
  it = vec.erase(it);
  it1 = vec1.erase(it1);
  ASSERT_EQ(*it, *it1);
  for (size_t i = 0; i < vec1.size(); ++i) {
    ASSERT_EQ(vec[i], vec1[i]);
  }
}

TEST(vector, erase4) {
  s21::vector<int> vec = {2, 1, 0, 4, 5};
  s21::vector<int>::iterator it;
  it = vec.begin() + 5;
  try {
    it = vec.erase(it);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Pointer located behind border vector");
  }
}

TEST(vector, Data_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int *dataPtr = v.data();
  ASSERT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  ASSERT_EQ(v[0], 10);
}
