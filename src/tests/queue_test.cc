#include "test_main.h"

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> q1;
  std::queue<int> q2;
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
}

TEST(QueueTest, InitializerListConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  std::queue<int> q2;
  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(4);
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(q1);
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4(q3);
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QueueTest, MoveConstructor1) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(std::move(q1));
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4(std::move(q3));
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QueueTest, Push) {
  s21::queue<int> q;
  std::queue<int> std_q;

  q.push(1);
  std_q.push(1);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());

  q.push(2);
  std_q.push(2);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());

  q.push(3);
  std_q.push(3);
  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2;
  q2 = std::move(q1);
  std::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  std::queue<int> q4;
  q4 = std::move(q3);
  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(QueueTest, SwapTest) {
  s21::queue<int> q1{1, 2, 3};
  s21::queue<int> q2{4, 5, 6};
  s21::queue<int> q1_copy{q1};
  s21::queue<int> q2_copy{q2};

  q1.swap(q2);

  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.front(), 4);
  EXPECT_EQ(q1.back(), 6);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);

  q2.swap(q1);

  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.front(), 4);
  EXPECT_EQ(q2.back(), 6);
  EXPECT_EQ(q1.front(), 1);
  EXPECT_EQ(q1.back(), 3);
}

TEST(QueueTest, insert_many_back) {
  s21::queue<int> my_queue{6, 7, 9};
  s21::queue<int> res_queue{6, 7, 9, 1, 2, 8};
  my_queue.insert_many_back(1, 2, 8);
  for (size_t i = 0; i <= res_queue.size(); i++) {
    ASSERT_EQ(my_queue.back(), res_queue.back());
    my_queue.pop();
    res_queue.pop();
  }
}