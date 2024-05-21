#include "test_main.h"

TEST(s21_list_constructor, default_constructor) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  ASSERT_EQ(s21list.empty(), stdlist.empty());
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(s21_list_constructor, size_constructor) {
  s21::list<int> s21list(5);
  std::list<int> stdlist(5);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, init_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, init_char_constructor) {
  s21::list<char> s21list{'a', 'b', 'c'};
  std::list<char> stdlist{'a', 'b', 'c'};
  s21::list<char>::iterator s21it = s21list.begin();
  std::list<char>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, init_string_constructor) {
  s21::list<std::string> s21list{"just", "string", "constructor"};
  std::list<std::string> stdlist{"just", "string", "constructor"};
  s21::list<std::string>::iterator s21it = s21list.begin();
  std::list<std::string>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, copy_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2(s21list);
  std::list<int> stdlist2(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, move_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2(std::move(s21list));
  std::list<int> stdlist2(std::move(stdlist));
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_constructor, move_operator_constructor) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int> s21list2 = std::move(s21list);
  std::list<int> stdlist2 = std::move(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i <= s21list.size() + 1; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_front_back, front_back) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(s21_list_empty_clear, empty_clear) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(s21_list_push_pop, push) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_push_pop, pop) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21list.pop_back();
  stdlist.pop_back();
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
  s21list.pop_front();
  stdlist.pop_front();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(s21_list_sort, sort) {
  s21::list<double> s21lone{7.19};
  s21lone.sort();
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.sort();
  stdlist.sort();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_iterator, iterator) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  ASSERT_EQ(*s21list.end(), *stdlist.end());
  // ASSERT_FALSE(begin != begin1);
}

TEST(s21_list_function, insert) {
  s21::list<int> s21list{22, 55, 0, 87};
  std::list<int> stdlist{22, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.insert(s21it, 77);
  stdlist.insert(stdit, 77);
  s21it = s21list.end();
  stdit = stdlist.end();
  s21list.insert(s21it, 66);
  stdlist.insert(stdit, 66);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.insert(s21it, 1111);
  stdlist.insert(stdit, 1111);
  ASSERT_EQ(s21list.size(), stdlist.size());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, erase) {
  s21::list<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.erase(s21it);
  stdlist.erase(stdit);
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, swap) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.swap(s21list2);
  stdlist.swap(stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, unique) {
  s21::list<int> s21list{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  std::list<int> stdlist{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  s21list.unique();
  stdlist.unique();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, splice) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.splice(s21it, s21list2);
  stdlist.splice(stdit, stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(s21_list_function, reverse) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.reverse();
  stdlist.reverse();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(s21_list_function, merge) {
  s21::list<int> s21list{77, 55, 0, 87, 1111};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  stdlist.sort();
  s21list.sort();
  s21list.merge(s21list2);
  stdlist.merge(stdlist2);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size() + 2; i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(s21_bonus, insert_many) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{6, 7, 1, 2, 8, 9};
  s21::list<int>::iterator s21it = s21list.begin();
  ++s21it;
  ++s21it;
  s21list.insert_many(s21it, 1, 2, 8);
  s21::list<int>::iterator it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(s21_bonus, insert_many_front) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{1, 2, 8, 6, 7, 9};
  s21list.insert_many_front(1, 2, 8);
  s21::list<int>::iterator it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(s21_bonus, insert_many_back) {
  s21::list<int> s21list{6, 7, 9};
  s21::list<int> s21res_list{6, 7, 9, 1, 2, 8};
  s21list.insert_many_back(1, 2, 8);
  s21::list<int>::iterator it_i = s21list.begin();
  s21::list<int>::iterator it_j = s21res_list.begin();
  for (size_t i = 0; i <= s21list.size(); i++) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}